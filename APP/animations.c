#include "../HAL/Switches/switches_int.h"
#include "../HAL/LED/LED_int.h"
#include "../MCAL/DIO/DIO_int.h"

int main (void)
{
	for (u8 i = 0; i <= 7; i++)
	{
		DIO_enuSetPinDirection(DIO_u8_PORTA, i, DIO_u8_OUTPUT);
	}
	for (u8 i = 0; i <= 7; i++)
	{
		SetSwitch(DIO_u8_PORTB, i);
	}
	while(1)
	{
		//Flashing
		if (IsSwitchPressed(DIO_u8_PORTB, DIO_u8_PIN0) == SWITCH_PRESSED)
		    {
		        for (u8 i = 0; i <= 7; i++)
		        {
		            LED_enuturnOnLED(DIO_u8_PORTA, i);
		        }
		        _delay_ms(500);
		        for (u8 i = 0; i <= 7; i++)
		        {
		            LED_enuturnOffLED(DIO_u8_PORTA, i);
		        }
		        _delay_ms(500);
		    }
		//Shift left
		else if (IsSwitchPressed(DIO_u8_PORTB, DIO_u8_PIN1) == SWITCH_PRESSED)
		{

		    for (u8 j = 0; j <= 7; j++)
		    {
		        LED_enuturnOnLED(DIO_u8_PORTA, j);
		        _delay_ms(250);
		        LED_enuturnOffLED(DIO_u8_PORTA, j);
		        _delay_ms(250);
		    }
		}
		//Shift right
		else if (IsSwitchPressed(DIO_u8_PORTB, DIO_u8_PIN2) == SWITCH_PRESSED)
		{

			for (u8 j = 7; j >= 0; j--)
			{
				 LED_enuturnOnLED(DIO_u8_PORTA, j);
				 _delay_ms(250);
				 LED_enuturnOffLED(DIO_u8_PORTA, j);
				 _delay_ms(250);

			}

		}
		//Converging
		else if (IsSwitchPressed(DIO_u8_PORTB, DIO_u8_PIN3) == SWITCH_PRESSED)
		{
			u8 j = 0;
			u8 i = 7;
			for (u8 k = 0; k <= 3; k++)
			{
				LED_enuturnOnLED(DIO_u8_PORTA, j);
				LED_enuturnOnLED(DIO_u8_PORTA, j+1);
				LED_enuturnOnLED(DIO_u8_PORTA, i);
				LED_enuturnOnLED(DIO_u8_PORTA, i-1);
				_delay_ms(300);
				LED_enuturnOffLED(DIO_u8_PORTA, j);
				LED_enuturnOffLED(DIO_u8_PORTA, j+1);
				LED_enuturnOffLED(DIO_u8_PORTA, i);
				LED_enuturnOffLED(DIO_u8_PORTA, i-1);
				_delay_ms(300);
				j++;
				i--;
			}

		}
		//Diverging
		else if (IsSwitchPressed(DIO_u8_PORTB, DIO_u8_PIN4) == SWITCH_PRESSED)
		{
			u8 j = 3;
			u8 i = 4;
			for (u8 k = 0; k <= 3; k++)
			{
				LED_enuturnOnLED(DIO_u8_PORTA, j);
				LED_enuturnOnLED(DIO_u8_PORTA, j+1);
				LED_enuturnOnLED(DIO_u8_PORTA, i);
				LED_enuturnOnLED(DIO_u8_PORTA, i-1);
				_delay_ms(300);
				LED_enuturnOffLED(DIO_u8_PORTA, j);
				LED_enuturnOffLED(DIO_u8_PORTA, j+1);
				LED_enuturnOffLED(DIO_u8_PORTA, i);
				LED_enuturnOffLED(DIO_u8_PORTA, i-1);
				_delay_ms(300);
				j++;
				i--;
			}

		}
		//Ping Pong
		else if (IsSwitchPressed(DIO_u8_PORTB, DIO_u8_PIN5) == SWITCH_PRESSED)
		{

			for (u8 j = 0; j <= 7; j++)
			{
		        LED_enuturnOnLED(DIO_u8_PORTA, j);
		        _delay_ms(250);
		        LED_enuturnOffLED(DIO_u8_PORTA, j);
		        _delay_ms(250);
			}
			for (u8 j = 6; j > 0; j--)
			{
		        LED_enuturnOnLED(DIO_u8_PORTA, j);
		        _delay_ms(250);
		        LED_enuturnOffLED(DIO_u8_PORTA, j);
		        _delay_ms(250);
			}

		}
		//Snake Effect
		else if (IsSwitchPressed(DIO_u8_PORTB, DIO_u8_PIN6) == SWITCH_PRESSED)
		{

			for (u8 j = 0; j <= 7; j++)
			{
		        LED_enuturnOnLED(DIO_u8_PORTA, j);
		        _delay_ms(300);

			}
			for (u8 j = 0; j <= 7; j++)
			{
		        LED_enuturnOffLED(DIO_u8_PORTA, j);
		        _delay_ms(150);

			}

		}
		//2 leds converging diverging at the same time
		else if (IsSwitchPressed(DIO_u8_PORTB, DIO_u8_PIN7) == SWITCH_PRESSED)
		{
			u8 j = 0;
			u8 i = 7;
			for (u8 k = 0; k <= 3; k++)
			{
				LED_enuturnOnLED(DIO_u8_PORTA, j);
				LED_enuturnOnLED(DIO_u8_PORTA, j+1);
				LED_enuturnOnLED(DIO_u8_PORTA, i);
				LED_enuturnOnLED(DIO_u8_PORTA, i-1);
				_delay_ms(300);
				LED_enuturnOffLED(DIO_u8_PORTA, j);
				LED_enuturnOffLED(DIO_u8_PORTA, j+1);
				LED_enuturnOffLED(DIO_u8_PORTA, i);
				LED_enuturnOffLED(DIO_u8_PORTA, i-1);
				_delay_ms(300);
				j++;
				i--;
			}
			u8 m = 3;
			u8 y = 4;
			for (u8 k = 0; k <= 3; k++)
			{
				LED_enuturnOnLED(DIO_u8_PORTA, m);
				LED_enuturnOnLED(DIO_u8_PORTA, m+1);
				LED_enuturnOnLED(DIO_u8_PORTA, y);
				LED_enuturnOnLED(DIO_u8_PORTA, y-1);
				_delay_ms(300);
				LED_enuturnOffLED(DIO_u8_PORTA, m);
				LED_enuturnOffLED(DIO_u8_PORTA, m+1);
				LED_enuturnOffLED(DIO_u8_PORTA, y);
				LED_enuturnOffLED(DIO_u8_PORTA, y-1);
				_delay_ms(300);
				m++;
				y--;
			}
		}



	}

}






