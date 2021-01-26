#ifndef __EXTRA_FUNCTIONS_H
#define __EXTRA_FUNCTIONS_H
#include <ble/BLE.h>

/*!
 * \file extra_functions.h
 */

/*!
 * \fn void print_address(ble::address_t address)
 * \brief Prints a Mac address of a device
 * \details 
 * Prints the address that is sent to the function. 
 * It does not matter if it is a peer or not, it is supposed to reduce code. 
 * Remember to print before wether this is a peer address or the own device address.
 * \pre There must be an address that's either a peer address, or comes from the device itself.
 * \post None
 * \todo Implement something that prints whether it is a peer address or not
 */
void print_mac_address(ble::address_t address);

#endif
