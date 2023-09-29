/*
 * switches_int.h
 *
 *  Created on: Sep 23, 2023
 *      Author: youse
 */

#ifndef HAL_SWITCHES_SWITCHES_INT_H_
#define HAL_SWITCHES_SWITCHES_INT_H_

#include "../../MCAL/DIO/DIO_int.h"

typedef enum
{
	SWITCH_PRESSED,
	SWITCH_NOTPRESSED,
	SWITCH_DIO_OK,
	SWITCH_DIO_NOK
} Switches_enuSwitchStatues;

/*
 * Function to check if a switch is pressed.
 * Parameters:
 *   - u8 Copy_u8PortId: The port where the switch is connected (DIO_u8_PORTA, DIO_u8_PORTB, etc.).
 *   - u8 Copy_u8PinId: The pin number where the switch is connected (0 to 7).
 * Returns:
 *   - Switches_enuSwitchStatues: SWITCH_PRESSED if the switch is pressed, 0 SWITCH_NOTPRESSED it is not pressed.
 *   SWITCH_DIO_OK,
	 SWITCH_DIO_NOK
	 depending on DIO inputs
 */
Switches_enuSwitchStatues IsSwitchPressed(u8 Copy_u8PortId, u8 Copy_u8PinId);

/*
 * Function to check if a switch is not pressed.
 * Parameters:
 *   - u8 Copy_u8PortId: The port where the switch is connected (DIO_u8_PORTA, DIO_u8_PORTB, etc.).
 *   - u8 Copy_u8PinId: The pin number where the switch is connected (0 to 7).
 * Returns:
 *   - Switches_enuSwitchStatues: SWITCH_NOTPRESSED if the switch is not pressed, SWITCH_PRESSED if it is pressed.
 *    SWITCH_DIO_OK,
	  SWITCH_DIO_NOK
	  depending on DIO inputs
 */
Switches_enuSwitchStatues IsSwitchNotPressed(u8 Copy_u8PortId, u8 Copy_u8PinId);

/*
 * Function to SetSwitch.
 * Parameters:
 *   - u8 Copy_u8PortId: The port where the switch is connected (DIO_u8_PORTA, DIO_u8_PORTB, etc.).
 *   - u8 Copy_u8PinId: The pin number where the switch is connected (0 to 7).
 * Returns:
 *
 *    SWITCH_DIO_OK,
	  SWITCH_DIO_NOK
	  depending on DIO inputs
 */
Switches_enuSwitchStatues SetSwitch(u8 Copy_u8PortId, u8 Copy_u8PinId);

#endif /* HAL_SWITCHES_SWITCHES_INT_H_ */
