#ifndef __BLE_CONN_H
#define __BLE_CONN_H
#include "user_headers.h"
#include "data_builder.h"

/*!
 * \file ble_conn.h
 * \par Holds variables used in with BLE and the headers for functions implemented in ble_conn.cpp
 */

static events::EventQueue event_queue(32 * EVENTS_EVENT_SIZE);
static BLE &_ble = BLE::Instance();
static ble::advertising_handle_t adv_handle = ble::INVALID_ADVERTISING_HANDLE;

/*!
 * \fn void schedule_ble_processing(BLE::OnEventsToProcessCallbackContext *context)
 * \brief Tells the ble to process events in our program
 * \post the BLE object needs to have this function as handle on onEventsToProcess
 */
void schedule_ble_processing(BLE::OnEventsToProcessCallbackContext *context);

/*!
 * \fn void on_ble_init_complete(BLE::InitializationCompleteCallbackContext *context)
 * \brief When the ble has been initialized we check if it was sucessful and set the phy to use.
 *        We then call the advertising function that will send out a connectable ble signal.
 * \pre BLE has to be initialized successfully
 * \post We can start advertising on CODED_PHY
 */
void on_ble_init_complete(BLE::InitializationCompleteCallbackContext *context);

/*!
 * \fn void advertise()
 * \brief Advertise a connectable status to other devices nearby
 * \pre BLE is initialized
 * \post Advertising has been started and the handle is saved for later
 */
void advertise();
#endif
