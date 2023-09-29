#include "LCD_int.h"

#include"avr/delay.h"

/* el site el gamed */
/* https://maxpromer.github.io/LCD-Character-Creator/ */




LCD_tenuErrorStatus LCD_enuSendInstruction(u8 Copy_u8Instruction)
{
	if (
	    DIO_enuSetPinDirection(LCD_D0_PORT, LCD_D0_PIN, DIO_u8_OUTPUT) == DIO_OK &&
	    DIO_enuSetPinDirection(LCD_D1_PORT, LCD_D1_PIN, DIO_u8_OUTPUT) == DIO_OK &&
	    DIO_enuSetPinDirection(LCD_D2_PORT, LCD_D2_PIN, DIO_u8_OUTPUT) == DIO_OK &&
	    DIO_enuSetPinDirection(LCD_D3_PORT, LCD_D3_PIN, DIO_u8_OUTPUT) == DIO_OK &&
	    DIO_enuSetPinDirection(LCD_D4_PORT, LCD_D4_PIN, DIO_u8_OUTPUT) == DIO_OK &&
	    DIO_enuSetPinDirection(LCD_D5_PORT, LCD_D5_PIN, DIO_u8_OUTPUT) == DIO_OK &&
	    DIO_enuSetPinDirection(LCD_D6_PORT, LCD_D6_PIN, DIO_u8_OUTPUT) == DIO_OK &&
	    DIO_enuSetPinDirection(LCD_D7_PORT, LCD_D7_PIN, DIO_u8_OUTPUT) == DIO_OK
	) {

		DIO_enuSetPinValue(LCD_D0_PORT, LCD_D0_PIN, GET_BIT(Copy_u8Instruction, 0));
		DIO_enuSetPinValue(LCD_D1_PORT, LCD_D1_PIN, GET_BIT(Copy_u8Instruction, 1));
		DIO_enuSetPinValue(LCD_D2_PORT, LCD_D2_PIN, GET_BIT(Copy_u8Instruction, 2));
		DIO_enuSetPinValue(LCD_D3_PORT, LCD_D3_PIN, GET_BIT(Copy_u8Instruction, 3));
		DIO_enuSetPinValue(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Instruction, 4));
		DIO_enuSetPinValue(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Instruction, 5));
		DIO_enuSetPinValue(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Instruction, 6));
		DIO_enuSetPinValue(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Instruction, 7));
	}
	else
	{
		return LCD_NOK;
	}

    if (DIO_enuSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_u8_LOW) == DIO_OK &&
        DIO_enuSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_u8_LOW) == DIO_OK)
    {

        DIO_enuSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_u8_LOW);  // RS = 0 (command reg.)
        DIO_enuSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_u8_LOW);  // RW = 0 (write operation)

        //  Send Enable Pulse
        DIO_enuSetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_u8_HIGH);
        _delay_us(2);
        DIO_enuSetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_u8_LOW);
        _delay_us(100);

        return LCD_OK;
    }

    // If any validation or control pin setting fails, return failure status
    return LCD_NOK;
}




LCD_tenuErrorStatus LCD_enuSendData(u8 Copy_u8Data)
{
	if (
		    DIO_enuSetPinDirection(LCD_D0_PORT, LCD_D0_PIN, DIO_u8_OUTPUT) == DIO_OK &&
		    DIO_enuSetPinDirection(LCD_D1_PORT, LCD_D1_PIN, DIO_u8_OUTPUT) == DIO_OK &&
		    DIO_enuSetPinDirection(LCD_D2_PORT, LCD_D2_PIN, DIO_u8_OUTPUT) == DIO_OK &&
		    DIO_enuSetPinDirection(LCD_D3_PORT, LCD_D3_PIN, DIO_u8_OUTPUT) == DIO_OK &&
		    DIO_enuSetPinDirection(LCD_D4_PORT, LCD_D4_PIN, DIO_u8_OUTPUT) == DIO_OK &&
		    DIO_enuSetPinDirection(LCD_D5_PORT, LCD_D5_PIN, DIO_u8_OUTPUT) == DIO_OK &&
		    DIO_enuSetPinDirection(LCD_D6_PORT, LCD_D6_PIN, DIO_u8_OUTPUT) == DIO_OK &&
		    DIO_enuSetPinDirection(LCD_D7_PORT, LCD_D7_PIN, DIO_u8_OUTPUT) == DIO_OK
		) {

			DIO_enuSetPinValue(LCD_D0_PORT, LCD_D0_PIN, GET_BIT(Copy_u8Data, 0));
			DIO_enuSetPinValue(LCD_D1_PORT, LCD_D1_PIN, GET_BIT(Copy_u8Data, 1));
			DIO_enuSetPinValue(LCD_D2_PORT, LCD_D2_PIN, GET_BIT(Copy_u8Data, 2));
			DIO_enuSetPinValue(LCD_D3_PORT, LCD_D3_PIN, GET_BIT(Copy_u8Data, 3));
			DIO_enuSetPinValue(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(Copy_u8Data, 4));
			DIO_enuSetPinValue(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(Copy_u8Data, 5));
			DIO_enuSetPinValue(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(Copy_u8Data, 6));
			DIO_enuSetPinValue(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(Copy_u8Data, 7));
		}
		else
		{
			return LCD_NOK;
		}
    // Validate Inputs
    if (DIO_enuSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_u8_HIGH) == DIO_OK &&
        DIO_enuSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_u8_LOW) == DIO_OK)
    {
        // Send Enable pulse
        DIO_enuSetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_u8_HIGH);
        _delay_us(2);
        DIO_enuSetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_u8_LOW);

        // Delay for LCD processing
        _delay_us(100);

        return LCD_OK;
    }

    return LCD_NOK;
}



LCD_tenuErrorStatus LCD_enuInitialize()
{
    LCD_tenuErrorStatus Local_enuErrorStatus = LCD_OK;

    // Step 1: Validate and set the direction of control pins (RS, RW, EN)
    if (
        DIO_enuSetPinDirection(LCD_RS_PORT, LCD_RS_PIN, DIO_u8_OUTPUT) == DIO_OK &&
        DIO_enuSetPinDirection(LCD_RW_PORT, LCD_RW_PIN, DIO_u8_OUTPUT) == DIO_OK &&
        DIO_enuSetPinDirection(LCD_EN_PORT, LCD_EN_PIN, DIO_u8_OUTPUT) == DIO_OK)
    {
        // Step 2: Delay for 30 ms
        _delay_ms(10);

        /* Function set (8-bit mode) */
        Local_enuErrorStatus = LCD_enuSendInstruction(0x38);

        /* Function set (8-bit mode, 2 lines, 5x8 font) */
        if (Local_enuErrorStatus == LCD_OK)
        {
            Local_enuErrorStatus = LCD_enuSendInstruction(0x0C);
        }

        /* Display on/off control (Display on, Cursor off, Blink off) */
        if (Local_enuErrorStatus == LCD_OK)
        {
            Local_enuErrorStatus = LCD_enuSendInstruction(0x06);
            _delay_ms(10);

        }

        /* Clear display */
        if (Local_enuErrorStatus == LCD_OK)
        {
            Local_enuErrorStatus = LCD_enuSendInstruction(0x01);

        }
    }

    return Local_enuErrorStatus;
}

LCD_tenuErrorStatus LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
	// validate inputs

	if( (Copy_u8Row == 1) && (Copy_u8Column < 16) )
	{
		LCD_enuSendInstruction(0x80 + Copy_u8Column);
		return LCD_OK;
	}
	else if( (Copy_u8Row == 2) && (Copy_u8Column < 16) )
	{
		LCD_enuSendInstruction(0xC0 + Copy_u8Column);
		return LCD_OK;
	}
	else
	{
		return LCD_NOK;
	}

}



LCD_tenuErrorStatus LCD_enuSendSpecChar(u8 Copy_u8PatternNo, u8* Add_pu8Pattern, u8 Copy_u8Row, u8 Copy_u8Col)
{
    u8 Local_u8_counter = 0;
    // Send AC to CGRAM
    if (LCD_enuSendInstruction(0x40 | (Copy_u8PatternNo * 8)) == LCD_OK)
    {
        // Send pattern
        for (Local_u8_counter = 0; Local_u8_counter < 8; Local_u8_counter++)
        {
            if (LCD_enuSendData(Add_pu8Pattern[Local_u8_counter]) != LCD_OK)
            {
                return LCD_NOK;
            }
        }
        // Send AC to DDRAM
        return LCD_voidGotoXY(Copy_u8Row, Copy_u8Col);
    }
    return LCD_NOK;
}


void LCD_vidSendStr(u8 * Copy_u8str)
{
	while(*Copy_u8str!='\0')
	{
		LCD_enuSendData(*Copy_u8str);
		Copy_u8str++;
	}
}



u8 LCD_u8calcstr(u8* Copy_u8str)
   {
       u8 i = 0;
       while (Copy_u8str[i] != '\0')
           i++;
       return i;
   }

