#include "sensor.h"

/*!
 * \file sensor.cpp
 * \brief Implements functions found in sensor.h
 */

Sensor::Sensor(ble::AdvertisingDataBuilder adv, int id, int type) : _adv(adv), _sensor_id(id), _type(type)
{
}

Sensor::~Sensor()
{
}

ble::AdvertisingDataBuilder Sensor::addSensorData() {
  uint8_t data = sensor_info();
  mbed::Span<uint8_t> dataspan = mbed::make_Span(&data, 1);
  ble_error_t error = _adv.addData(ble::adv_data_type_t::SERVICE_DATA, dataspan);
  
  if (error)
  {
    printf("AdvertisingDataBuilder::addData() failed!");
  }

  return _adv;
}

uint8_t Sensor::sensor_info()
{
  uint8_t randomVal = rand() % 50;
  _value = randomVal;
  return _value;
}
