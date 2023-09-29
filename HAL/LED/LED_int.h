/*
 * LED_Driver_int.h
 *
 *  Created on: Sep 10, 2023
 *      Author: youse
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

#include"avr/delay.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../LED/bits.h"
#include "../LED/data_types.h"

typedef enum {
    LED_OK,
    LED_NOK
} LED_tenuErrorStatus;

// DIO MAX PORTS
#define LCD_u8_MAXPORTS   3

// DIO MAX PINS
#define LCD_u8_MAXPINS   7



/*
 * Function name: LED_vidturnOnLED
 * Description: Turn on a LED.
 * Inputs: port and designated pin.
 * Returns: OK or NOK
 */
LED_tenuErrorStatus LED_enuturnOnLED(u8 Copy_u8PortId, u8 Copy_u8PinId);

/*
 * Function name: LED_vidturnOffLED
 * Description: Turn off a LED.
 * Inputs: port and designated pin.
 * Returns: OK or NOK
 */
LED_tenuErrorStatus LED_enuturnOffLED(u8 Copy_u8PortId, u8 Copy_u8PinId);


/*
 * Function name: LED_vidBlink
 * Description: Make Led on then off and delay for a period that you choose (Basically choose the freq).
 * Inputs: port and designated pin.
 * Returns: OK or NOK
 */
LED_tenuErrorStatus LED_enuBlink(u8 Copy_u8PortId, u8 Copy_u8PinId,u32 Copy_u8Sec);



#endif /* HAL_LED_LED_INT_H_ */
