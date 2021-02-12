#ifndef __USER_CONFIG_H
#define __USER_CONFIG_H

#define   OWN_DEVICE_NAME                 "MUST_SENDER"
#define   PEER_DEVICE_NAME                "MUST_RECEIVER"
#define   DEVICE_NAME                     PEER_DEVICE_NAME

/**
 * Baudrate used for serial communication with PC
 */
#define   BAUDRATE_USER_SETTING           115200

/**
 * Defines the advertising 
 */
#define   MAX_ADVERTISING_PAYLOAD_SIZE    50

/*
 * Set to false when DEVICE_NAME is MUST_RECEIVER.
 * Set to true when DEVICE_NAME is MUST_SENDER
 */
#define   DEVICE_SCANNER                  true

#endif
