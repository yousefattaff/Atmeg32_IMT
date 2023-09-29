#include "../../MCAL/DIO/DIO_int.h"
#include "steppermotor_int.h"




StepperM_tenuErrorStatus Stepper_Rotate(u32 Copy_u8Angle, u8 Copy_u8Direction, u16 Copy_u16TimeInMs)
{

    // Set the desired pins as OUTPUT
   if ( DIO_enuSetPinDirection(DIO_u8_PORTD, Coil_Blue, DIO_u8_OUTPUT) == DIO_OK &&
    DIO_enuSetPinDirection(DIO_u8_PORTD, Coil_Pink, DIO_u8_OUTPUT)== DIO_OK &&
    DIO_enuSetPinDirection(DIO_u8_PORTD, Coil_Yellow, DIO_u8_OUTPUT)== DIO_OK &&
    DIO_enuSetPinDirection(DIO_u8_PORTD, Coil_Orange, DIO_u8_OUTPUT) == DIO_OK )
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
	            Stepper_RotateCW();
	            delay_ms(Copy_u16StepDelay);

	        }
	    }
	    else if (Copy_u8Direction == STEPPER_u8_ACW)
	    {
	        for (u16 Local_u16Index = 0; Local_u16Index < Local_u16NumOfSteps; Local_u16Index++)
	        {
	            Stepper_RotateACW();
	            delay_ms(Copy_u16StepDelay);
	        }
	    }
	    return STEPPER_OK;
   }
   else
   {
	   return STEPPER_NOK;
   }


}

// This pattern represents one step in a clockwise direction
static void Stepper_RotateCW(void)
{
    // Step 1: Activate the Blue coil while keeping others off
    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    delay_ms(5); // Delay for motor stability

    // Step 2: Activate the Pink coil while keeping others off
    // This effectively rotates the stepper motor by one step in a clockwise direction
    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    delay_ms(5);

    // Step 3: Activate the Yellow coil while keeping others off
    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    delay_ms(5);

    // Step 4: Activate the Orange coil while keeping others off
    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_HIGH);
    delay_ms(5);

    // The above pattern represents one step in a clockwise direction
}

// This pattern represents one step in an anti-clockwise direction
static void Stepper_RotateACW(void)
{
    // Step 1: Activate the Orange coil while keeping others off
    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_HIGH);
    delay_ms(5);

    // Step 2: Activate the Pink coil while keeping others off
    // This effectively rotates the stepper motor by one step in an anti-clockwise direction
    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    delay_ms(5);

    // Step 3: Activate the Blue coil while keeping others off
    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_HIGH);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    delay_ms(5);

    // Step 4: Deactivate all coils
    DIO_enuSetPinValue(COIL_BLUE_PORT, Coil_Blue, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_PINK_PORT, Coil_Pink, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_YELLOW_PORT, Coil_Yellow, DIO_u8_LOW);
    DIO_enuSetPinValue(COIL_ORANGE_PORT, Coil_Orange, DIO_u8_LOW);
    delay_ms(5);

    // The above pattern represents one step in an anti-clockwise direction
}


