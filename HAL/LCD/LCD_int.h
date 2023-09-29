/*
 * LCD_int.h
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#include "../../MCAL/DIO/DIO_int.h"
#include"avr/delay.h"
#include "../LCD/bits.h"
#include "../LCD/data_types.h"
#include "../LCD/LCD_cfg.h"


typedef enum
{
    LCD_OK,
    LCD_NOK
} LCD_tenuErrorStatus;


/*
 * Function name: LCD_enuSendInstruction
 * Description: This function is used to send an instruction/command to the LCD.
 * Inputs:
 *   - Copy_u8Instruction: The instruction/command to send to the LCD.
 * Returns:
 *   - LCD_tenuErrorStatus: OK or NOK indicating the success or failure of the operation.
 * Explanation: This function sends an instruction to the LCD, which controls various display settings or actions, such as clearing the display or setting the cursor position.
 */
LCD_tenuErrorStatus LCD_enuSendInstruction(u8 Copy_u8Instruction);



/*
 * Function name: LCD_enuSendData
 * Description: This function is used to send data to be displayed on the LCD.
 * Inputs:
 *   - Copy_u8Data: The data to be displayed on the LCD.
 * Returns:
 *   - LCD_tenuErrorStatus: OK or NOK indicating the success or failure of the operation.
 * Explanation: This function sends character data to the LCD, which will be shown on the screen. It typically involves setting the RS (Register Select) pin to indicate data mode and writing the data to the data pins.
 */
LCD_tenuErrorStatus LCD_enuSendData(u8 Copy_u8Data);



/*
 * Function name: LCD_enuInitialize
 * Description: This function initializes the LCD module.
 * Inputs:
			VOID
 * Returns:
 *   - LCD_tenuErrorStatus: OK or NOK indicating the success or failure of the initialization.
 * Explanation: The initialization function sets up the LCD for use. It configures the control and data pins, clears the display, and sets other display settings.
 */
LCD_tenuErrorStatus LCD_enuInitialize();


/*
 * Function name: LCD_voidGotoXY
 * Description: This function moves the cursor to a specific row and column on the LCD.
 * Inputs:
 *   - Copy_u8Row: The row number (1 or 2) to move the cursor to.
 *   - Copy_u8Column: The column number (0 to 15) to move the cursor to.

 * Returns:
 *   - LCD_tenuErrorStatus: OK or NOK indicating the success or failure of the operation.
 * Explanation: This function positions the cursor at a specific location on the LCD screen, allowing you to control where text or characters will be displayed.
 */
LCD_tenuErrorStatus LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column);



/*
 * Function name: LCD_enuSendSpecChar
 * Description: This function sends a custom-defined special character to the LCD.
 * Inputs:
 *   - Copy_u8PatternNo: The pattern number (0 to 7) for the custom character.
 *   - Add_pu8Pattern: Pointer to an array containing the custom character's data pattern.
 *   - Copy_u8Row: The row number (1 or 2) to display the custom character.
 *   - Copy_u8Col: The column number (0 to 15) to display the custom character.
 * Returns:
 *   - LCD_tenuErrorStatus: OK or NOK indicating the success or failure of the operation.
 */
LCD_tenuErrorStatus LCD_enuSendSpecChar( u8 Copy_u8PatternNo, u8* Add_pu8Pattern, u8 Copy_u8Row, u8 Copy_u8Col);





/*
 * Function name: LCD_vidSendStr
 * Description: This function sends a string to be displayed on the LCD.
 * Inputs:
 *   - Copy_u8str: Pointer to the null-terminated string to be displayed.
 * Returns:
 *   - VOID
 */
void LCD_vidSendStr(u8 * Copy_u8str);


/*
 * Function name: LCD_u8calcstr
 * Description: calculates the chars in the name to loop on them, it's helpful in certain programs
 * Inputs:
 *   - Copy_u8str: Pointer to the null-terminated string to be displayed.
 * Returns:
 *   - number of chars in u8 type.
 */
u8 LCD_u8calcstr(u8* Copy_u8str);


// frequently used instructions

#define CLRSCR 0x01
#define DISPLAY_ON 0x0C
#define DISPLAY_OFF 0x08
#define CURSOR_ON 0x0A
#define CURSOR_OFF 0x08
#define CURSOR_INC 0x06
#define MODE_8BIT 0x38
#define MODE_4BIT 0x28
#define SET_CGRAM_ADDRESS 0x40

// Define meaningful names for custom characters in CGRAM from 0 to 7
#define CUSTOM_CHAR_0 0
#define CUSTOM_CHAR_1 1
#define CUSTOM_CHAR_2 2
#define CUSTOM_CHAR_3 3
#define CUSTOM_CHAR_4 4
#define CUSTOM_CHAR_5 5
#define CUSTOM_CHAR_6 6
#define CUSTOM_CHAR_7 7


/* Instructions Section */
#define LCD_u8_CLEAR_DISPLAY    0x01
#define LCD_u8_RETURN_HOME      0x02
#define LCD_u8_DISPLAY_CONTROL  0x08

#endif /* HAL_LCD_LCD_INT_H_ */
