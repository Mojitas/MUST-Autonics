#include "returned_ble_events.h"

/*!
 * \file returned_ble_events.cpp
 * \include returned_ble_events.h
 * \brief Implements function headers found in the included header file.
 */
CretEvents::CretEvents(BLE &ble) : Advertiser(ble), _ble(ble)
{
}

CretEvents::~CretEvents()
{
  if (_ble.hasInitialized())
    _ble.shutdown();
}

void CretEvents::run()
{
  // Set the event handler to this class
  _gap.setEventHandler(this);

  // Call the super function with the same name that runs the BLE module
  Advertiser::run();
}

BLE &CretEvents::getBleVariable()
{
  return _ble;
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

  Gap &_gap = getBleVariable().gap();
  ble::connection_handle_t _handle = event.getConnectionHandle();
  ble::phy_set_t phySet(false, false, true);
  ble::coded_symbol_per_bit_t bitSymbol(ble::coded_symbol_per_bit_t::S8);
  ble_error_t error = _gap.setPhy(_handle, &phySet, &phySet, bitSymbol);
  if (error)
  {
    printf("%s: Setting 8 symbols per bit did not work!\r\n", _ble.errorToString(error));
  }
}
