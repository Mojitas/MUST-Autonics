#ifndef __BATTERY_H
#define __BATTERY_H
#include <ble/BLE.h>

/*!
 * \file battery.h
 * \brief Headerfile for battery data functions
 */

/*!
 * \class Battery battery.h "lib/battery/battery.h"
 * \brief This class holds the battery module.
 * \details This class implements something that automatically on each call lowers the battery level to reflect a real world battery.
 */
class Battery : private mbed::NonCopyable<Battery>
{
  public:
    /*!
     * \fn Battery(ble::AdvertisingDataBuilder adv)
     * \brief Constructor for the class
     */
    Battery(ble::AdvertisingDataBuilder adv);

    /*!
     * \fn virtual ~Battery()
     * \brief Destructor for the class
     */
    virtual ~Battery();
    
    /*!
     * \fn uint8_t getPower()
     * \brief Decreases an integer from 160 to 10 and starts over at 10
     * \return uint8_t An integer value
     * \pre None
     * \post A positive integer has been generated
     */
    uint8_t getPower();

    /*!
     * \fn ble::AdvertisingDataBuilder battery_status()
     * \brief Set the UUID service data to the battery level of the solar car
     * \pre A advertising data builder needs to exist or have been created at the call of this function
     * \param[in] adv An advertising data builder
     * \post The data exist under the UUID_BATTERY_SERVICE GattService tag in the service data.
     */
    ble::AdvertisingDataBuilder battery_status();

  private:
    /*!
     * \var level
     * \brief Holds the current battery level
     */
    uint8_t level = 160;

    /*!
     * \var _adv
     * \brief Holds the advertising data builder that is sent on initialization of the class object.
     */
    ble::AdvertisingDataBuilder _adv;
};


#endif
