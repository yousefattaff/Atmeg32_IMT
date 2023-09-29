#include "LED_int.h"


LED_tenuErrorStatus LED_enuturnOnLED(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    // Check if the port and pin IDs are valid
    if (Copy_u8PortId <= LCD_u8_MAXPORTS && Copy_u8PinId <= LCD_u8_MAXPINS)
    {


            // Set the pin value to HIGH to turn on the LED
            if (DIO_enuSetPinValue(Copy_u8PortId, Copy_u8PinId, DIO_u8_HIGH) == DIO_OK)
            {
                return LED_OK;
            }
            else
            {
                // Error: Failed to set the pin value
                return LED_NOK;

            }
    }
    else
    {
        // Error: Invalid port or pin ID
        return LED_NOK;
    }
}

LED_tenuErrorStatus LED_enuturnOffLED(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    // Check if the port and pin IDs are valid
    if (Copy_u8PortId <= LCD_u8_MAXPORTS && Copy_u8PinId <= LCD_u8_MAXPINS)
    {

            // Set the pin value to LOW to turn off the LED
            if (DIO_enuSetPinValue(Copy_u8PortId, Copy_u8PinId, DIO_u8_LOW) == DIO_OK)
            {
                return LED_OK;
            }
            else
            {
                // Error: Failed to set the pin value
                return LED_NOK;
            }
    }
    else
    {
        // Error: Invalid port or pin ID
        return LED_NOK;
    }
}


LED_tenuErrorStatus LED_enuBlink(u8 Copy_u8PortId, u8 Copy_u8PinId, u32 Copy_u8Sec)
{
    // Check if turning on the LED is successful
    if (LED_enuturnOnLED(Copy_u8PortId, Copy_u8PinId) == LED_OK)
    {
        _delay_ms(Copy_u8Sec);
        // Turn off the LED
        if (LED_enuturnOffLED(Copy_u8PortId, Copy_u8PinId) == LED_OK)
        {
        	_delay_ms(Copy_u8Sec);
            return LED_OK;
        }
        else
        {
            // Error: Failed to turn off the LED
            return LED_NOK;
        }
    }
    else
    {
        // Error: Failed to turn on the LED
        return LED_NOK;
    }
}


