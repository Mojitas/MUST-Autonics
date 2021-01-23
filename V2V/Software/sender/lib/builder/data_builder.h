#ifndef __DATA_BUILDER_H
#define __DATA_BUILDER_H
#include "user_headers.h"
#include "user_config.h"

/*!
 * \file data_builder.h
 * \par This file contains the function headers and all the includes that are necessary for the data_builder to work
 */

/*!
 * \class DataBuilder data_builder.h "lib/builder/data_builder.h"
 * \brief A class that returns an object related to the advertising data builder.
 */
class DataBuilder {
  public:
    /*!
     * \fn DataBuilder()
     * \brief Constructor for the DataBuilder class
     */
    DataBuilder();

    /*!
     * \fn virtual ~DataBuilder()
     * \brief Destructor for the DataBuilder class
     */
    virtual ~DataBuilder();

  public:
    /*!
     * \fn ble::AdvertisingDataBuilder initialize(BLE &_ble)
     * \param[in] _ble Bluetooth low energy object
     * \pre BLE has been instatiated and initialized, possibly even have a connection to another BLE device
     * \brief Generates a data builder for BLE which has the device name set to either NAME_SENDER or NAME_RECEIVER.
     * \post An advertising data builder with the device name set exists.
     */
    ble::AdvertisingDataBuilder initialize(BLE &_ble);
};

#endif
