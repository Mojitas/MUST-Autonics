#include "returned_ble_events.h"

/*!
 * \file returned_ble_events.cpp
 * \include returned_ble_events.h
 * \brief Implements function headers found in the included header file.
 */
CretEvents::CretEvents(BLE &ble) : _advertiser(ble)
{
}

CretEvents::~CretEvents()
{
    _advertiser.~Advertiser();
}

void CretEvents::run()
{
  // Set the event handler to this class
  _advertiser._gap.setEventHandler(this);

  // Call the super function with the same name that runs the BLE module
  _advertiser.run();
}

void CretEvents::onAdvertisingStart(const ble::AdvertisingStartEvent &event)
{
}

void CretEvents::onAdvertisingEnd(const ble::AdvertisingEndEvent &event)
{
}

void CretEvents::onAdvertisingReport(const ble::AdvertisingReportEvent &event)
{
  ble::rssi_t value = event.getRssi();
  printf("RSSI: %d dBm", value);

  ble::address_t peer = event.getPeerAddress();
  print_mac_address(peer);

  // Look only at devices nearby
  if (value < -60)
  {
    printf("Device too far away!");
    return;
  }
}

void onConnectionComplete(const ble::ConnectionCompleteEvent &event)
{
  if (event.getStatus())
  {
    printf("%s: Connection failed!", BLE::errorToString(event.getStatus()));
    return;
  }

  _advertiser._handle = event.getConnectionHandle();
  ble::phy_set_t phySet(false, false, true);
  ble::coded_symbol_per_bit_t bitSymbol(ble::coded_symbol_per_bit_t::S8);
  _advertiser.error = _advertiser._gap.setPhy(_advertiser._handle, &phySet, &phySet, bitSymbol);
  if (_advertiser.error)
  {
    printf("%s: Setting 8 symbols per bit did not work!\r\n", BLE::errorToString(_advertiser.error));
  }
}
