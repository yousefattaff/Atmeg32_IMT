#include <avr/io.h>
#include <util/delay.h>
#include "../HAL/Switches/switches_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LED/LED_Driver_int.h"

int main()
{
	SetSwitch(DIO_u8_PORTA, DIO_u8_PIN0);
	while(1)
	{
		if (IsSwitchPressed(DIO_u8_PORTA, DIO_u8_PIN0) == SWITCH_PRESSED)
		{
			LED_enuturnOnLED(DIO_u8_PORTA, DIO_u8_PIN1);
		}
		else if (IsSwitchPressed(DIO_u8_PORTA, DIO_u8_PIN0) == SWITCH_NOTPRESSED)
		{
			LED_enuturnOffLED(DIO_u8_PORTA, DIO_u8_PIN1);
		}
	}
    return 0;
}
