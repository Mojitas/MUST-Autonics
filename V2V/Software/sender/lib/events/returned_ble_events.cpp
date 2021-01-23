#include "returned_ble_events.h"

/*!
 * \file returned_ble_events.cpp
 * \include returned_ble_events.h
 * \brief Implements function headers found in the included header file.
 */
CretEvents::CretEvents(BLE &ble) : _ble(ble), _gap(ble.gap()) 
{
}

CretEvents::~CretEvents()
{
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

  // Look only at devices nearby
  if (value < -60)
  {
    printf("Device too far away!");
    return;
  }

  ble::advertising_event_t type = event.getType();
}
