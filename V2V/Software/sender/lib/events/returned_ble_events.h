#ifndef __RETURNED_BLE_EVENTS_H
#define __RETURNED_BLE_EVENTS_H
#include "user_headers.h"

/*!
 * \file returned_ble_events.h
 * \brief Implements the events in that the event handler in the gap module has
 * \details Selected events from the Gap EventHandler will have headers in this file and
 * implemented in its corresponding cpp-file namely returned_ble_events.cpp. The functions
 * will be described here and grouped together in the documentation to easier find them and
 * to know which functions are together.
 */
/*!
 * \class CretEvents returned_ble_events.h
 * \brief Class that handles the ble events that are triggered when starting advertising for example.
 */
class CretEvents : private mbed::NonCopyable<CretEvents>, public ble::Gap::EventHandler {
  public:
    /*!
     * \fn CretEvents()
     * \brief Constructor for the event handler class for ble events
     */
    CretEvents(BLE &ble);
    /*!
     * \fn virtual ~CretEvents()
     * \brief Destructor for the event handler class for ble events
     */
    virtual ~CretEvents();
  public:
    /*!
     * \addtogroup advertising
     * @{
     */
    /*!
     * \fn void CretEvents::onAdvertisingStart(const ble::AdvertisingStartEvent &event)
     * \brief Used when advertising starts
     * \details Implements the event that is triggered when advertising starts on the BLE device
     * \pre BLE is initialized
     */
    void onAdvertisingStart(const ble::AdvertisingStartEvent &event);
    /*!
     * \fn void CretEvents::onAdvertisingEnd(const ble::AdvertisingEndEvent &event)
     * \brief Used when advertising ends
     * \details Implements the event that is triggered when advertising ends
     * \pre BLE is initialized
     */
    void onAdvertisingEnd(const ble::AdvertisingEndEvent &event);
    /*!
     * \fn void CretEvents::onAdvertisingReport(const ble::AdvertisingReportEvent &event)
     * \brief Used when a report of the advertisement is available
     * \details Implements the event that is triggered and reports how the advertisement goes
     * \pre BLE is initialized
     */
    void onAdvertisingReport(const ble::AdvertisingReportEvent &event);
    /*!
     * @}
     */

  private:
    BLE &_ble;
    Gap &_gap;
};


#endif
