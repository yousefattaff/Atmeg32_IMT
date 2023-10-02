#include "../HAL/StepperMotor/steppermotor_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/Switches/switches_int.h"

int main (void)
{

	SetSwitch(0,0);
	SetSwitch(0,1);
	LCD_enuInitialize();
	u8 name [] = "CLOCKWISE";
	u8 name2 [] = "ANTICLOCKWISE";
	while(1)
	{

		if(IsSwitchPressed(0,0) == SWITCH_PRESSED)
		{
			LCD_vidSendStr(name);
			Stepper_Rotate(90, 0, 0);
			LCD_enuSendInstruction(CLRSCR);

		}
		else if(IsSwitchPressed(0,1) == SWITCH_PRESSED)
		{
			LCD_vidSendStr(name2);
			Stepper_Rotate(90, 1, 0);
			LCD_enuSendInstruction(CLRSCR);
		}

	}

}

