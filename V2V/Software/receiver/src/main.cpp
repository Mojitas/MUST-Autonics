#include <events/mbed_events.h>
#include <mbed.h>
#include "ble/BLE.h"

#define BLINKING_RATE_1_MS        500ms
#define BLINKING_RATE_2_MS        250ms
#define BLINKING_RATE_3_MS        300ms
#define BLINKING_RATE_4_MS        400ms
#define PEER_DEVICE_NAME          "MUST_SENDER"
#define OWN_DEVICE_NAME           "MUST_RECEIVER"

#define ACTIVE_SCANNING         true  
#define SCAN_INTERVAL           ble::scan_interval_t(500)
#define SCAN_WINDOW             ble::scan_window_t(250)

static EventQueue event_queue(16 * EVENTS_EVENT_SIZE);

class BLEScanner : ble::Gap::EventHandler {

  public:
    // constructor
    BLEScanner(BLE &ble, events::EventQueue &event_queue) :
        _ble(ble),
        _gap(ble.gap()),
        _event_queue(event_queue),
        _led1(LED1, 1),
        _led2(LED2, 1),
        _led3(LED3, 1),
        _led4(LED4, 1) 
    { }

    // destructor
    virtual ~BLEScanner() 
    {
      if (_ble.hasInitialized())
        _ble.shutdown();
    }

    void scan() {
        _ble.gap().setEventHandler(this);
        _ble.init(this, &BLEScanner::on_init_complete);
        _event_queue.dispatch_forever();
    }
  
  private:
    BLE &_ble;
    Gap &_gap;
    events::EventQueue &_event_queue;
    DigitalOut _led1, _led2, _led3, _led4;
    ble_error_t error;
    int cancel_handles[4] = { 0 };
    bool is_connecting = false, is_syncing = false, is_connected = false;
    ble::periodic_sync_handle_t _sync_handle;

    /** Callback triggered when the ble initialization process has finished */
    void on_init_complete(BLE::InitializationCompleteCallbackContext *params) {
      error = params->error;

      if (error) {
        printf("%lld: %s - init failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      if (_gap.isFeatureSupported(ble::controller_supported_features_t::LE_CODED_PHY))
      {
        ble::phy_set_t phySet(ble::phy_t::LE_CODED);
        error = _gap.setPreferredPhys(&phySet, &phySet);
        
        if (error)
        {
          printf("%lld: %s - setPreferredPhys failed!\r\n", time(NULL), BLE::errorToString(error));
        } else
        {
          printf("%lld: setPreferredPhys succeeded!\r\n", time(NULL));
        }
      }
      
      cancel_handles[0] = _event_queue.call_every(BLINKING_RATE_1_MS, this, &BLEScanner::blink, 1);
      _event_queue.call(this, &BLEScanner::start_scan);
    }

    void start_scan()
    {
      ble::ScanParameters scan_params;
      scan_params.setOwnAddressType(ble::own_address_type_t::RANDOM);
      scan_params.setCodedPhyConfiguration(SCAN_INTERVAL, SCAN_WINDOW, ACTIVE_SCANNING);

      error = _gap.setScanParameters(scan_params);
      if (error)
      {
        printf("%lld: setScanParams failed!\r\n", time(NULL));
        return;
      }

      error = _gap.startScan();
      if (error)
      {
        printf("%lld: startScan failed!\r\n", time(NULL));
        return;
      }
    }

    // Blink the alive LED
    void blink(int x) {
      switch (x)
      {
        case 1:
          _led1 = !_led1;
          break;
        case 2:
          _led2 = !_led2;
          break;
        case 3:
          _led3 = !_led3;
          break;
        case 4:
          _led4 = !_led4;
          break;
        default:
          _led1 = !_led1;
          break;
      }
    }

    void onAdvertisingReport(const ble::AdvertisingReportEvent &event) 
    {
      if (is_connecting) 
      {
        return;
      }

      ble::rssi_t rssi = event.getRssi();
      //if (-60 > rssi)
      //  return;

      ble::address_t address = event.getPeerAddress();
      ble::peer_address_type_t type = event.getPeerAddressType();
      bool is_connectable = event.getType().connectable();
 
      printf("%lld: RSSI: %d, Address: %02x:%02x:%02x:%02x:%02x:%02x, Type: %d, Connectable: %d\r\n", time(NULL), rssi, address[5], address[4], address[3], address[2], address[1], address[0], type.value(), is_connectable);

      ble::AdvertisingDataParser dataParser(event.getPayload());
      while (dataParser.hasNext())
      {
        ble::AdvertisingDataParser::element_t field = dataParser.next();

        if (field.type == ble::adv_data_type_t::COMPLETE_LOCAL_NAME &&
            field.value.size() == strlen(PEER_DEVICE_NAME) &&
            (memcmp(field.value.data(), PEER_DEVICE_NAME, field.value.size()) == 0))
        {
          printf("%lld: Peer device found! Connecting...\r\n", time(NULL));
          error = _gap.connect(type, address, ble::ConnectionParameters());
          if (error)
          {
            printf("%lld: %s - connect failed!\r\n", time(NULL), BLE::errorToString(error));
            return;
          }
          else
          {
            _event_queue.cancel(cancel_handles[0]);
            cancel_handles[2] = _event_queue.call_every(BLINKING_RATE_3_MS, this, &BLEScanner::blink, 3);
            is_connecting = true;
          }
        }
      }
    }

    void onConnectionComplete(const ble::ConnectionCompleteEvent &event)
    {
      error = event.getStatus();
      if (error)
      {
        printf("%lld: %s - Failed to connect!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      is_connected = true;
      printf("%lld: Connection successful, changing symbols per bit to 8.\r\n", time(NULL));
      ble::connection_handle_t handle = event.getConnectionHandle();
      ble::coded_symbol_per_bit_t symbols(ble::coded_symbol_per_bit_t::S8);
      ble::phy_set_t phySet(ble::phy_t::LE_CODED);
      error = _gap.setPhy(handle, &phySet, &phySet, symbols);
      if (error)
      {
        printf("%lld: %s - setPhy for connection failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      printf("%lld: Changed to 8 symbols per bit, meaning 125kbit/s transfer speed.\r\n", time(NULL));
      printf("%lld: My role in this connection is CENTRAL\r\n", time(NULL));
      printf("%lld: I will synchronize with periodic advertising\r\n", time(NULL));
      
      error = _gap.createSync(5, ble::sync_timeout_t(ble::millisecond_t(500)));
      if (error)
      {
        printf("%lld: %s - createSync failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      printf("%lld: Created sync with the other device!\r\n", time(NULL));
      _event_queue.cancel(cancel_handles[2]);
      blink(3);
    }

    void onPeriodicAdvertisingSyncEstablished(const ble::PeriodicAdvertisingSyncEstablishedEvent &event)
    {
      error = event.getStatus();
      if (error)
      {
        printf("%lld: %s - Failed to establish sync\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      printf("%lld: Sync established!\r\n", time(NULL));
      _sync_handle = event.getSyncHandle();
      error = _gap.addDeviceToPeriodicAdvertiserList(event.getPeerAddressType(), event.getPeerAddress(), event.getSid());
      if (error)
      {
        printf("%lld: %s - Failed to add to periodic advertiser list!\r\n", time(NULL), BLE::errorToString(error));
      }
    }

    void onPeriodicAdvertisingReport(const ble::PeriodicAdvertisingReportEvent &event)
    {
      ble::rssi_t rssi = event.getRssi();
      printf("%lld: RSSI value: %d dBm, ", time(NULL), rssi);

      ble::AdvertisingDataParser dataParser(event.getPayload());
      while (dataParser.hasNext())
      {
        ble::AdvertisingDataParser::element_t field = dataParser.next();

        if (field.type == ble::adv_data_type_t::SERVICE_DATA) 
        {
          if (*((uint16_t *)field.value.data()) == GattService::UUID_BATTERY_SERVICE)
          {
            const uint8_t *level = field.value.data() + sizeof(uint16_t);
            printf("Battery level => %d\r\n", *level);
          }
        }
      }
    }

    void onScanTimeout(const ble::ScanTimeoutEvent&)
    {
      if (is_connecting || is_connected || is_syncing)
      {
        printf("%lld: Scanning stopped because we are either connecting, connected or syncing.\r\n", time(NULL));
      }
    }
};

void schedule_ble_events(BLE::OnEventsToProcessCallbackContext *context) {
    event_queue.call(Callback<void()>(&context->ble, &BLE::processEvents));
}

int main()
{   
    printf("%lld: Creating instance of ble\r\n", time(NULL));
    BLE &ble = BLE::Instance();

    printf("%lld: Attaching callback to event queue\r\n", time(NULL));
    ble.onEventsToProcess(schedule_ble_events);

    printf("%lld: Creating instance of scanner\r\n", time(NULL));
    BLEScanner scanner(ble, event_queue);

    printf("%lld: Running...\r\n", time(NULL));
    scanner.scan();
    return 0;
}
