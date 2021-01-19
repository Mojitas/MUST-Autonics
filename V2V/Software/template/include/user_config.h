#ifndef __USER_CONFIG_H
#define __USER_CONFIG_H

/*
 * Define the name of the sender and the receiver
 * The reciever is the name which the sender will
 * be looking for and the sender name is the name
 * that the receiver will be looking for.
 */
#ifndef NAME_RECEIVER
#define NAME_RECEIVER	"SolarTeamReceiver"
#endif

#ifndef NAME_SENDER
#define NAME_SENDER	  "SolarTeamSender"
#endif

#ifndef DEVICE_NAME
#define	DEVICE_NAME	  NAME_SENDER
#endif

/*
 * Define package priorities for the priority
 * queues that will be used when sending data
 * over to the follow car.
 */
#ifndef PKG_PRIO_LOW
#define PKG_PRIO_LOW	2
#endif

#ifndef PKG_PRIO_MED
#define PKG_PRIO_MED	4
#endif

#ifndef PKG_PRIO_HIGH
#define PKG_PRIO_HIGH	6
#endif

/*
 * For the communication we use a priority
 * queue, this is the defined size for the
 * priority queue. There is also a type of
 * message that the queue holds that is
 * defined here.
 */
#ifndef QSIZE
#define QSIZE 		    32
#endif

typedef struct
{
	float voltage;
	float current;
	uint32_t counter;
} message_t;

/*
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
#ifndef BLINK_RATE_1
#define BLINK_RATE_1  500ms
#endif

#ifndef BLINK_RATE_2
#define BLINK_RATE_2  250ms
#endif

#ifndef BLINK_RATE_3
#define BLINK_RATE_3  300ms
#endif

#endif // __USER_CONFIG_H
