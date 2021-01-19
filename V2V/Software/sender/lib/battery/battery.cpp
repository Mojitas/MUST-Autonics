#include "battery.h"
#include "data_builder.h"

uint8_t get_battery_info() {
  uint8_t random_number = rand();
  uint8_t charge = random_number % 4000;
  return charge;
}

ble::AdvertisingDataBuilder battery_status_package(ble::AdvertisingDataBuilder adv) {
  uint8_t batteryStatus = get_battery_info();               // Try and get the status of the battery
  mbed::Span<uint8_t> payloadData = mbed::make_Span(&batteryStatus, 1);

  ble_error_t error = adv.setServiceData(GattService::UUID_BATTERY_SERVICE, payloadData);
  if (error)
  {
    printf("AdvertisingDataBuilder::setServiceData() failed!");
  }

  return adv;
}
