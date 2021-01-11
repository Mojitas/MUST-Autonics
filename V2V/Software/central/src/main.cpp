/*
 * Notes to self:
 * 1. Never include libraries that add size to the program
 * 2. Find solutions that reduce code since 1 char = 1 byte and there is only 1 MB on the nRF52840_dk flash storage
 * 3. Lookup functions on datatypes if any exist and make use of them.
 */
#include <mbed.h>
#include <ble/BLE.h>
#include "user_config.h"

using namespace std::chrono;
using std::milli;
using namespace std::literals::chrono_literals;

/* configuration start */
DigitalOut _led1(LED1);
DigitalOut _led2(LED2);
DigitalOut _led3(LED3);
DigitalOut _led4(LED4);

events::EventQueue event_queue;

/*
 * Connectable and undirected advertising 
 * with minimum interval of 25 millisecond
 * and maximum interval of 50 milliseconds
 */
static const ble::AdvertisingParameters advparams(
		ble::advertising_type_t::CONNECTABLE_UNDIRECTED,
		ble::adv_interval_t(ble::millisecond_t(25)),
		ble::adv_interval_t(ble::millisecond_t(50))
);

static const ble::AdvertisingParameters extadvparams(
		ble::advertising_type_t::CONNECTABLE_UNDIRECTED,
		ble::adv_interval_t(600),
		ble::adv_interval_t(800)
);

static const std::chrono::milliseconds advertising_duration = 10000ms;

static const ble::ScanParameters scan_params(
		ble::phy_t::LE_CODED,
		ble::scan_interval_t(80),
		ble::scan_window_t(60),
		false
);

static const ble::scan_duration_t scan_duration(ble::millisecond_t(10000));
static const std::chrono::milliseconds delay = 3000ms;

/* config end */

class Receiver : private mbed::NonCopyable<Receiver>,
	public ble::Gap::EventHandler {
public:
	Receiver(BLE& ble, events::EventQueue& event_queue) :
		_ble(ble),
		_gap(ble.gap()),
		_event_queue(event_queue)
		{ }

	virtual ~Receiver()
	{
		if (BLE::Instance().hasInitialized())
			BLE::Instance().shutdown();
	}

	void run()
	{
		_gap.setEventHandler(this);
		error = _ble.init(this, &Receiver::on_init_complete);
		if (error) {
      print_error(error, "%s: %s\r\n", "Error returned by BLE::init");
		}

		_event_queue.dispatch_forever();
	}

private:
	void on_init_complete(BLE::InitializationCompleteCallbackContext *context)
	{
    error = context->error;
	  if (error) {
      print_error(error, "%s: %s\r\n", "Error during initialization");
	    return;
	  }
    
    if (_gap.isFeatureSupported(ble::controller_supported_features_t::LE_CODED_PHY)) {
      ble::phy_set_t phys(false, false, true);
      error = _gap.setPreferredPhys(&phys, &phys);
      if (error) {
        print_error(error, "%s: %s\r\n", "Gap::setPreferredPhys failed!");
      }
    } else {
      /* mbed automatically sets 1M as PHY for the BLE device */
    }

    _event_queue.call(this, &Receiver::advertise);
	}

  void advertise() {
    error = _gap.setAdvertisingParameters(ble::LEGACY_ADVERTISING_HANDLE, advparams);
    if (error) {
      print_error(error, "%s: %s\r\n", "Gap::setAdvertisingParameters failed!");
      return;
    }

    ble::AdvertisingDataSimpleBuilder<ble::LEGACY_ADVERTISING_MAX_SIZE> data_builder;
    data_builder.setFlags().setName(DEVICE_NAME);

    error = _gap.setAdvertisingPayload(ble::LEGACY_ADVERTISING_HANDLE, data_builder.getAdvertisingData());
    if (error) {
      print_error(error, "%s: %s\r\n", "Gap::setAdvertisingPayload failed!");
      return;
    }

    error = _gap.startAdvertising(ble::LEGACY_ADVERTISING_HANDLE);
    if (error) {
      print_error(error, "%s: %s\r\n", "Gap::startAdvertising failed!");
      return;
    }

    printf("\r\nAdvertising started! (type: 0x%x, interval: [%ld : %ld]ms)\r\n",
        advparams.getType(), advparams.getMinPrimaryInterval().valueInMs(),
        advparams.getMaxPrimaryInterval().valueInMs());

    if (_gap.isFeatureSupported(ble::controller_supported_features_t::LE_EXTENDED_ADVERTISING)) {
      error = _gap.createAdvertisingSet(&_ext_adv_handle, extadvparams);
      if (error) {
        print_error(error, "%s: %s\r\n", "Gap::createAdvertisingSet failed!");
        return;
      }

      error = _gap.setAdvertisingPayload(_ext_adv_handle, data_builder.getAdvertisingData());
      if (error) {
        print_error(error, "%s: %s\r\n", "Gap::setAdvertisingPayload failed!");
        return;
      }

      error = _gap.startAdvertising(_ext_adv_handle);
      if (error) {
        print_error(error, "%s: %s\r\n", "Gap::startAdvertising failed!");
        return;
      }

      printf("\r\nAdvertising started! (type: 0x%x, interval: [%ld : %ld]ms)\r\n",
          extadvparams.getType(), extadvparams.getMinPrimaryInterval().valueInMs(),
          extadvparams.getMaxPrimaryInterval().valueInMs());
    }

    _led_cancel_handles[1] = _event_queue.call_every(BLINK_RATE_2, [this]{ periodicCallbackB(); });
    _cancel_handle = _event_queue.call_in(advertising_duration, [this]{ end_advertising_mode(); });
  }

  void scan() {
    error = _gap.setScanParameters(scan_params);
    if (error) {
      print_error(error, "%s: %s\r\n", "Gap::setScanParameters failed!");
      return;
    }

    error = _gap.startScan(scan_duration);
    if (error) {
      print_error(error, "%s: %s\r\n", "Gap::startScan failed!");
      return;
    }

    printf("\r\nScanning started! (interval: %ldms, window: %ldms, timeout: %ldms)",
        scan_params.getCodedPhyConfiguration().getInterval().valueInMs(),
        scan_params.getCodedPhyConfiguration().getWindow().valueInMs(),
        scan_duration.valueInMs());
    _led_cancel_handles[0] = _event_queue.call_every(BLINK_RATE_1, [this]{ periodicCallbackA(); });
  }

private:
  /** Start implementation of BLE::Gap::EventHandler **/

  void onAdvertisingReport(const ble::AdvertisingReportEvent &event) override
  {
    // Print the Received Signal Strength Indication
    ble::rssi_t rssi = event.getRssi();
    printf("RSSI: %d", rssi);

    // If we're already connecting we can discard other advertisement reports
    if (_is_connecting)
      return;

    if (rssi < -65) { // Look at devices at close proximity only
      return;
    }

    // Get wether it is possible to connect to the device in the report
    // as well as the type of address and its adress. Also try to parse
    // the device name which should be equal to NAME_SENDER for the incoming
    // device when it is on the receiving end. 
    bool connectable = event.getType().connectable();
    bool is_peer_device = false;
    ble::peer_address_type_t type = event.getPeerAddressType();
    ble::address_t address = event.getPeerAddress();
    // Parse the incoming payload for discovery type and name
    ble::AdvertisingDataParser adv_parser(event.getPayload());
    while (adv_parser.hasNext()) {
      ble::AdvertisingDataParser::element_t field = adv_parser.next();

      if (field.type != ble::adv_data_type_t::FLAGS ||
          field.value.size() != 1 ||
          !ble::adv_data_flags_t(field.value[0]).getGeneralDiscoverable()) {
        continue;
      }

      if (field.type == ble::adv_data_type_t::COMPLETE_LOCAL_NAME) {
        const char *peer_name = reinterpret_cast<const char *>(field.value.data());
        if (strncmp(NAME_SENDER, peer_name, strlen(peer_name)) == 0) {
          is_peer_device = true;
        }
      }
    }

    if (!_bonded && connectable && is_peer_device) {
      // Connect to the device if the sender name is correct
      _event_queue.cancel(_cancel_handle);
      error = _gap.connect(type, address, ble::ConnectionParameters());
      if (error) {
        print_error(error, "%s: %s\r\n", "Gap::connect failed!");
        return;
      }
      
      _led_cancel_handles[2] = _event_queue.call_every(BLINK_RATE_3, [this]{ periodicCallbackC(); });
      _is_connecting = true;
    }
  }

  void onAdvertisingEnd(const ble::AdvertisingEndEvent &event) override
  {
    if (event.isConnected()) {
      printf("Stopped advertising due to a recently established connection!\r\n");
    }
  }

  void onAdvertisingStart(const ble::AdvertisingStartEvent &event) override
  {
    printf("Advertising set %d started\r\n", event.getAdvHandle());
  }

  void onScanTimeout(const ble::ScanTimeoutEvent&) override
  {
    printf("Stopped scanning due to timeout parameter!");
    _event_queue.call(this, &Receiver::end_scanning_mode);
  }

  void onConnectionComplete(const ble::ConnectionCompleteEvent &event) override
  {
    // Stop blinking LED3 and set is_connecting to false,
    // meaning that if it didn't disconnect it will try
    // again when it finds a device again.
    _event_queue.cancel(_led_cancel_handles[2]);
    _is_connecting = false;

    // Stop any ongoing advertisement. 
    if (_ext_adv_handle != ble::INVALID_ADVERTISING_HANDLE) {
      if (_gap.isAdvertisingActive(_ext_adv_handle)) {
        _gap.stopAdvertising(_ext_adv_handle);
      } else if (_gap.isAdvertisingActive(ble::LEGACY_ADVERTISING_HANDLE)){
        _gap.stopAdvertising(ble::LEGACY_ADVERTISING_HANDLE);
      }
    }

    /**
     * If it failes to connect, the error status
     * will be other then BLE_ERROR_NONE.
     */
    if (event.getStatus() != BLE_ERROR_NONE) {
      print_error(error, "%s: %s\r\n", "Failed to connect to device");
      return;
    }
    
    /**
     * This prints the address of the connected device,
     * and gives us a connection handle of type connection_handle_t.
     * It then turns on LED3 so it is lit up meaning that
     * the other device is successfully connected.
     */
    ble::address_t peer_addr = event.getPeerAddress();
    _handle = event.getConnectionHandle();
    _bonded = true;
    printf("Connected to device with address ");
    for (int i = 5; i >= 1; i--) {
      printf("%02x:", peer_addr[i]);
    }
    printf("%02x", peer_addr[0]);
    _led3 = !_led3;
  }

  /**
   * @brief When a device has disconnected this function is fired.
   * It gives the reason to why the device was disconnected
   * via the DisconnectionCompleteEvent event.
   * @param event The disconnection complete event which tells us the disconnection reason
   */
  void onDisconnectionComplete(const ble::DisconnectionCompleteEvent &event) override {
    printf("Diconnected from device\r\n");

    if (event.getReason() == ble::disconnection_reason_t::REMOTE_USER_TERMINATED_CONNECTION) {
      printf("Remote device terminated connection!\r\n");
    }

    if (_gap.isAdvertisingActive(ble::LEGACY_ADVERTISING_HANDLE) || _gap.isAdvertisingActive(_ext_adv_handle))
      _event_queue.call(this, &Receiver::end_advertising_mode);
    else
      _event_queue.call(this, &Receiver::end_scanning_mode);
  }

  /** End implementation of BLE::Gap::EventHandler **/
private:
  /*
   * Stops scanning and prevents LED1 from blinking.
   * It also starts the advertisement mode.
   **/
  void end_scanning_mode() {
    error = _gap.stopScan();
    if (error) {
      print_error(error, "%s: %s\r\n", "Gap::stopScan failed");
    }

    _event_queue.cancel(_led_cancel_handles[0]);
    _event_queue.call_in(delay, this, &Receiver::advertise); 
  }

  /*
   * Stops the current advertising both for LEGACY_ADVERTISING_HANDLE
   * and for our advertising handle which is extended advertising.
   * It also stops blinking LED2 and sends a signal to start scanning.
   */
  void end_advertising_mode() {
    _gap.stopAdvertising(ble::LEGACY_ADVERTISING_HANDLE);

    if (_ext_adv_handle != ble::INVALID_ADVERTISING_HANDLE) {
      if (_gap.isAdvertisingActive(_ext_adv_handle)) {
        error = _gap.stopAdvertising(_ext_adv_handle);
        if (error) {
          print_error(error, "%s: %s\r\n", "Gap::stopAdvertising failed");
        }
      }

      error = _gap.destroyAdvertisingSet(_ext_adv_handle);
      if (error) {
        print_error(error, "%s: %s\r\n", "Gap::destroyAdvertisingSet failed");
      }

      _ext_adv_handle = ble::INVALID_ADVERTISING_HANDLE;
    }

    _event_queue.cancel(_led_cancel_handles[1]);
    _event_queue.call_in(delay, [this]{ scan(); });
  }

  /*
   * Both periodicCallbackA, periodicCallbackB and
   * periodicCallbackC are functions for blinking the
   * leds on the nrf52840_dk
   */
  void periodicCallbackA(void) { 
    _led1 = !_led1;
  }

  void periodicCallbackB(void) {
    _led2 = !_led2;
  }
  
  void periodicCallbackC(void) {
    _led3 = !_led3;
  }
  
  /*
   * Translates the error from ble_error_t into a 
   * readable string that will be printed if there
   * is any error that occurrs. printf will be changed
   * to a file pointer before actual usage begins
   */
  void print_error(ble_error_t err, const char *format, const char *output)
  {
    printf(format, output, BLE::errorToString(err));
  }

private:
	BLE& _ble;
	ble::Gap& _gap;
	ble::connection_handle_t _handle = 0;
	bool _bonded = false;
	events::EventQueue& _event_queue;
	ble_error_t error;
	int _cancel_handle = 0;
  int _led_cancel_handles[3] = { 0 };
	ble::advertising_handle_t _ext_adv_handle = ble::INVALID_ADVERTISING_HANDLE;
  bool _is_connecting = false;
};

/*
 * Event scheduler for ble which processes BLE events by calling
 * processEvents. This makes it easier to handle all the events 
 * in the class above by just writing function names that comes
 * with the interfaces mbed ble class has to offer.
 */
void schedule_ble_events(BLE::OnEventsToProcessCallbackContext *context)
{
  event_queue.call([&ble_instance = context->ble] { ble_instance.processEvents(); });
}

/*
 * Gets the mac address from the device
 * and writes it to the storage in the solar
 * car.
 */
static void print_mac_address(Gap& gap)
{
	ble::own_address_type_t	addr_type;
	ble::address_t		address;
	gap.getAddress(addr_type, address);
	printf("Mac address of this device: ");
	for (int i = 5; i >= 1; i--) {
		printf("%02x:", address[i]);
	}
	printf("%02x\n", address[0]);
}

/*
 * Writes information to the storage in the solar car.
 * Information about its name, when it started, what
 * its mac address is and what the name of the other
 * device is which its looking for.
 */
static void print_information(Gap& gap)
{
	time_t timex = time(NULL);
  printf("Time: %ld", timex);
	printf("Solar Team External Communication");
  printf("Device Name: %s", DEVICE_NAME);
	print_mac_address(gap);
	printf("Looking for %s", NAME_SENDER);
}

int main()
{
	/*
	 * Detect and shutdown an already initialized stack
	 * and reset the state of the ble instance.
	 */
  BLE& _nrf52840 = BLE::Instance();
	
  /* Acquire a ble instance to use and print information such
	 * as mac address, name, name of sender and maybe some other
	 * instructions too if any buttons are used or so. */
	print_information(_nrf52840.gap());

	// Point to the event scheduler so that ble informs us of events
	_nrf52840.onEventsToProcess(schedule_ble_events);

	// Create an instance of the Receiver class and run it.
	Receiver receiver(_nrf52840, event_queue);
  receiver.run();
}
