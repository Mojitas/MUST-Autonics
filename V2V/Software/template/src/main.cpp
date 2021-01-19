#include <mbed.h>
#include "sensor.h"

int main(void)
{
	sensor_info("Sens1");
	
	while (true)
	{
		sensor_info("Sens2");
		ThisThread::sleep_for(1s);
	}	
}
