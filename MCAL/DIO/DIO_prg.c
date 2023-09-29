/*

 *
 * Yousef-Alsayed-Abdelfattah
 *
 */
#include "bits.h"
#include "data_types.h"
#include "../DIO/DIO_int.h"
#include "../DIO/DIO_prv.h"

DIO_tenuErrorStatus DIO_enuSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{
    DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;

    // Check if the inputs are within valid ranges.
    if (Copy_u8PortId > DIO_u8_PORTD || Copy_u8PinId > DIO_u8_PIN7 || Copy_u8Direction > DIO_u8_OUTPUT)
    {
        Local_enuErrorStatus = DIO_NOK;
    }
    else
    {
        // Set or clear the specific bit in the port's data direction register (DDRx)
        // based on the desired direction.
        switch (Copy_u8PortId)
        {
            case DIO_u8_PORTA:
                assign_bit(DIO_u8_DDRA_REG, Copy_u8PinId, Copy_u8Direction );
                break;
            case DIO_u8_PORTB:
                assign_bit(DIO_u8_DDRB_REG, Copy_u8PinId, Copy_u8Direction );
                break;
            case DIO_u8_PORTC:
                assign_bit(DIO_u8_DDRC_REG, Copy_u8PinId, Copy_u8Direction );
                break;
            case DIO_u8_PORTD:
                assign_bit(DIO_u8_DDRD_REG, Copy_u8PinId, Copy_u8Direction );
                break;
        }
    }

    return Local_enuErrorStatus;
}


DIO_tenuErrorStatus DIO_enuSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{
  DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;

  // Check if the inputs are within valid ranges.
  if ((Copy_u8PortId > DIO_u8_PORTD) || (Copy_u8Direction > DIO_u8_OUTPUT))
  {
    Local_enuErrorStatus = DIO_NOK;
  }
  else
  {
    // Set or clear all bits in the port's data direction register (DDRx)
    // based on the desired direction.
    switch (Copy_u8PortId)
    {
    case DIO_u8_PORTA:
      (Copy_u8Direction == DIO_u8_OUTPUT) ? SET_REG(DIO_u8_DDRA_REG) : CLR_REG(DIO_u8_DDRA_REG);
      break;
    case DIO_u8_PORTB:
      (Copy_u8Direction == DIO_u8_OUTPUT) ? SET_REG(DIO_u8_DDRB_REG) : CLR_REG(DIO_u8_DDRB_REG);
      break;
    case DIO_u8_PORTC:
      (Copy_u8Direction == DIO_u8_OUTPUT) ? SET_REG(DIO_u8_DDRC_REG) : CLR_REG(DIO_u8_DDRC_REG);
      break;
    case DIO_u8_PORTD:
      (Copy_u8Direction == DIO_u8_OUTPUT) ? SET_REG(DIO_u8_DDRD_REG) : CLR_REG(DIO_u8_DDRD_REG);
      break;
    }
  }
  return Local_enuErrorStatus;
}


DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
	 DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;

	    // Check if the inputs are within valid ranges.
	    if (Copy_u8PortId > DIO_u8_PORTD || Copy_u8PinId > DIO_u8_PIN7 || Copy_u8Value > DIO_u8_HIGH)
	    {
	        Local_enuErrorStatus = DIO_NOK;
	    }
	    else
	    {
	        // Set or clear the specific bit in the port's data direction register (DDRx)
	        // based on the desired direction.
	        switch (Copy_u8PortId)
	        {
	            case DIO_u8_PORTA:
	                assign_bit(DIO_u8_PORTA_REG, Copy_u8PinId, Copy_u8Value);
	                break;
	            case DIO_u8_PORTB:
	                assign_bit(DIO_u8_PORTB_REG, Copy_u8PinId, Copy_u8Value);
	                break;
	            case DIO_u8_PORTC:
	                assign_bit(DIO_u8_PORTC_REG, Copy_u8PinId, Copy_u8Value);
	                break;
	            case DIO_u8_PORTD:
	                assign_bit(DIO_u8_PORTD_REG, Copy_u8PinId, Copy_u8Value);
	                break;
	        }
	    }

	    return Local_enuErrorStatus;
}


DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{
  DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
  // Check if the inputs are within valid ranges.
  if ((Copy_u8PortId > DIO_u8_PORTD) || (Copy_u8Value > DIO_u8_HIGH))
  {
    Local_enuErrorStatus = DIO_NOK;
  }
  else
  {
    // Set or clear all bits in the port's data register (PORTx)
    // based on the desired value.
    switch (Copy_u8PortId)
    {
    case DIO_u8_PORTA:
      (Copy_u8Value == DIO_u8_HIGH) ? SET_REG(DIO_u8_PORTA_REG) : CLR_REG(DIO_u8_PORTA_REG);
      break;
    case DIO_u8_PORTB:
      (Copy_u8Value == DIO_u8_HIGH) ? SET_REG(DIO_u8_PORTB_REG) : CLR_REG(DIO_u8_PORTB_REG);
      break;
    case DIO_u8_PORTC:
      (Copy_u8Value == DIO_u8_HIGH) ? SET_REG(DIO_u8_PORTC_REG) : CLR_REG(DIO_u8_PORTC_REG);
      break;
    case DIO_u8_PORTD:
      (Copy_u8Value == DIO_u8_HIGH) ? SET_REG(DIO_u8_PORTD_REG) : CLR_REG(DIO_u8_PORTD_REG);
      break;
    }
  }
  return Local_enuErrorStatus;
}


DIO_tenuErrorStatus DIO_enuGetPinValue(
    u8 Copy_u8PortId,
    u8 Copy_u8PinId,
    u8 *Add_pu8Value)
{
  DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
  // Check if the inputs are within valid ranges.
  if (
      (Copy_u8PortId > DIO_u8_PORTD) ||
      (Copy_u8PinId > DIO_u8_PIN7) ||
      (Add_pu8Value == NULL))
  {
    Local_enuErrorStatus = DIO_NOK;
  }
  else
  {
    // Read the value of the specific pin from the port's input register (PINx).
    switch (Copy_u8PortId)
    {
    case DIO_u8_PORTA:
      *Add_pu8Value = GET_BIT(DIO_u8_PINA_REG, Copy_u8PinId);
      break;
    case DIO_u8_PORTB:
      *Add_pu8Value = GET_BIT(DIO_u8_PINB_REG, Copy_u8PinId);
      break;
    case DIO_u8_PORTC:
      *Add_pu8Value = GET_BIT(DIO_u8_PINC_REG, Copy_u8PinId);
      break;
    case DIO_u8_PORTD:
      *Add_pu8Value = GET_BIT(DIO_u8_PIND_REG, Copy_u8PinId);
      break;
    }
  }
  return Local_enuErrorStatus;
}


DIO_tenuErrorStatus DIO_enuGetPortValue(u8 Copy_u8PortId, u8 *Add_pu8Value)
{
  DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
  // Check if the inputs are within valid ranges.
  if ((Copy_u8PortId > DIO_u8_PORTD) || (Add_pu8Value == NULL))
  {
    Local_enuErrorStatus = DIO_NOK;
  }
  else
  {
    // Read the value of the entire port from the port's input register (PINx).
    switch (Copy_u8PortId)
    {
    case DIO_u8_PORTA:
      *Add_pu8Value = GET_REG(DIO_u8_PINA_REG);
      break;
    case DIO_u8_PORTB:
      *Add_pu8Value = GET_REG(DIO_u8_PINB_REG);
      break;
    case DIO_u8_PORTC:
      *Add_pu8Value = GET_REG(DIO_u8_PINC_REG);
      break;
    case DIO_u8_PORTD:
      *Add_pu8Value = GET_REG(DIO_u8_PIND_REG);
      break;
    }
  }
  return Local_enuErrorStatus;
}

// Function to initialize all ports as OUTPUT and set their values to LOW.
void DIO_vidInit(void)
{
  // Set the direction of all ports to OUTPUT
  SET_REG(DIO_u8_DDRA_REG);
  SET_REG(DIO_u8_DDRB_REG);
  SET_REG(DIO_u8_DDRC_REG);
  SET_REG(DIO_u8_DDRD_REG);

  // Set the initial value of all ports to 0x00 (LOW)
  CLR_REG(DIO_u8_PORTA_REG);
  CLR_REG(DIO_u8_PORTB_REG);
  CLR_REG(DIO_u8_PORTC_REG);
  CLR_REG(DIO_u8_PORTD_REG);
}
