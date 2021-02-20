#include <mbed.h>
#include <events/mbed_events.h>
#include <ble/BLE.h>
#include <COMPONENT_SD/include/SD/SDBlockDevice.h>
#include <FATFileSystem.h>
#include <SPISlave.h>
#include "user_config.h"
#include <PinNames.h>

using namespace std::literals::chrono_literals;

events::EventQueue event_queue;

#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
SDBlockDevice sd(MBED_CONF_SD_SPI_MOSI,
                 MBED_CONF_SD_SPI_MISO,
                 MBED_CONF_SD_SPI_CLK,
                 MBED_CONF_SD_SPI_CS);
#endif

/**
 * TODO: Connect the cable according to the definitions for second SPI port below
 * TODO: Pins are in following order
 * TODO: P1_2 (MOSI) = D1
 * TODO: P1_3 (MISO) = D2
 * TODO: P1_1 (SSEL) = D0
 * TODO: P1_4 (SCK) = D3
 * TODO: Cables on the nucleo are from bottom, following: MISO, CS, SCK, MOSI and are
 * TODO: correctly connected
 * SPI is first defined here as a slave if needed change from it being a slave
 * to a regular SPI object.
 */
static SPISlave master(SPI_PSELMOSI1, SPI_PSELMISO1, SPI_PSELSCK1, SPI_PSELSS1);
#endif

/** Demonstrate periodic advertising and scanning and syncing with the advertising
 */
class PeriodicDemo : private mbed::NonCopyable<PeriodicDemo>, public ble::Gap::EventHandler
{
public:
    /**
     * @if DEVICE_SCANNER == false
     * @fn PeriodicDemo(BLE& ble, events::EventQueue& event_queue, FATFileSystem *fatFileSystem) :
     * @else
     * @fn PeriodicDemo(BLE& ble, events::EventQueue& event_queue) :
     * @endif
     * @brief Class initialization function
     */
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

    /**
     * @fn ~PeriodicDemo()
     * @brief Class destructor function
     */
    ~PeriodicDemo()
    {
        if (_ble.hasInitialized()) {
            _ble.shutdown();
        }
    }

    /**
     * @fn void run()
     * @brief Initializes the BLE module on the device
     * @details
     * Sets the event handler to be this class, which will receive
     * all events coming from the BLE device. We also call the
     * initialization function that sets up the BLE module on the
     * device with a callback to on_init_complete. Lastly we start
     * event handling and tell it to run forever.
     */
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

        // Start infinite event handling, meaning that the program will run for an undefined length of time
        _event_queue.dispatch_forever();
    }

private:
    /**
     * @fn void on_init_complete(BLE::InitializationCompleteCallbackContext *event)
     * @brief This is called when BLE interface is initialised and starts the first mode
     */
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

        // All calls are serialised on the user thread through the event queue
        start_role();
    }

    /**
     * @fn void start_role()
     * @brief Start role selection
     * @details
     * IF the roles is established then one of the
     * devices will start periodic advertisement,
     * while the other device starts a periodic
     * scan. However, when the devices have not yet
     * discovered each other and the roles that they
     * have, they cycle through the roles until they
     * know who is going to do what.
     */
    void start_role()
    {
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

    /**
     * @fn void advertise()
     * @brief Setup and start advertising
     * @details
     * Make a connectable advertisement that uses 200 ms intervals.
     * The set is applied to the gap module in the ble which tells
     * it to use that interval and make it connectable. We then
     * tell the BLE module to use the DEVICE_NAME specified in
     * the use_config.h file. Finally we start advertising at
     * a random interval which we do not have control over
     * since we need to discover the other device and the other
     * way around.
     */
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

    /**
     * @fn void advertise_periodic()
     * @brief Starts periodic advertisement
     * @details
     * Sets the advertising interval to 200 milliseconds with a non-connectable and undirected package.
     * Meaning it's receivable by anyone. It then writes the failure to an SD Card if there was an error,
     * otherwise it continues with activating the advertisement. If successful, the device shall have
     * started periodic advertisement.
     */
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
    }

    /**
     * @fn void scan()
     * @brief
     * A regular scan is setup with a duration of 500 ms
     * and a randomized address as scan parameters.
     */
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

    /**
     * @fn void scan_periodic()
     * @brief Starts scanning again, this time
     * with role_established set to <b>true</b>.
     */
    void scan_periodic()
    {
        _is_connecting_or_syncing = false;

        ble_error_t error = _ble.gap().startScan();

        if (error) {
            return;
        }

        printf("Scanning for periodic advertising started\r\n");
    }

    /**
     *
     * @fn void update_sensor_value()
     * @brief
     * Updates the payload used for periodic advertisement.
     * It does so using SPI and it also writes to SD Card
     * using SDBlockDevice or FATFileSystem.
     */
    void update_sensor_value()
    {
#if DEVICE_SCANNER == false
        /**
         * The _battery_level variable here is what is being updated when as a test that it works
         * when connected properly.
         * TODO: Make sure it receives data (The data it receives is both written to SD card and sent
         * TODO: via BLE to another nRF-device) or modify the code for the sender so that it receives
         * TODO: the data correctly. Finally push that changes to GitHub and I will write documentation
         * TODO: for the code as well as a manual for the devices. // Erik Kamph
         */
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
    /**
     * @addtogroup EventHandler
     * @brief The Gap Event handler functions that we use
     * @{
     */
    /**
     * @fn void onAdvertisingStart(const ble::AdvertisingStartEvent &event) override
     * @brief When we start scanning we will make a decision to also start periodic advertising based on role
     */
    void onAdvertisingStart(const ble::AdvertisingStartEvent &event) override
    {
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

            _event_queue.call_every(1000ms, this, &PeriodicDemo::update_sensor_value);
        }
    }

    /**
     * @fn void onAdvertisingReport(const ble::AdvertisingReportEvent &event) override
     * @brief Look at scan payload to find a peer device and connect to it
     */
    void onAdvertisingReport(const ble::AdvertisingReportEvent &event) override
    {
        // If we are already connecting or in sync with the other device we can discard these kinds of events.
        if (_is_connecting_or_syncing) {
            return;
        }

        // If we have established roles but there are no periodic interval present we discard the events
        // until the periodic interval is present in the payload from the other device
        if (_role_established && !event.isPeriodicIntervalPresent()) {
            return;
        }

        ble::AdvertisingDataParser adv_parser(event.getPayload());

        // Parse the advertising payload, looking for a discoverable device
        while (adv_parser.hasNext()) {
            ble::AdvertisingDataParser::element_t field = adv_parser.next();

            // Identify the other device using the OTHER_NAME definition from user_config.h file
            if (field.type == ble::adv_data_type_t::COMPLETE_LOCAL_NAME &&
                field.value.size() == strlen(OTHER_NAME) &&
                (memcmp(field.value.data(), OTHER_NAME, field.value.size()) == 0)) {
                // if we haven't established our roles connect, otherwise sync with advertising
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

                _is_connecting_or_syncing = true;

                return;
            }
        }
    }

    /**
     * @fn void onScanTimeout(const ble::ScanTimeoutEvent&) override
     * @brief When we have connected or chosen to end scanning this event is triggered
     */
    void onScanTimeout(const ble::ScanTimeoutEvent&) override
    {
        if (!_is_connecting_or_syncing) {
            printf("Scanning ended, failed to find peer\r\n");
            start_role();
        }
    }

    /**
     * @fn void onConnectionComplete(const ble::ConnectionCompleteEvent &event) override
     * @brief This is called by Gap to notify the application we connected
     */
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

    /**
     * @fn void onDisconnectComplete(const ble::DisconnectionCompleteEvent &event) override
     * @brief This is called by Gap to notify the application we disconnected
     */
    void onDisconnectionComplete(const ble::DisconnectionCompleteEvent &event) override
    {
        printf("Disconnected\r\n");
        start_role();
    }

    /**
     * @fn void onPeriodicAdvertisingSyncEstablished(const ble::PeriodicAdvertisingSyncEstablishedEvent &event) override
     * @brief Called when first advertising packet in periodic advertising is received.
     */
    void onPeriodicAdvertisingSyncEstablished(const ble::PeriodicAdvertisingSyncEstablishedEvent &event) override
    {
        if (event.getStatus() == BLE_ERROR_NONE) {
            printf("Synced with periodic advertising\r\n");
            _sync_handle = event.getSyncHandle();
        } else {
            printf("Sync with periodic advertising failed\r\n");
        }
    }

    /**
     * @fn void onPeriodicAdvertisingReport(const ble::PeriodicAdvertisingReportEvent &event) override
     * @brief Called when a periodic advertising packet is received.
     */
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

    /**
     * @fn void onPeriodicAdvertisingSyncLoss(const ble::PeriodicAdvertisingSyncLoss &event) override
     * @brief Called when a periodic advertising sync has been lost.
     * @param event The PeriodicAdvertisingSyncLoss event.
     * */
    void onPeriodicAdvertisingSyncLoss(const ble::PeriodicAdvertisingSyncLoss &event) override
    {
        printf("Sync to periodic advertising lost\r\n");
        _sync_handle = ble::INVALID_ADVERTISING_HANDLE;
        _event_queue.call(this, &PeriodicDemo::scan_periodic);
    }
    /**
     * @}
     */
     
#if DEVICE_SCANNER == false
    /**
     * @fn void write_buffer_to_file(const char *buffer, size_t buf_size)
     * @brief Takes a string of text and writes it to a .txt or .log file
     * @param buffer The buffer to write to the log file
     * @param buf_size The size of the buffer that is going to be written
     */
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
    /**
     * @addtogroup Variables
     * @brief All the necessary variables that is used within the @class PeriodicDemo
     * @{
     */
    /**
     * @var _ble
     * @brief The reference to a instantiated BL
     */
    BLE  &_ble;
    /**
     * @var _event_queue
     * @brief This is where we schedule all the events
     */
    events::EventQueue &_event_queue;

    /**
     * @var _adv_buffer[MAX_ADVERTISING_PAYLOAD_SIZE]
     * @brief a buffer for building a message to send to the other BLE device
     */
    uint8_t _adv_buffer[MAX_ADVERTISING_PAYLOAD_SIZE];
    /**
     * @var _adv_data_builder
     * @brief This is the object which builds the data together
     * into a package using the _adv_buffer[MAX_ADVERTISING_PAYLOAD_SIZE]
     */
    ble::AdvertisingDataBuilder _adv_data_builder;

    /**
     * @var _adv_handle
     * @brief The advertising handle that is used before periodic advertising starts
     */
    ble::advertising_handle_t _adv_handle = ble::INVALID_ADVERTISING_HANDLE;
    /**
     * @var _sync_handle
     * @brief A handle set when in sync but never used.
     */
    ble::periodic_sync_handle_t _sync_handle = ble::INVALID_ADVERTISING_HANDLE;

    /**
     * @var _battery_level
     * @brief Used when simulating the battery level
     */
    uint8_t _battery_level = 100;

    /**
     * @var _is_scanner
     * @brief Is set to the opposite of the DEVICE_SCANNER variable
     */
    bool _is_scanner = !DEVICE_SCANNER;
    /**
     * @var _is_connecting_or_syncing
     * @brief When the device is connecting or syncing we ignore
     * events fired by reports generated from scanning
     */
    bool _is_connecting_or_syncing = false;
    /**
     * @var _role_established
     * @brief When we know if one of the devices is central
     * or peripheral this changes to true
     */
    bool _role_established = false;

#if DEVICE_SCANNER == false
    /**
     * @var _file_system
     * @brief A reference to the initiated file system on SD-Card
     */
    FATFileSystem *_file_system;
    /**
     * @var _fp
     * @brief a variable that is set depending on when we write
     * and not.
     */
    File _fp;
#endif
    /**
     * @}
     */
};

/**
 * @fn void schedule_ble_events(BLE::OnEventsToProcessCallbackContext *context)
 * @brief The callback for all the BLE events that needs to be processed from the nRF52840 SoC
 * @param context the context for the event
 */
void schedule_ble_events(BLE::OnEventsToProcessCallbackContext *context)
{
    event_queue.call(Callback<void()>(&context->ble, &BLE::processEvents));
}

/**
 * @fn int main()
 * @brief defines the entry point for the program
 * @return an integers defining the success status
 */
int main()
{
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
    // Initiates the file system on the sd card
    FATFileSystem fatFileSystem("sd");
    if (fatFileSystem.mount(&sd) < 0)
    {
        perror(strerror(errno));
        return -1;
    }
#endif
#endif

    // Instantiates ble
    BLE &ble = BLE::Instance();

    // Informs us of all the events in the BLE module
    ble.onEventsToProcess(schedule_ble_events);

    // Create an instance of the program
#if DEVICE_SCANNER == false
#ifdef MY_SD_DEFINITION
    PeriodicDemo demo(ble, event_queue, &fatFileSystem);
#else
    PeriodicDemo demo(ble, event_queue, nullptr);
#endif
#else
    PeriodicDemo demo(ble, event_queue);
#endif

    // Run the program
    demo.run();

    return 0;
}
