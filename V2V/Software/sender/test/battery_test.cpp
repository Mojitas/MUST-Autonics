#include <mbed.h>
#include <unity.h>
#include <ble/BLE.h>
#include "battery.h"

void test_get_battery_data(void)
{
  Battery b = Battery();
  int data = b.getPower();
  TEST_ASSERT_GREATER_THAN(0, data);
  TEST_ASSERT_LESS_THAN(200, data);
}

void test_battery_service_data(void)
{
  Battery b = Battery();
  ble::AdvertisingDataBuilder db = b.battery_status();
  mbed::Span<const uint8_t> c;
  db.getData(c, ble::adv_data_type_t::SERVICE_DATA);
  TEST_ASSERT_NOT_EQUAL_UINT8(*c.data(), 0);
}
