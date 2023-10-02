#include "../../MCAL/DIO/DIO_int.h"
#include "steppermotor_int.h"
#include "avr/delay.h"




// This pattern represents one step in a clockwise direction
static void Stepper_RotateHalfStepCW(void)
{

    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);

    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);

  
    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);

    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_HIGH);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_HIGH);
    _delay_ms(5);
}





// This pattern represents one step in an anti-clockwise direction
static void Stepper_RotateHalfStepCCW(void)
{

    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_HIGH);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_HIGH);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    _delay_ms(5);


    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_HIGH);
    _delay_ms(5);
}



StepperM_tenuErrorStatus Stepper_Rotate(u32 Copy_u8Angle, u8 Copy_u8Direction, u16 Copy_u16TimeInMs)
{

    // Set the desired pins as OUTPUT
   if ( DIO_enuSetPinDirection(COIL_BLUE_PORT, Coil_Blue, DIO_u8_OUTPUT) == DIO_OK &&
    DIO_enuSetPinDirection(COIL_PINK_PORT, Coil_Pink, DIO_u8_OUTPUT)== DIO_OK &&
    DIO_enuSetPinDirection(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_OUTPUT)== DIO_OK &&
    DIO_enuSetPinDirection(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_OUTPUT) == DIO_OK )
   {
	    // Calculate the number of steps needed based on the desired angle
	    // Lookup data sheet for more information on the number of coils in the stepper motor
	    f32 Local_f32SingleStep = 360 / (COIL_NUM * 1.0);
	    u16 Local_u16NumOfSteps = (u16)(Copy_u8Angle / Local_f32SingleStep);

	    // Calculate the delay between steps based on the desired rotation time
	    u16 Copy_u16StepDelay = Copy_u16TimeInMs / Local_u16NumOfSteps;

	    // Call the appropriate rotation function based on direction
	    if (Copy_u8Direction == STEPPER_u8_CW)
	    {
	        for (u16 Local_u16Index = 0; Local_u16Index < Local_u16NumOfSteps; Local_u16Index++)
	        {
	        	Stepper_RotateHalfStepCW();
	            _delay_ms(Copy_u16StepDelay);

	        }
	    }
	    else if (Copy_u8Direction == STEPPER_u8_ACW)
	    {
	        for (u16 Local_u16Index = 0; Local_u16Index < Local_u16NumOfSteps; Local_u16Index++)
	        {
	        	Stepper_RotateHalfStepCCW();
	            _delay_ms(Copy_u16StepDelay);
	        }
	    }
	    return STEPPER_OK;
   }
   else
   {
	   return STEPPER_NOK;
   }


}




