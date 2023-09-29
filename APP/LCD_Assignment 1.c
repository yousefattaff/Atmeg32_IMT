#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_cfg.h"
int main()
{

    _delay_ms(50);

    // Initialize the LCD
    LCD_enuInitialize();



    while (1)
    {
    	// initialize an u8 as row
        u8 row;
        // Bool for toggling the row
        bool isRow1 = false;

        u8 j = 0;
        for (int i = 0;  i <= 15  ; i++)
        {
        	u8 name[] = "Yousef";
        	// initiate a variable to store length of string in
        	u8 length = LCD_u8calcstr(name);
        	// ask if row is false or true if true then row = 2 else row = 1 .... just a way for the chars to be displayed first row then second
            row = isRow1 ? 2 : 1;
            // go the row(1 or 2) and col : i .... i looping from 0 to 15 as there are 16 chars
            LCD_voidGotoXY(row, i);
            // send char to be displayed on lcd
            LCD_enuSendData(name[j]);

            j++;
            // if name is less than the 16 chars reset j so that the lcd displays the chars from the start index again
            if (j == length)
            {
            	j = 0;
            }
            _delay_ms(100);
            isRow1 ^= true;
        }
        // clear the screen to make it seem like the name is disappearing
        LCD_enuSendInstruction(0x01);
    }

    return 0;
}
