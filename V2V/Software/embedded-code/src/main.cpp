#include <mbed.h>
#include <events/mbed_events.h>
#include <ble/BLE.h>
#include <COMPONENT_SD/include/SD/SDBlockDevice.h>
#include <FATFileSystem.h>
#include <SPISlave.h>
#include "user_config.h"

using namespace std::literals::chrono_literals;

events::EventQueue event_queue;

#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
SDBlockDevice sd(MBED_CONF_SD_SPI_MOSI,
                 MBED_CONF_SD_SPI_MISO,
                 MBED_CONF_SD_SPI_CLK,
                 MBED_CONF_SD_SPI_CS);
#endif

static SPISlave master(D0, D1, D2, D3);
#endif

/** Demonstrate periodic advertising and scanning and syncing with the advertising
 */
class PeriodicDemo : private mbed::NonCopyable<PeriodicDemo>, public ble::Gap::EventHandler
{
public:
#if DEVICE_SCANNER == false
    PeriodicDemo(BLE& ble, events::EventQueue& event_queue, FATFileSystem *fatFileSystem) :
        _ble(ble),
        _event_queue(event_queue),
        _adv_data_builder(_adv_buffer),
        _file_system(fatFileSystem)
    {
    }
#else
    PeriodicDemo(BLE& ble, events::EventQueue& event_queue) :
        _ble(ble),
        _event_queue(event_queue),
        _adv_data_builder(_adv_buffer)
    {
    }
#endif

    ~PeriodicDemo()
    {
        if (_ble.hasInitialized()) {
            _ble.shutdown();
        }
    }

    /** Start BLE interface initialisation */
    void run()
    {
        /* handle gap events */
        _ble.gap().setEventHandler(this);

        ble_error_t error = _ble.init(this, &PeriodicDemo::on_init_complete);
        if (error) {
            char buffer[] = "Error initializing bluetooth LE!\r\n";
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
            write_buffer_to_file(buffer, sizeof(buffer));
#else
            printf("%s", buffer);
#endif
#else
            printf("%s", buffer);
#endif
            return;
        }

        /* this will not return until shutdown */
        _event_queue.dispatch_forever();
    }

private:
    /** This is called when BLE interface is initialised and starts the first mode */
    void on_init_complete(BLE::InitializationCompleteCallbackContext *event)
    {
        if (event->error) {
            char buffer[] = "Error on initialization of BLE\r\n";
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
            write_buffer_to_file(buffer, sizeof(buffer));
#else
            printf("%s", buffer);
#endif
#else
            printf("%s", buffer);
#endif
            return;
        }

        if (!_ble.gap().isFeatureSupported(ble::controller_supported_features_t::LE_EXTENDED_ADVERTISING) ||
            !_ble.gap().isFeatureSupported(ble::controller_supported_features_t::LE_PERIODIC_ADVERTISING)) {
            printf("Periodic advertising not supported.\r\n");
            return;
        }

        if (_ble.gap().isFeatureSupported(ble::controller_supported_features_t::LE_CODED_PHY))
        {
            ble::phy_set_t phys(ble::phy_t::LE_CODED);
            ble_error_t error = _ble.gap().setPreferredPhys(&phys, &phys);
            if (error) {
                const char *err = BLE::errorToString(error);
#if DEVICE_SCANNER == false
                write_buffer_to_file(err, sizeof(error));
#endif

            }
        }

        /* all calls are serialised on the user thread through the event queue */
        start_role();
    }

    void start_role()
    {
        /* This example is designed to be run on two boards at the same time,
         * depending on our role we will either be the advertiser or scanner,
         * until the roles are established we will cycle the roles until we find each other */
        if (_role_established) {
            if (_is_scanner) {
                _event_queue.call(this, &PeriodicDemo::scan_periodic);
            } else {
                _event_queue.call(this, &PeriodicDemo::advertise_periodic);
            }
        } else {
            _is_scanner = !_is_scanner;

            if (_is_scanner) {
                _event_queue.call(this, &PeriodicDemo::scan);
            } else {
                _event_queue.call(this, &PeriodicDemo::advertise);
            }
        }
    }

    /** Set up and start advertising */
    void advertise()
    {
        ble_error_t error;

        ble::AdvertisingParameters adv_parameters(
            ble::advertising_type_t::CONNECTABLE_NON_SCANNABLE_UNDIRECTED,
            ble::adv_interval_t(ble::millisecond_t(100))
        );

        adv_parameters.setUseLegacyPDU(false);

        error = _ble.gap().createAdvertisingSet(
            &_adv_handle,
            adv_parameters
        );

        if (error) {
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
            char buffer[] = "Error creating advertising set!\r\n";
            write_buffer_to_file(buffer, sizeof(buffer));
#endif
#endif
            return;
        }

        _adv_data_builder.setFlags();
        _adv_data_builder.setName(DEVICE_NAME);

        /* Set payload for the set */
        error = _ble.gap().setAdvertisingPayload(
            _adv_handle,
            _adv_data_builder.getAdvertisingData()
        );

        if (error) {
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
            char buf[] = "Error setting advertising payload!";
            write_buffer_to_file(buf, sizeof(buf));
#endif
#endif
            return;
        }

        /* since we have two boards which might start running this example at the same time
         * we randomise the interval of advertising to have them meet when one is advertising
         * and the other one is scanning (we use their random address as source of randomness) */
        ble::millisecond_t random_duration_ms((2 + rand() % 5) * 1000);
        ble::adv_duration_t random_duration(random_duration_ms);

        error = _ble.gap().startAdvertising(
            _adv_handle,
            random_duration
        );

        if (error) {
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
            char buff[] = "Error starting advertisment!";
            write_buffer_to_file(buff, sizeof(buff));
#endif
#endif
            return;
        }

#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
        char bu[] = "Advertising started!\r\n";
        write_buffer_to_file(bu, sizeof(bu));
#endif
#endif
        printf("Advertising started for %ldms\r\n", random_duration_ms.valueInMs());
    }

    void advertise_periodic()
    {
        ble::AdvertisingParameters adv_parameters(
            ble::advertising_type_t::NON_CONNECTABLE_UNDIRECTED,
            ble::adv_interval_t(ble::millisecond_t(200))
        );

        adv_parameters.setUseLegacyPDU(false);

        ble_error_t error = _ble.gap().setAdvertisingParameters(_adv_handle, adv_parameters);

        if (error) {
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
            char buffer[] = "Set periodic advertising parameters failed!\r\n";
            write_buffer_to_file(buffer, sizeof(buffer));
#endif
#endif
            return;
        }

        /* Start advertising the set as the advertising needs to be active
         * before we start periodic advertising */
        error = _ble.gap().startAdvertising(_adv_handle);

        if (error) {
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
            char buf[] = "Error starting advertising!\r\n";
            write_buffer_to_file(buf, sizeof(buf));
#endif
#endif
            return;
        }

        /* periodic advertising will be enabled when advertising starts */
    }

    /** Set up and start scanning */
    void scan()
    {
        _is_connecting_or_syncing = false;

        ble::ScanParameters scan_params;
        scan_params.setOwnAddressType(ble::own_address_type_t::RANDOM);

        ble_error_t error = _ble.gap().setScanParameters(scan_params);

        if (error) {
            return;
        }

        error = _ble.gap().startScan(ble::scan_duration_t(500));

        if (error) {
            return;
        }

        printf("Scanning started\r\n");
    }

    void scan_periodic()
    {
        _is_connecting_or_syncing = false;

        ble_error_t error = _ble.gap().startScan();

        if (error) {
            return;
        }

        printf("Scanning for periodic advertising started\r\n");
    }

    /* also updates periodic advertising payload */
    void update_sensor_value()
    {
#if DEVICE_SCANNER == false
        master.reply(0x00);
        if (master.receive())
        {
            _battery_level = master.read();
        }
#else
        /* simulate battery level */
        _battery_level--;
        if (_battery_level < 1) {
            _battery_level = 100;
        }
#endif

#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
        char b_level[50] = { 0 };
        snprintf(b_level, 50, "Solar Car Battery Level: %d\r\n", _battery_level);
        write_buffer_to_file(b_level, sizeof(b_level));
#endif
#endif

        /* update the level in the payload */
        ble_error_t error = _adv_data_builder.setServiceData(
            GattService::UUID_BATTERY_SERVICE,
            mbed::make_Span(&_battery_level, 1)
        );

        if (error) {
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
            char err[] = "Could not set service data on the advertising payload!\r\n";
            write_buffer_to_file(err, sizeof(err));
#endif
#endif
            return;
        }

        /* the data in the local host buffer has been updated but now
         * we have to update the data in the controller */
        error = _ble.gap().setPeriodicAdvertisingPayload(
            _adv_handle,
            _adv_data_builder.getAdvertisingData()
        );

        if (error)
        {
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
            char err[] = "Set periodic advertising payload failed!\r\n";
            write_buffer_to_file(err, sizeof(err));
#endif
#endif
        }
    }

private:
    /* Gap::EventHandler */

    void onAdvertisingStart(const ble::AdvertisingStartEvent &event) override
    {
        /* start periodic advertising only if we're already advertising after roles established */
        if (_role_established) {
            ble_error_t error = _ble.gap().setPeriodicAdvertisingParameters(
                _adv_handle,
                ble::periodic_interval_t(100),
                ble::periodic_interval_t(1000)
            );

            if (error) {
                return;
            }

            error = _ble.gap().startPeriodicAdvertising(_adv_handle);

            if (error) {
                return;
            }

            printf("Periodic advertising started\r\n");

            /* tick over our fake battery data, this will also update the advertising payload */
            _event_queue.call_every(1000ms, this, &PeriodicDemo::update_sensor_value);
        }
    }

    /** Look at scan payload to find a peer device and connect to it */
    void onAdvertisingReport(const ble::AdvertisingReportEvent &event) override
    {
        /* don't bother with analysing scan result if we're already connecting */
        if (_is_connecting_or_syncing) {
            return;
        }

        /* if we're looking for periodic advertising don't bother unless it's present */
        if (_role_established && !event.isPeriodicIntervalPresent()) {
            return;
        }

        ble::AdvertisingDataParser adv_parser(event.getPayload());

        /* parse the advertising payload, looking for a discoverable device */
        while (adv_parser.hasNext()) {
            ble::AdvertisingDataParser::element_t field = adv_parser.next();

            /* identify peer by name */
            if (field.type == ble::adv_data_type_t::COMPLETE_LOCAL_NAME &&
                field.value.size() == strlen(OTHER_NAME) &&
                (memcmp(field.value.data(), OTHER_NAME, field.value.size()) == 0)) {
                /* if we haven't established our roles connect, otherwise sync with advertising */
                if (_role_established) {
                    printf("We found the peer, syncing with SID %d"
                           " and periodic interval %ldms\r\n",
                           event.getSID(), event.getPeriodicInterval().valueInMs());

                    ble_error_t error = _ble.gap().createSync(
                        event.getPeerAddressType(),
                        event.getPeerAddress(),
                        event.getSID(),
                        2,
                        ble::sync_timeout_t(ble::millisecond_t(5000))
                    );

                    if (error) {
                        return;
                    }
                } else {
                    printf("We found the peer, connecting\r\n");

                    ble_error_t error = _ble.gap().connect(
                        event.getPeerAddressType(),
                        event.getPeerAddress(),
                        ble::ConnectionParameters() // use the default connection parameters
                    );

                    if (error) {
                        return;
                    }
                }

                /* we may have already scan events waiting to be processed
                 * so we need to remember that we are already connecting
                 * or syncing and ignore them */
                _is_connecting_or_syncing = true;

                return;
            }
        }
    }

    void onScanTimeout(const ble::ScanTimeoutEvent&) override
    {
        if (!_is_connecting_or_syncing) {
            printf("Scanning ended, failed to find peer\r\n");
            start_role();
        }
    }

    /** This is called by Gap to notify the application we connected */
    void onConnectionComplete(const ble::ConnectionCompleteEvent &event) override
    {
        if (event.getStatus() == BLE_ERROR_NONE) {
            printf("Roles established\r\n");
            _role_established = true;

            if (_is_scanner) {
                printf("I will synchronise with periodic advertising\r\n");
                _event_queue.call_in(
                    1000ms,
                    [this, handle = event.getConnectionHandle()] {
                        _ble.gap().disconnect(
                            handle,
                            ble::local_disconnection_reason_t(ble::local_disconnection_reason_t::USER_TERMINATION)
                        );
                    }
                );
            } else {
                printf("I will advertise periodic advertising\r\n");
            }
        } else {
            printf("Failed to connect\r\n");
            start_role();
        }
    }

    /** This is called by Gap to notify the application we disconnected */
    void onDisconnectionComplete(const ble::DisconnectionCompleteEvent &event) override
    {
        printf("Disconnected\r\n");
        start_role();
    }

    /** Called when first advertising packet in periodic advertising is received. */
    void onPeriodicAdvertisingSyncEstablished(const ble::PeriodicAdvertisingSyncEstablishedEvent &event) override
    {
        if (event.getStatus() == BLE_ERROR_NONE) {
            printf("Synced with periodic advertising\r\n");
            _sync_handle = event.getSyncHandle();
        } else {
            printf("Sync with periodic advertising failed\r\n");
        }
    }

    /** Called when a periodic advertising packet is received. */
    void onPeriodicAdvertisingReport(const ble::PeriodicAdvertisingReportEvent &event) override
    {
        ble::AdvertisingDataParser adv_parser(event.getPayload());

        /* parse the advertising payload, looking for a battery level */
        while (adv_parser.hasNext()) {
            ble::AdvertisingDataParser::element_t field = adv_parser.next();

            if (field.type == ble::adv_data_type_t::SERVICE_DATA) {
                if (*((uint16_t*)field.value.data()) != GattService::UUID_BATTERY_SERVICE) {
                    printf("Unexpected service data\r\n");
                } else {
                    /* battery level is right after the UUID */
                    const uint8_t *battery_level = field.value.data() + sizeof(uint16_t);
                    printf("Peer battery level: %d\r\n", *battery_level);
                }
            }
        }
    }

    /** Called when a periodic advertising sync has been lost. */
    void onPeriodicAdvertisingSyncLoss(const ble::PeriodicAdvertisingSyncLoss &event) override
    {
        printf("Sync to periodic advertising lost\r\n");
        _sync_handle = ble::INVALID_ADVERTISING_HANDLE;
        _event_queue.call(this, &PeriodicDemo::scan_periodic);
    }

#if DEVICE_SCANNER == false
    void write_buffer_to_file(const char *buffer, size_t buf_size)
    {
        if (_fp.open(_file_system, "data.1.log", O_RDWR | O_CREAT | O_APPEND) < 0)
        {
            perror(strerror(errno));
            return;
        }

        if (_fp.write(buffer, buf_size) < 0)
        {
            perror(strerror(errno));
            return;
        }

        if (_fp.close() < 0)
        {
            perror(strerror(errno));
            return;
        }
    }
#endif

private:
    BLE  &_ble;
    events::EventQueue &_event_queue;

    uint8_t _adv_buffer[MAX_ADVERTISING_PAYLOAD_SIZE];
    ble::AdvertisingDataBuilder _adv_data_builder;

    ble::advertising_handle_t _adv_handle = ble::INVALID_ADVERTISING_HANDLE;
    ble::periodic_sync_handle_t _sync_handle = ble::INVALID_ADVERTISING_HANDLE;

    uint8_t _battery_level = 100;

    bool _is_scanner = !DEVICE_SCANNER;
    bool _is_connecting_or_syncing = false;
    bool _role_established = false;

#if DEVICE_SCANNER == false
    FATFileSystem *_file_system;
    File _fp;
#endif
};

/** Schedule processing of events from the BLE middleware in the event queue. */
void schedule_ble_events(BLE::OnEventsToProcessCallbackContext *context)
{
    event_queue.call(Callback<void()>(&context->ble, &BLE::processEvents));
}

int main()
{
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
    FATFileSystem fatFileSystem("sd");
    if (fatFileSystem.mount(&sd) < 0)
    {
        perror(strerror(errno));
        return -1;
    }
#endif
#endif

    BLE &ble = BLE::Instance();

    /* this will inform us off all events so we can schedule their handling
     * using our event queue */
    ble.onEventsToProcess(schedule_ble_events);

    /* look for other device and then settle on a role and sync periodic advertising */
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
    PeriodicDemo demo(ble, event_queue, &fatFileSystem);
#else
    PeriodicDemo demo(ble, event_queue, nullptr);
#endif
#else
    PeriodicDemo demo(ble, event_queue);
#endif

    demo.run();

    return 0;
}
