#ifndef __SENSOR_H
#define __SENSOR_H
#include "user_headers.h"

/*!
 * \file sensor.h
 */

/*!
 * \class Sensor sensor.h "lib/sensor1/sensor.h"
 * \brief Implements the code for a replication of a sensor
 */
class Sensor
{
  private:
    ble::AdvertisingDataBuilder _adv;
    int _sensor_id = 0;
    int _type = 0;
    int _value = 0;
  
  private:
    /*!
     * \fn uint8_t sensor_info()
     * \brief Randomly generates an integer from 0 to 40.
     * \pre None
     * \return A randomly generated integer from 0 to 40.
     * \post A non negative integer
     */
    uint8_t sensor_info();

  public:
    Sensor(ble::AdvertisingDataBuilder adv, int id, int type);
    virtual ~Sensor();
    /*!
     * \fn ble::AdvertisingDataBuilder addSensorData(ble::AdvertisingDataBuilder adv)
     * \brief Modifies and updates an existing databuilder with information from a sensor, this tries to reflect a temperature sensor going crazy from 0 to 40 degrees Celsius
     * \pre A databuilder exists or has been created in connection with this call
     * \param[in] adv a data builder that accepts data that will be advertised over ble
     * \return A modified data builder
     * \post The modified data builder shall contain the temperature sensor information as SERVICE_DATA.
     */
    ble::AdvertisingDataBuilder addSensorData();
};

#endif
