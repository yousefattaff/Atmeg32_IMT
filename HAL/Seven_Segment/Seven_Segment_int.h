/*
 * Seven_Segment_int.h
 *
 *  Created on: Sep 17, 2023
 *      Author: youse
 */

#ifndef HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_INT_H_
#define HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_INT_H_

#include "../../MCAL/DIO/DIO_int.h"


// Define segment patterns for numbers 0-9
extern u8 A_u8sevenSegmentPatterns[10];
extern u8 A_u8customPatternArray[10];



typedef enum {
    SEVENSEG_OK,
    SEVENSEG_NOK
} SevenSegment_tenuErrorStatus;


// Function to initialize the seven-segment display
// Input: None
// Output: Returns SEVENSEG_OK if initialization is successful, SEVENSEG_NOK otherwise.
SevenSegment_tenuErrorStatus SevenSegment_enuInit(void);

// Function to display a single digit (0-9)
// Input: Copy_u8Digit - The digit to be displayed (0-9)
// Output: Returns SEVENSEG_OK if the digit is successfully displayed, SEVENSEG_NOK if there's an error or an invalid digit is provided.
SevenSegment_tenuErrorStatus SevenSegment_enuDisplayDigit(u8 Copy_u8Digit);

// Function to display a character (A-F, space, etc.)
// Input: Copy_char - The character to be displayed (A-F, space, etc.)
// Output: Returns SEVENSEG_OK if the character is successfully displayed, SEVENSEG_NOK if there's an error or an invalid character is provided.
SevenSegment_tenuErrorStatus SevenSegment_enuDisplayCharacter(u8 Copy_char);

// Function to display a custom pattern (0-9) on the seven-segment display
// Input: pattern - The pattern number to be displayed (0-9)
// Output: Returns SEVENSEG_OK if the pattern is successfully displayed, SEVENSEG_NOK if there's an error or an invalid pattern number is provided.
SevenSegment_tenuErrorStatus SevenSegment_vidDisplayCustomPattern(u8 pattern);


#endif /* HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_INT_H_ */
