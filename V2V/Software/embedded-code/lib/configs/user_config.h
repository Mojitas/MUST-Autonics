#ifndef __USER_CONFIG_H
#define __USER_CONFIG_H

/**
 * OTHER_NAME is the name of the device that is searching/advertising
 * while DEVICE_NAME is the name itself. Depending on device these
 * need to be switched just like the DEVICE_SCANNER definition below
 */
#define   OWN_DEVICE_NAME                 "MUST_SENDER"
#define   PEER_DEVICE_NAME                "MUST_RECEIVER"
#define   DEVICE_NAME                     PEER_DEVICE_NAME
#define   OTHER_NAME                      OWN_DEVICE_NAME

/**
 * If you don't want to write to SDCard then comment the row below
 */
#define MY_SD_DEFINITION

/**
 * Baudrate used for serial communication with PC
 */
#define   BAUDRATE_USER_SETTING           115200

/**
 * Defines the advertising 
 */
#define   MAX_ADVERTISING_PAYLOAD_SIZE    50

/*
 * Set to false when DEVICE_NAME is MUST_SENDER.
 * Set to true when DEVICE_NAME is MUST_RECEIVER
 */
#define   DEVICE_SCANNER                  false

#endif
