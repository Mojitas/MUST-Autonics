#include "ble_conn.h"

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
  BLE &nRF52840 = BLE::Instance();
  nRF52840.onEventsToProcess(schedule_ble_processing);
  Advertiser *adv = new Advertiser(nRF52840);
  adv->run();
  return 0;
}
