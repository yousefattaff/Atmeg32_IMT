#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/DcMotor/DcMotor_int.h"
#include "../HAL/Switches/switches_int.h"
#include "../HAL/LCD/LCD_int.h"

int main (void)
{
	LCD_enuInitialize();
	for (u8 i = 0; i <= 3; i++)
	{
		SetSwitch(DIO_u8_PORTD, i);
	}
	DcMotor_Init();
	while(1)
	{
		if (IsSwitchPressed(DIO_u8_PORTD, 0) == SWITCH_PRESSED )
		{
			LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
			DcMotor_SetDirection(CLOCKWISE);
			LCD_voidGotoXY(1, 0);
			LCD_vidSendStr("The Direction is: ");
			LCD_voidGotoXY(2, 0);
			LCD_vidSendStr("CLOCKWISE.");
		}
		else if (IsSwitchPressed(DIO_u8_PORTD, 1) == SWITCH_PRESSED)
		{
			LCD_enuSendInstruction(LCD_u8_CLEAR_DISPLAY);
			DcMotor_SetDirection(ANTICLOCKWISE);
			LCD_voidGotoXY(1, 0);
			LCD_vidSendStr("The Direction is: ");
			LCD_voidGotoXY(2, 0);
			LCD_vidSendStr("ANTICLOCKWISE.");
		}
	}

}
