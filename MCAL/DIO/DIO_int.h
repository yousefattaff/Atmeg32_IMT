/*
 * DIO_int.h
 *
 * Yousef-Alsayed-Abdelfattah
 */

#ifndef MCAL_DIO_DRIVER_DIO_INT_H_
#define MCAL_DIO_DRIVER_DIO_INT_H_

#include "data_types.h"
#include "DIO_prv.h"
#include "bits.h"
// DIO Ports
#define DIO_u8_PORTA   0
#define DIO_u8_PORTB   1
#define DIO_u8_PORTC   2
#define DIO_u8_PORTD   3

// DIO Pins
#define DIO_u8_PIN0    0
#define DIO_u8_PIN1    1
#define DIO_u8_PIN2    2
#define DIO_u8_PIN3    3
#define DIO_u8_PIN4    4
#define DIO_u8_PIN5    5
#define DIO_u8_PIN6    6
#define DIO_u8_PIN7    7

// Pin Direction
#define DIO_u8_INPUT   0
#define DIO_u8_OUTPUT  1

// Pin Values
#define DIO_u8_LOW     0
#define DIO_u8_HIGH    1

typedef enum {
	DIO_OK, DIO_NOK
} DIO_tenuErrorStatus;

/*
 * Function name: DIO_enuSetPinDirection
 * Description: Set the pin direction (input or output) for a specific pin.
 * Inputs:
 *   - u8 Copy_u8PortId: The port to which the pin belongs (e.g., DIO_u8_PORTA).
 *   - u8 Copy_u8PinId: The pin number (0 to 7).
 *   - u8 Copy_u8Direction: The desired direction (DIO_u8_INPUT or DIO_u8_OUTPUT).
 * Returns:
 *   - DIO_tenuErrorStatus: OK or NOK indicating success or failure.
 */
DIO_tenuErrorStatus DIO_enuSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8Direction);

/*
 * Function name: DIO_enuSetPortDirection
 * Description: Set the direction (input or output) for all pins in a given port.
 * Inputs:
 *   - u8 Copy_u8PortId: The port to configure (e.g., DIO_u8_PORTA).
 *   - u8 Copy_u8Direction: The desired direction (DIO_u8_INPUT or DIO_u8_OUTPUT).
 * Returns:
 *   - DIO_tenuErrorStatus: OK or NOK indicating success or failure.
 */
DIO_tenuErrorStatus DIO_enuSetPortDirection(u8 Copy_u8PortId,
		u8 Copy_u8Direction);

/*
 * Function name: DIO_enuSetPinValue
 * Description: Set the value (high or low) for a specific pin.
 * Inputs:
 *   - u8 Copy_u8PortId: The port to which the pin belongs (e.g., DIO_u8_PORTA).
 *   - u8 Copy_u8PinId: The pin number (0 to 7).
 *   - u8 Copy_u8Value: The desired value (DIO_u8_HIGH or DIO_u8_LOW).
 * Returns:
 *   - DIO_tenuErrorStatus: OK or NOK indicating success or failure.
 */
DIO_tenuErrorStatus DIO_enuSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8Value);

/*
 * Function name: DIO_enuSetPortValue
 * Description: Set the value (high or low) for all pins in a given port.
 * Inputs:
 *   - u8 Copy_u8PortId: The port to configure (e.g., DIO_u8_PORTA).
 *   - u8 Copy_u8Value: The desired value (DIO_u8_HIGH or DIO_u8_LOW).
 * Returns:
 *   - DIO_tenuErrorStatus: OK or NOK indicating success or failure.
 */
DIO_tenuErrorStatus DIO_enuSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value);

/*
 * Function name: DIO_enuGetPinValue
 * Description: Read and return the value (high or low) of a specific pin.
 * Inputs:
 *   - u8 Copy_u8PortId: The port to which the pin belongs (e.g., DIO_u8_PORTA).
 *   - u8 Copy_u8PinId: The pin number (0 to 7).
 *   - u8 *Add_pu8Value: Pointer to store the pin value.
 * Returns:
 *   - DIO_tenuErrorStatus: OK or NOK indicating success or failure.
 */
DIO_tenuErrorStatus DIO_enuGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8* Add_pu8Value);

/*
 * Function name: DIO_enuGetPortValue
 * Description: Read and return the value (high or low) of all pins in a given port.
 * Inputs:
 *   - u8 Copy_u8PortId: The port to read (e.g., DIO_u8_PORTA).
 *   - u8 *Add_pu8Value: Pointer to store the port value.
 * Returns:
 *   - DIO_tenuErrorStatus: OK or NOK indicating success or failure.
 */
DIO_tenuErrorStatus DIO_enuGetPortValue(u8 Copy_u8PortId, u8* Add_pu8Value);

/*
 * Function name: DIO_vidInit
 * Description: Initialize all digital I/O ports as outputs with initial values set to low.
 * Inputs: void-none
 * Returns: void-none
 */
void DIO_vidInit(void);

#endif /* MCAL_DIO_DRIVER_DIO_INT_H_ */
