#include "switches_int.h"


Switches_enuSwitchStatues IsSwitchPressed(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    u8 *Local_u8SwitchValue ;
    if (DIO_enuGetPinValue(Copy_u8PortId, Copy_u8PinId, Local_u8SwitchValue) == DIO_OK)
    {
    	 if (*Local_u8SwitchValue == DIO_u8_LOW)
    	 {
    		  return SWITCH_PRESSED;
    	 }
    	 else
    	 {
    		 return SWITCH_NOTPRESSED;
    	 }
    }
    else
    {
    	return SWITCH_DIO_NOK;
    }

}

Switches_enuSwitchStatues IsSwitchNotPressed(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 * Local_u8SwitchValue   ;
	    if (DIO_enuGetPinValue(Copy_u8PortId, Copy_u8PinId, Local_u8SwitchValue) == DIO_OK)
	    {
	    	 if (*Local_u8SwitchValue == DIO_u8_HIGH)
	    	 {
	    		  return SWITCH_NOTPRESSED;
	    	 }
	    	 else
	    	 {
	    		 return SWITCH_PRESSED;
	    	 }
	    }
	    else
	    {
	    	return SWITCH_DIO_NOK;
	    }
}


Switches_enuSwitchStatues SetSwitch(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    if (DIO_enuSetPinDirection(Copy_u8PortId, Copy_u8PinId, DIO_u8_INPUT) == DIO_OK && DIO_enuSetPinValue(Copy_u8PortId, Copy_u8PinId, DIO_u8_HIGH) == DIO_OK)
    {
        return SWITCH_DIO_OK;
    }
    else
    {
        return SWITCH_DIO_NOK;
    }
}
