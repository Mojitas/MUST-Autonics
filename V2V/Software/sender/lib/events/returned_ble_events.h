#ifndef __RETURNED_BLE_EVENTS_H
#define __RETURNED_BLE_EVENTS_H
#include "user_headers.h"
#include "ble_conn.h"
#include "extra_functions.h"

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
 * \details
 * Has the Advertiser class as implementation so that it can access its functions and objects, that way we can tell it that this class is the event handler and still access the same functions from the advertiser class.
 * However, the super class has to be initialized before using it or running the application. That way when we create this class, it will automatically initialize its super class so that we can run the application.
 * On running the application it will set the event handler to this class so we can control what happens when the different events fire. We can also access the super class functions and queue them for calling, depending on what event got triggered.
 */
class CretEvents : private mbed::NonCopyable<CretEvents>, public Advertiser, public ble::Gap::EventHandler {
  public:
    /*!
     * \fn CretEvents(BLE &ble)
     * \brief Constructor for the event handler class for ble events
     */
    CretEvents(BLE &ble);
    /*!
     * \fn virtual ~CretEvents()
     * \brief Destructor for the event handler class for ble events
     */
    virtual ~CretEvents();
    /*!
     * \fn void run()
     * \brief Sets the event handler to this class and runs the advertising super class. It's also the entry point when starting the application.
     */
    void run();
    /*!
     */
    BLE &getBleVariable();

  public:
    /*!
     * \addtogroup advertising
     * @{
     */
    /*!
     * \fn void CretEvents::onAdvertisingStart(const ble::AdvertisingStartEvent &event)
     * \brief Used when advertising starts
     */
    void onAdvertisingStart(const ble::AdvertisingStartEvent &event) override;
    /*!
     * \fn void CretEvents::onAdvertisingEnd(const ble::AdvertisingEndEvent &event)
     * \brief Used when advertising ends
     */
    void onAdvertisingEnd(const ble::AdvertisingEndEvent &event) override;
    /*!
     * \fn void CretEvents::onAdvertisingReport(const ble::AdvertisingReportEvent &event)
     * \brief Used when a report of the advertisement is available
     */
    void onAdvertisingReport(const ble::AdvertisingReportEvent &event) override;
    /*!
     * @}
     */
    /*!
     * \addtogroup connection
     * @{
     */
    /*!
     * \fn void onConnectionComplete(ConnectionCompleteEvent &event)
     */
    void onConnectionComplete(const ble::ConnectionCompleteEvent &event) override;
    /*!
     * @}
     */
};


#endif
