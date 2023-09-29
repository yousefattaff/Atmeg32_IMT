#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/Seven_Segment/Seven_Segment_int.h"
#include "../HAL/LED/LED_int.h"
#include "segm2.h" // file was deleted will restore or modify the seven seg driver for better use
int main (void)
{
	DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN0,
			DIO_u8_OUTPUT);//red
	DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN1,
			DIO_u8_OUTPUT);//yellow
	DIO_enuSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN2,
				DIO_u8_OUTPUT);//green
	SevenSegment_enuInit();
while(1)
{

		for (u8 i = 1; i <= 10; i++)
		{
			LED_enuturnOnLED(DIO_u8_PORTA, DIO_u8_PIN2);
			if (i == 10)
			{
				i=1;
				u8 j =0;
				SevenSegment_enuDisplayDigit(i);
				Segm2_enuInit();
				Segm2_enuDisplayDigit(j);
				LED_enuturnOffLED(DIO_u8_PORTA, DIO_u8_PIN2);
				break;
			}
			SevenSegment_enuDisplayDigit(i);
			_delay_ms(1000);

		}
		for (u8 i = 1; i <= 3; i++)
		{
			LED_enuturnOnLED(DIO_u8_PORTA, DIO_u8_PIN1);
			SevenSegment_enuDisplayDigit(i);
			_delay_ms(1000);
			if (i == 3)
			{
				LED_enuturnOffLED(DIO_u8_PORTA, DIO_u8_PIN1);
				break;
			}


		}
			for (u8 i = 1; i <= 10; i++)
			{
				LED_enuturnOnLED(DIO_u8_PORTA, DIO_u8_PIN0);
				if (i == 10)
				{
					i=1;
					u8 j =0;
					SevenSegment_enuDisplayDigit(i);
					Segm2_enuInit();
					Segm2_enuDisplayDigit(j);
					LED_enuturnOffLED(DIO_u8_PORTA, DIO_u8_PIN0);
					break;
				}
				SevenSegment_enuDisplayDigit(i);
				_delay_ms(1000);

			}
}
}
