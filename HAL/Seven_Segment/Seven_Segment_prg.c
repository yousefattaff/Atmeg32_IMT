#include "Seven_Segment_int.h"
#include "Seven_Segment_cfg.h"
#include "../LCD/bits.h"

/*
u8 A_u8sevenSegmentPatterns[10] = {
		0b00111111, // 0
		    0b00000110, // 1
		    0b01011011, // 2
		    0b01001111, // 3
		    0b01100110, // 4
		    0b01101101, // 5
		    0b01111101, // 6
		    0b00000111, // 7
		    0b01111111, // 8
		    0b01101111  // 9
};



u8 A_u8customPatternArray[10] = {
    // Pattern for custom digit 0
    0b00111111, // 0
    // Pattern for custom digit 1
    0b00000110, // 1
    // Pattern for custom character A
    0b01110111, // A
    // Pattern for custom character B
    0b01111100, // B
    // Pattern for custom digit 2
    0b01011011, // 2
    // Pattern for custom character C
    0b00111001, // C
    // Pattern for custom digit 3
    0b01001111, // 3
    // Pattern for custom character D
    0b01011110, // D
    // Pattern for custom digit 4
    0b01100110, // 4
    // Pattern for custom character E
    0b01111001, // E
};

*/



SevenSegment_tenuErrorStatus SevenSegment_enuInit(void)
{
    // Set each segment pin as OUTPUT
    if (DIO_enuSetPinDirection(SEGMENT_A_PORT, SEGMENT_A, DIO_u8_OUTPUT) != DIO_OK ||
        DIO_enuSetPinDirection(SEGMENT_B_PORT, SEGMENT_B, DIO_u8_OUTPUT) != DIO_OK ||
        DIO_enuSetPinDirection(SEGMENT_C_PORT, SEGMENT_C, DIO_u8_OUTPUT) != DIO_OK ||
        DIO_enuSetPinDirection(SEGMENT_D_PORT, SEGMENT_D, DIO_u8_OUTPUT) != DIO_OK ||
        DIO_enuSetPinDirection(SEGMENT_E_PORT, SEGMENT_E, DIO_u8_OUTPUT) != DIO_OK ||
        DIO_enuSetPinDirection(SEGMENT_F_PORT, SEGMENT_F, DIO_u8_OUTPUT) != DIO_OK ||
        DIO_enuSetPinDirection(SEGMENT_G_PORT, SEGMENT_G, DIO_u8_OUTPUT) != DIO_OK)
    {
        return SEVENSEG_NOK;
    }

    // Turn off all segments initially
    DIO_enuSetPinValue(SEGMENT_A_PORT, SEGMENT_A, DIO_u8_LOW);
    DIO_enuSetPinValue(SEGMENT_B_PORT, SEGMENT_B, DIO_u8_LOW);
    DIO_enuSetPinValue(SEGMENT_C_PORT, SEGMENT_C, DIO_u8_LOW);
    DIO_enuSetPinValue(SEGMENT_D_PORT, SEGMENT_D, DIO_u8_LOW);
    DIO_enuSetPinValue(SEGMENT_E_PORT, SEGMENT_E, DIO_u8_LOW);
    DIO_enuSetPinValue(SEGMENT_F_PORT, SEGMENT_F, DIO_u8_LOW);
    DIO_enuSetPinValue(SEGMENT_G_PORT, SEGMENT_G, DIO_u8_LOW);

    return SEVENSEG_OK;
}

SevenSegment_tenuErrorStatus SevenSegment_enuDisplayDigit(u8 Copy_u8Digit)
{
    // Check if the digit is within the valid range (0-9)
	if (Copy_u8Digit <= 9)
	    {
	        u8 Local_u8SegmentPattern = 0;
	        switch (Copy_u8Digit)
	        {
	        case 0:
	        	Local_u8SegmentPattern = 0b00111111;
	            break;
	        case 1:
	        	Local_u8SegmentPattern = 0b00000110;
	            break;
	        case 2:
	        	Local_u8SegmentPattern = 0b01011011;
	            break;
	        case 3:
	        	Local_u8SegmentPattern = 0b01001111;
	            break;
	        case 4:
	        	Local_u8SegmentPattern = 0b01100110;
	            break;
	        case 5:
	        	Local_u8SegmentPattern = 0b01101101;
	            break;
	        case 6:
	        	Local_u8SegmentPattern = 0b01111101;
	            break;
	        case 7:
	        	Local_u8SegmentPattern = 0b00000111;
	            break;
	        case 8:
	        	Local_u8SegmentPattern = 0b01111111;
	            break;
	        case 9:
	        	Local_u8SegmentPattern = 0b01101111;
	            break;
	        default:
	            return SEVENSEG_NOK; // Invalid digit
	        }

	        // Display the digit using the segment pattern

	        DIO_enuSetPinValue(SEGMENT_A_PORT, SEGMENT_A, (Anode1_Cathode0 ? !GET_BIT(Local_u8SegmentPattern, 0) : GET_BIT(Local_u8SegmentPattern, 0)));
	        DIO_enuSetPinValue(SEGMENT_B_PORT, SEGMENT_B, (Anode1_Cathode0 ? !GET_BIT(Local_u8SegmentPattern, 1) : GET_BIT(Local_u8SegmentPattern, 1)));
	        DIO_enuSetPinValue(SEGMENT_C_PORT, SEGMENT_C, (Anode1_Cathode0 ? !GET_BIT(Local_u8SegmentPattern, 2) : GET_BIT(Local_u8SegmentPattern, 2)));
	        DIO_enuSetPinValue(SEGMENT_D_PORT, SEGMENT_D, (Anode1_Cathode0 ? !GET_BIT(Local_u8SegmentPattern, 3) : GET_BIT(Local_u8SegmentPattern, 3)));
	        DIO_enuSetPinValue(SEGMENT_E_PORT, SEGMENT_E, (Anode1_Cathode0 ? !GET_BIT(Local_u8SegmentPattern, 4) : GET_BIT(Local_u8SegmentPattern, 4)));
	        DIO_enuSetPinValue(SEGMENT_F_PORT, SEGMENT_F, (Anode1_Cathode0 ? !GET_BIT(Local_u8SegmentPattern, 5) : GET_BIT(Local_u8SegmentPattern, 5)));
	        DIO_enuSetPinValue(SEGMENT_G_PORT, SEGMENT_G, (Anode1_Cathode0 ? !GET_BIT(Local_u8SegmentPattern, 6) : GET_BIT(Local_u8SegmentPattern, 6)));


        return SEVENSEG_OK;
    }
    else
    {
        return SEVENSEG_NOK;
    }
}

SevenSegment_tenuErrorStatus SevenSegment_enuDisplayCharacter(u8 Copy_char)
{
    // Convert the character to uppercase
    if (Copy_char >= 'a' && Copy_char <= 'z')
    {
    	// look up toupper and tolower libs in c
        Copy_char -= ('a' - 'A');
    }

    // Check if the character is within the valid range ('A' - 'F', space, etc.)
    if (Copy_char >= 'A' && Copy_char <= 'F')
    {
        // Display the character using the corresponding segment patterns
        u8 Local_u8SegmentPattern = 0;

        switch (Copy_char)
        {
        case 'A':
        	Local_u8SegmentPattern = 0b01110111; // Display 'A'
            break;
        case 'B':
        	Local_u8SegmentPattern = 0b01111100; // Display 'B'
            break;
        case 'C':
        	Local_u8SegmentPattern = 0b00111001; // Display 'C'
            break;
        case 'D':
        	Local_u8SegmentPattern = 0b01011110; // Display 'D'
            break;
        case 'E':
        	Local_u8SegmentPattern = 0b01111001; // Display 'E'
            break;
        case 'F':
        	Local_u8SegmentPattern = 0b01110001; // Display 'F'
            break;
        default:
            // For unsupported characters, turn off all segments
        	Local_u8SegmentPattern = 0b00000000;
            break;
        }


        // Display the character using the segment pattern
        DIO_enuSetPinValue(SEGMENT_A_PORT, SEGMENT_A, !GET_BIT(Local_u8SegmentPattern, 0));
        DIO_enuSetPinValue(SEGMENT_B_PORT, SEGMENT_B, !GET_BIT(Local_u8SegmentPattern, 1));
        DIO_enuSetPinValue(SEGMENT_C_PORT, SEGMENT_C, !GET_BIT(Local_u8SegmentPattern, 2));
        DIO_enuSetPinValue(SEGMENT_D_PORT, SEGMENT_D, !GET_BIT(Local_u8SegmentPattern, 3));
        DIO_enuSetPinValue(SEGMENT_E_PORT, SEGMENT_E, !GET_BIT(Local_u8SegmentPattern, 4));
        DIO_enuSetPinValue(SEGMENT_F_PORT, SEGMENT_F, !GET_BIT(Local_u8SegmentPattern, 5));
        DIO_enuSetPinValue(SEGMENT_G_PORT, SEGMENT_G, !GET_BIT(Local_u8SegmentPattern, 6));




        return SEVENSEG_OK;
    }
    else
    {
        return SEVENSEG_NOK;
    }
}


SevenSegment_tenuErrorStatus SevenSegment_vidDisplayCustomPattern(u8 patternIndex)
{
	// Check if the patternIndex is within the valid range (0-9)
	    if (patternIndex <= 9)
	    {
	        // Display the pattern using the corresponding segment patterns from the customPatternArray
	    	DIO_enuSetPinValue(SEGMENT_A_PORT, SEGMENT_A, (Anode1_Cathode0 ? !GET_BIT(A_u8customPatternArray[patternIndex], 0) : GET_BIT(A_u8customPatternArray[patternIndex], 0)));
	    	DIO_enuSetPinValue(SEGMENT_B_PORT, SEGMENT_B, (Anode1_Cathode0 ? !GET_BIT(A_u8customPatternArray[patternIndex], 1) : GET_BIT(A_u8customPatternArray[patternIndex], 1)));
	    	DIO_enuSetPinValue(SEGMENT_C_PORT, SEGMENT_C, (Anode1_Cathode0 ? !GET_BIT(A_u8customPatternArray[patternIndex], 2) : GET_BIT(A_u8customPatternArray[patternIndex], 2)));
	    	DIO_enuSetPinValue(SEGMENT_D_PORT, SEGMENT_D, (Anode1_Cathode0 ? !GET_BIT(A_u8customPatternArray[patternIndex], 3) : GET_BIT(A_u8customPatternArray[patternIndex], 3)));
	    	DIO_enuSetPinValue(SEGMENT_E_PORT, SEGMENT_E, (Anode1_Cathode0 ? !GET_BIT(A_u8customPatternArray[patternIndex], 4) : GET_BIT(A_u8customPatternArray[patternIndex], 4)));
	    	DIO_enuSetPinValue(SEGMENT_F_PORT, SEGMENT_F, (Anode1_Cathode0 ? !GET_BIT(A_u8customPatternArray[patternIndex], 5) : GET_BIT(A_u8customPatternArray[patternIndex], 5)));
	    	DIO_enuSetPinValue(SEGMENT_G_PORT, SEGMENT_G, (Anode1_Cathode0 ? !GET_BIT(A_u8customPatternArray[patternIndex], 6) : GET_BIT(A_u8customPatternArray[patternIndex], 6)));

	        return SEVENSEG_OK;
	    }
	    else
	    {
	        return SEVENSEG_NOK;
	    }
}
