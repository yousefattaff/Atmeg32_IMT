

#ifndef HAL_KEYPAD_KPD_INTERFACE_H_
#define HAL_KEYPAD_KPD_INTERFACE_H_


#include "../../MCAL/DIO/DIO_int.h"

/**
 * Function name: KPD_u8GetPressedKey
 * Description: Get the currently pressed key from the keypad.
 * Inputs: None
 * Returns:
 *   - u8: identifier (BE IT A NUMBER OR A CHAR) of the pressed key.
 */
u8 KPD_u8GetPressedKey(void);

/**
 * Function name: KPD_vidInit
 * Description: Initialize the keypad for input.
 * Inputs: None
 * Returns: None
 */
void KPD_vidInit(void);


#endif /* HAL_KEYPAD_KPD_INTERFACE_H_ */
