#include "data_builder.h"

ble::AdvertisingDataBuilder initialize(BLE &_ble)
{
  ble_error_t error;

  const int data_size = _ble.gap().getMaxAdvertisingDataLength();
  uint8_t data_buffer[data_size] = { };
  ble::AdvertisingDataBuilder data_builder = ble::AdvertisingDataBuilder(data_buffer, data_size);

  error = data_builder.setFlags();
  if (error) {
    printf("Gap::createAdvertisingSet() failed!");
  }

  error = data_builder.setName(DEVICE_NAME);
  if (error)
  {
    printf("Gap::setName() failed!");
  }

  return data_builder;
}
