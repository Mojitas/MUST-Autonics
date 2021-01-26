#ifndef __USER_CONFIG_H
#define __USER_CONFIG_H

/*!
 * \file user_config.h
 */

/*!
 * \addtogroup Names
 * @{
 */

/*!
 * \def NAME_RECEIVER
 * \brief The name of the receiving device
 */
#ifndef NAME_RECEIVER
#define NAME_RECEIVER	"SolarTeamReceiver"
#endif

/*!
 * \def NAME_SENDER
 * \brief The name of the sending device
 */
#ifndef NAME_SENDER
#define NAME_SENDER	  "SolarTeamSender"
#endif

/*!
 * \def DEVICE_NAME
 * \par
 * Define the name of the sender and the receiver
 * The reciever is the name which the sender will
 * be looking for and the sender name is the name
 * that the receiver will be looking for.
 */
#ifndef DEVICE_NAME
#define	DEVICE_NAME	  NAME_RECEIVER
#endif

/*!
 * @}
 */

/*!
 * \addtogroup Priorities
 * @{
 */
/*!
 * \def PKG_PRIO_LOW
 * \brief The lowest priority for a package that will be advertised with BLE
 */
#ifndef PKG_PRIO_LOW
#define PKG_PRIO_LOW	2
#endif

/*!
 * \def PKG_PRIO_MED
 * \brief Medium priority for a package that will be advertised with BLE
 */
#ifndef PKG_PRIO_MED
#define PKG_PRIO_MED	4
#endif

/*!
 * \def PKG_PRIO_HIGH
 * \brief The highest priority, information from e.g. battery like error messages will be sent here
 */
#ifndef PKG_PRIO_HIGH
#define PKG_PRIO_HIGH	6
#endif

/*!
 * @}
 */

/*!
 * \addtogroup Messages
 * @{
 */
/*!
 * \def QSIZE
 * \par
 * For the communication we use a priority
 * queue, this is the defined size for the
 * priority queue. There is also a type of
 * message that the queue holds that is
 * defined here.
 */
#ifndef QSIZE
#define QSIZE 		    32
#endif

/*!
 * \struct message_t
 * \brief A message struct for the mbed::Queue
 * \typedef struct
 * \var voltage
 * \var current
 * \var counter
 */
typedef struct
{
	float voltage;
	float current;
	uint32_t counter;
} message_t;

/*!
 * @}
 */

/*!
 * \addtogroup Status
 * @{
 * 
 * \par
 * Define blinking rates for each of the
 * leds that exist on the board, different
 * rate means different things
 * For example:
 * LED1 blinking at 500ms could mean its scanning
 * for BLE device. LED2 lit up could mean its 
 * connected to a BLE device.
 * Blink rate for led1 is identified with
 * BLINK_RATE_1, for each LED not defined
 * the light will be static, could also be
 * static on a defined light once an event
 * is over, example event include connecting
 * to a device.
 */
/*!
 * \def BLINK_RATE_1
 * \brief How fast LED 1 is going to blink
 */
#ifndef BLINK_RATE_1
#define BLINK_RATE_1  500ms
#endif

/*!
 * \def BLINK_RATE_2
 * \brief How fast LED 2 is going to blink
 */
#ifndef BLINK_RATE_2
#define BLINK_RATE_2  250ms
#endif

/*!
 * \def BLINK_RATE_3
 * \brief How fast LED 3 is going to blink.
 */
#ifndef BLINK_RATE_3
#define BLINK_RATE_3  300ms
#endif

/*!
 * @}
 */
#endif // __USER_CONFIG_H
