#include <events/mbed_events.h>
#include <mbed.h>
#include "ble/BLE.h"

#define BLINKING_RATE_1_MS        500ms
#define BLINKING_RATE_2_MS        250ms
#define BLINKING_RATE_3_MS        300ms
#define BLINKING_RATE_4_MS        400ms
#define PEER_DEVICE_NAME          "MUST_SENDER"
#define PEER_DEVICE_ADDR          "f9:80:1b:c4:5e:2a"
#define OWN_DEVICE_NAME           "MUST_RECEIVER"

/*#define ACTIVE_SCANNING         true  
#define SCAN_INTERVAL           ble::scan_interval_t(500)
#define SCAN_WINDOW             ble::scan_window_t(250)
*/

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

      error = _gap.setScanParameters(scan_params);
      if (error)
      {
        printf("%lld: setScanParams failed!\r\n", time(NULL));
        return;
      }

      error = _gap.startScan(ble::scan_duration_t(500));
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
      if (is_connecting || is_syncing) 
      {
        return;
      }

      //ble::rssi_t rssi = event.getRssi();
      //if (-60 > rssi)
      //  return;
      
      if (is_connected && event.getPeriodicInterval().valueInMs() == 0)
      {
        return;
      }

      ble::address_t address = event.getPeerAddress();
      ble::peer_address_type_t type = event.getPeerAddressType();
      bool is_connectable = event.getType().connectable();
 
      // printf("%lld: RSSI: %d, Address: %02x:%02x:%02x:%02x:%02x:%02x, Type: %d, Connectable: %d\r\n", time(NULL), rssi, address[5], address[4], address[3], address[2], address[1], address[0], type.value(), is_connectable);

      const int size = 18;
      char peer[size] = { 0 };
      int x = snprintf(peer, size, "%02x:%02x:%02x:%02x:%02x:%02x", address[5], address[4], address[3], address[2], address[1], address[0]);
      if (x == 0)
      {
        printf("%lld: Something went wrong printing!\r\n", time(NULL));
      } 
      else if (strncmp(peer, PEER_DEVICE_ADDR, strlen(peer)) == 0 && is_connectable) 
      {
        if (is_connected)
        {
          printf("%lld: Peer found, creating sync with periodic interval %ldms!\r\n", time(NULL), event.getPeriodicInterval().valueInMs());
          error = _gap.createSync(type, address, event.getSID(), 5, ble::sync_timeout_t(ble::millisecond_t(500)));
          if (error)
          {
            printf("%lld: %s createSync failed!\r\n", time(NULL), BLE::errorToString(error));
            return;
          }

          is_syncing = true;
          printf("%lld: Creating sync between devices!\r\n", time(NULL));
          
          error = _gap.addDeviceToPeriodicAdvertiserList(event.getPeerAddressType(), event.getPeerAddress(), event.getSID());
          if (error)
          {
            printf("%lld: %s - Failed to add to periodic advertiser list!\r\n", time(NULL), BLE::errorToString(error));
          }
        }
        else
        {
          printf("%lld: Peer device found by address %s\r\n", time(NULL), PEER_DEVICE_ADDR);
          error = _gap.connect(type, address, ble::ConnectionParameters());
          if (error)
          {
            printf("%lld: %s - Gap::connect failed!\r\n", time(NULL), BLE::errorToString(error));
            return;
          } 
          else
          {
            is_connecting = true;
            cancel_handles[2] = _event_queue.call_every(BLINKING_RATE_3_MS, this, &BLEScanner::blink, 3);
            _event_queue.cancel(cancel_handles[0]);
          }

          printf("%lld: Connecting to peer device!\r\n", time(NULL));
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
      is_connecting = false;
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
      
      _event_queue.cancel(cancel_handles[2]);
      event_queue.call_in(500ms, this, &BLEScanner::periodic_scan);
      blink(3);
    }

    void periodic_scan()
    {
      is_connected = true;
      is_syncing = false;
      is_connecting = false;

      error = _gap.startScan();
      if (error)
      {
        printf("%lld: %s - start periodic scan failed!\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      printf("%lld: Periodic scan started!\r\n", time(NULL));
    }

    void onPeriodicAdvertisingSyncEstablished(const ble::PeriodicAdvertisingSyncEstablishedEvent &event)
    {
      error = event.getStatus();
      if (error)
      {
        printf("%lld: %s - Failed to establish sync\r\n", time(NULL), BLE::errorToString(error));
        return;
      }

      is_syncing = true;
      is_connected = false;
      printf("%lld: Sync established!\r\n", time(NULL));
      _sync_handle = event.getSyncHandle();
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
    
    void onPeriodicAdvertisingSyncLoss(const ble::PeriodicAdvertisingSyncLoss &event)
    {
      printf("%lld: Sync was lost!\r\n", time(NULL));
      _gap.startScan();
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
