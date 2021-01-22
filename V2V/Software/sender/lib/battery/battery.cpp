#include "battery.h"
#include "data_builder.h"

/*!
 * \file battery.cpp
 * \par 
 * This file holds implementations for the functions found in battery.h.
 * It implements for now the random generator for the battery status,
 * meaning it can be anywhere between dead and alive. It also implements
 * the function that sets the service data on the data package that will
 * be advertised to the receiver/central depending on how you see it.
 */

Battery::Battery(ble::AdvertisingDataBuilder adv) : _adv(adv) 
{
}

Battery::~Battery() 
{
}

uint8_t Battery::getPower()
{
  if (level < 10)
  {
    level = 160;
    return level;
  }

  level = level - 10;
  return level;
}

ble::AdvertisingDataBuilder Battery::battery_status()
{
  uint8_t status = getPower();
  mbed::Span<uint8_t> batteryData = mbed::make_Span(&status, 1);

  ble_error_t error = _adv.setServiceData(GattService::UUID_BATTERY_SERVICE, batteryData);
  if (error)
  {
    printf("%s: setServiceData() failed!\r\n", BLE::errorToString(error));
    return _adv;
  }

  return _adv;
}
