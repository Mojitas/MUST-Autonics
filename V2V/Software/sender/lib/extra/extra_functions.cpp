#include "extra_functions.h"

void print_mac_address(ble::address_t address)
{
  for (int i = 5; i > 1; i--) {
    printf("%02x:", address[i]);
  }
  printf("%02x", address[0]);
}
