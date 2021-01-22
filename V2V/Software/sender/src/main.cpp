#include "user_headers.h"
#include "data_builder.h"
#include "battery.h"
#include "ble_conn.h"
#include "sensor.h"
//#include "returned_ble_events.h"

/*!
 * \file main.cpp
 * \brief Entry file for the program
 */

/*!
 * \fn int main(void)
 * \brief Entry point for the program that runs the BLE module
 */
int main(void)
{
  // Setup an event handler
  //CretEvents eventHandler = CretEvents();
  //_ble.gap().setEventHandler(eventHandler);
  _ble.onEventsToProcess(schedule_ble_processing);

  // Initialize the BLE device
  _ble.init(on_ble_init_complete);

  // Dispatch the queue for as long as we can, which is forever
  event_queue.dispatch_forever();

  if (_ble.hasInitialized())
    _ble.shutdown();
  return 0;
}
