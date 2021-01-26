#ifndef __BLE_CONN_H
#define __BLE_CONN_H
#include "user_headers.h"
#include "data_builder.h"

/*!
 * \file ble_conn.h
 * \par Holds variables used in with BLE and the headers for functions implemented in ble_conn.cpp
 */

static events::EventQueue event_queue(EVENTS_QUEUE_SIZE);

/*!
 * \fn void schedule_ble_processing(BLE::OnEventsToProcessCallbackContext *context)
 * \brief Tells the ble to process events in our program
 * \post the BLE object needs to have this function as handle on onEventsToProcess
 */
void schedule_ble_processing(BLE::OnEventsToProcessCallbackContext *context);

/*!
 * \class Advertiser ble_conn.h "lib/connection/ble_conn.h"
 */
class Advertiser : private mbed::NonCopyable<Advertiser>
{
  public:
    Advertiser(BLE &ble);
    virtual ~Advertiser();
    void run();

  public:
    /*!
     * \fn void on_ble_init_complete(BLE::InitializationCompleteCallbackContext *context)
     * \brief When the ble has been initialized we check if it was sucessful and set the phy to use.
     *        We then call the advertising function that will send out a connectable ble signal.
     * \pre BLE has to be initialized successfully
     * \post We have set the preferred phys to LE_CODED_PHY so that we later can set the number of symbols to either 2 or 8.
     */
    void on_ble_init_complete(BLE::InitializationCompleteCallbackContext *context);

    /*!
     * \fn void device_scan()
     * \pre BLE has initialized
     * \post We look for a device with name NAME_SENDER which is going to be the peripheral.
     * \brief Starts a scan that will look for another device
     */
    void device_scan();

  public:
    BLE &_ble;
    Gap &_gap;
    events::EventQueue _event_queue;
    DataBuilder *_builder = nullptr;
    ble::advertising_handle_t adv_handle = ble::INVALID_ADVERTISING_HANDLE;
    ble_error_t error;
    ble::connection_handle_t _handle;
    bool is_connected = false;
};

#endif
