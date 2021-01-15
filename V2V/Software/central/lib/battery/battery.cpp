#include "battery.h"

int battery_level(int current) {
    if (current - 1 < 10)
        return 100;
    else
        return current - 1;
}
