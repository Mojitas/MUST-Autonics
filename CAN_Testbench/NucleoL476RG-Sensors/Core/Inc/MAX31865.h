#ifndef _MAX31865_H

#define MAX31865_FAULT_HIGHTHRESH       0x80
#define MAX31865_FAULT_LOWTHRESH        0x40
#define MAX31865_FAULT_REFINLOW         0x20
#define MAX31865_FAULT_REFINHIGH        0x10
#define MAX31865_FAULT_RTDINLOW         0x08
#define MAX31865_FAULT_OVUV             0x04

#define _MAX31865_H

/*
  Author:     Nima Askari
  WebSite:    http://www.github.com/NimaLTD
  Instagram:  http://instagram.com/github.NimaLTD
  Youtube:    https://www.youtube.com/channel/UCUhY7qY1klJm1d2kulr9ckw

  Version:    1.0.0


  Reversion History:

  (1.0.0)
  First Release.

 */

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"
#include <stdbool.h>
//#########################################################################################################################
typedef struct
{
	GPIO_TypeDef      *cs_gpio;
	uint16_t          cs_pin;
	SPI_HandleTypeDef *spi;
	uint8_t           lock;

}Max31865_t;
//#########################################################################################################################
void  Max31865_init(Max31865_t *max31865,SPI_HandleTypeDef *spi,GPIO_TypeDef  *cs_gpio,uint16_t cs_pin,uint8_t  numwires, uint8_t filterHz);
uint8_t  Max31865_readTempC(Max31865_t *max31865, float *readTemp);
bool  Max31865_readTempF(Max31865_t *max31865, float *readTemp);
float Max31865_Filter(float	newInput, float	lastOutput, float efectiveFactor);
int16_t Max31865_faultToString(uint8_t faultCode, char* faultString);
//#########################################################################################################################
#ifdef __cplusplus
}
#endif



#endif
