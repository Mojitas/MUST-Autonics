#include <mbed.h>
#include <unity.h>
#include <ble/BLE.h>
#include "battery.h"

void test_get_battery_data(void)
{
  int data = get_battery_status();
  TEST_ASSERT_GREATER_THAN(0, data);
  TEST_ASSERT_LESS_THAN(4000, data);
}

void test_set_battery_level(void)
{
  int data = get_battery_status();
  ble::AdvertisingDataBuilder advbuilder = 
}
