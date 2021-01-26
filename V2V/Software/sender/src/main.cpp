#include "returned_ble_events.h"

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
  // Create an instance of the ble object
  BLE &nRF52840 = BLE::Instance();

  // Set the event processer
  nRF52840.onEventsToProcess(schedule_ble_processing);

  // Create an Advertiser class object and run BLE Code
  CretEvents *events = new CretEvents(nRF52840);
  events->run();

  // Exit normally
  return 0;
}
