#include <events/mbed_events.h>
#include <mbed.h>
#include "ble/BLE.h"

#define BLINKING_RATE_1_MS        500ms
#define BLINKING_RATE_2_MS        250ms
#define BLINKING_RATE_3_MS        300ms
#define BLINKING_RATE_4_MS        400ms
#define OWN_DEVICE_NAME           "MUST_SENDER"
#define PEER_DEVICE_NAME          "MUST_RECEIVER"
#define MAX_PAYLOAD_SIZE          50

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
        _led4(LED4, 1),
        _databuilder(adv_buffer)
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
    bool is_syncing = false, is_connected = false;
    ble::advertising_handle_t _handle = ble::INVALID_ADVERTISING_HANDLE;
    uint8_t adv_buffer[MAX_PAYLOAD_SIZE] = { 0 };
    ble::AdvertisingDataBuilder _databuilder;
    uint8_t battery_level = 100;

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
      
      cancel_handles[0] = _event_queue.call_every(BLINKING_RATE_2_MS, this, &BLEScanner::blink, 2);
      _event_queue.call(this, &BLEScanner::start_advertising);
    }

    void start_advertising()
    {
      // Start advertising here
      ble::AdvertisingParameters adv_parameters(
          ble::advertising_type_t::CONNECTABLE_NON_SCANNABLE_UNDIRECTED,
          ble::adv_interval_t(ble::millisecond_t(100))
          );

      adv_parameters.setUseLegacyPDU(false);

      error = _gap.createAdvertisingSet(&_handle, adv_parameters);
      if (error)
      {
        printf("%lld: %s - createAdvertisingSet failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      printf("%lld: createAdvertisingSet succeeded!\r\n", time(NULL));
      _databuilder.setFlags();
      _databuilder.setName(OWN_DEVICE_NAME, true);
      error = _gap.setAdvertisingPayload(_handle, _databuilder.getAdvertisingData());
      if (error)
      {
        printf("%lld: %s - setAdvertisingPayload failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      printf("%lld: setAdvertisingPayload succeeded!\r\n", time(NULL));
      ble::millisecond_t duration_ms((2 + rand() % 5) * 1000);
      ble::adv_duration_t rand_duration(duration_ms);

      error = _gap.startAdvertising(_handle, rand_duration);
      if (error)
      {
        printf("%lld: %s - startAdvertising failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      printf("%lld: Started advertising for %ldms\r\n", time(NULL), rand_duration.valueInMs());
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

      error = _gap.createSync(5, ble::sync_timeout_t(ble::millisecond_t(5000)));
      if (error)
      {
        printf("%lld: %s - createSync failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }
      printf("%lld: creating sync between devices!\r\n", time(NULL));

      _event_queue.cancel(cancel_handles[0]);
      blink(3);
    }

    void onAdvertisingEnd(const ble::AdvertisingEndEvent &event)
    {
      if (event.isConnected())
      {
        printf("%lld: If you didn't know that we where connected, then you know it now!\r\n", time(NULL));
        _event_queue.call(this, &BLEScanner::start_periodic_advertising);
      }
    }
    
    void start_periodic_advertising()
    {
      ble::AdvertisingParameters adv_params(
          ble::advertising_type_t::NON_CONNECTABLE_UNDIRECTED,
          ble::adv_interval_t(ble::millisecond_t(200))
          );

      error = _gap.setAdvertisingParameters(_handle, adv_params);
      if (error)
      {
        printf("%lld: %s - setAdvertisingParameters failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      error = _gap.startAdvertising(_handle);
      if (error)
      {
        printf("%lld: %s - startAdvertising failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      printf("%lld: Advertising restarted with non connectable parameter!\r\n", time(NULL));
    }

    void onAdvertisingStart(const ble::AdvertisingStartEvent &event)
    {
      if (is_connected)
      {
        error = _gap.setPeriodicAdvertisingParameters(_handle, 
          ble::periodic_interval_t(ble::millisecond_t(100)), 
          ble::periodic_interval_t(ble::millisecond_t(1000)),
          true);

        if (error)
        {
          printf("%lld: %s - Could not set periodic advertising parameters!\r\n", time(NULL), BLE::errorToString(error));
          return;
        }

        printf("%lld: Periodic advertising parameters has been set!\r\n", time(NULL));

        error = _gap.startPeriodicAdvertising(_handle);
        if (error)
        {
          printf("%lld: %s - startPeriodicAdvertising failed!\r\n", time(NULL), BLE::errorToString(error));
          return;
        }

        _event_queue.call_every(1000ms, this, &BLEScanner::update_periodic_advertising_set);
        printf("%lld: Periodic advertising started!\r\n", time(NULL));
      }
    }

    void update_periodic_advertising_set()
    {
      battery_level -= 5;
      if (battery_level < 5)
        battery_level = 100;

      error = _databuilder.setServiceData(GattService::UUID_BATTERY_SERVICE, mbed::make_Span(&battery_level, 1));
      if (error)
      {
        printf("%lld: %s - setServiceData failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      printf("%lld: Battery level %d %%\r\n", time(NULL), battery_level);

      error = _gap.setPeriodicAdvertisingPayload(_handle, _databuilder.getAdvertisingData());
      if (error)
      {
        printf("%lld: %s - setPeriodicAdvertisingPayload failed!\r\n", time(NULL), BLE::errorToString(error));
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
