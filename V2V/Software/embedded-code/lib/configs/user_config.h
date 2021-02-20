#ifndef __USER_CONFIG_H
#define __USER_CONFIG_H

/**
 * @file user_config.h
 * @brief Configuration file for the different features and names of devices for
 */

/**
 * @addtogroup Definitions
 * @brief A group for the names of the devices.
 * @{
 */
/**
 * @def OWN_DEVICE_NAME
 * @brief A name of a device
 */
#define   OWN_DEVICE_NAME                 "MUST_SENDER"
/**
 * @def PEER_DEVICE_NAME
 * @brief The name of another device
 */
#define   PEER_DEVICE_NAME                "MUST_RECEIVER"
/**
 * @def DEVICE_NAME
 * @brief
 * The name of the device that is currently being used.
 * Set it to PEER_DEVICE_NAME if we are developing for
 * that, otherwise set it to OWN_DEVICE_NAME.
 */
#define   DEVICE_NAME                     PEER_DEVICE_NAME
/**
 * @def OTHER_NAME
 * @brief
 * The name of the device that is currently not being
 * programmed for, change to OWN_DEVICE_NAME if the
 * device developed for is PEER_DEVICE_NAME and the
 * other way around.
 */
#define   OTHER_NAME                      OWN_DEVICE_NAME
/**
 * @}
 */

/**
 * @def MY_SD_DEFINITION
 * @brief
 * Controls the parts of the code that writes messages
 * onto an SD Card.
 */
#define MY_SD_DEFINITION

/**
 * @def BAUDRATE_USER_SETTNG
 * @brief
 * Baudrate used for serial communication with PC
 */
#define   BAUDRATE_USER_SETTING           115200

/**
 * @def MAX_ADVERTISING_PAYLOAD_SIZE
 * @brief
 * Defines the advertising payloads maximum size
 */
#define   MAX_ADVERTISING_PAYLOAD_SIZE    50


/**
 * @def DEVICE_SCANNER
 * @brief
 * Set to false if DEVICE_NAME is PEER_DEVICE_NAME,
 * true otherwise.
 */
#define   DEVICE_SCANNER                  false

#endif
