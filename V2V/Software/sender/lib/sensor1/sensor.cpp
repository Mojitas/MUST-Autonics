#include "sensor.h"

uint8_t sensor_info()
{
  uint8_t random_value = rand();
  uint8_t temp = random_value % 40;
  return temp;
}

/**
 *
 **/
ble::AdvertisingDataBuilder addSensorData(ble::AdvertisingDataBuilder adv) {
  data = sensor_info();
  mbed::Span<uint8_t> dataspan = mbed::make_Span(&data, 1);
  ble_error_t error = adv.addData(ble::adv_data_type_t::SERVICE_DATA, dataspan);
  
  if (error)
  {
    printf("AdvertisingDataBuilder::addData() failed!");
  }

  return adv;
}
