#ifndef __BATTERY_H
#define __BATTERY_H
#include "user_headers.h"

int get_battery_status();
ble::AdvertisingDataBuilder battery_status_package(ble::AdvertisingDataBuilder adv);

#endif
