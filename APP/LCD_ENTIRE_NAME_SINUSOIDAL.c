#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_cfg.h"
int main()
{

    _delay_ms(50);

    // Initialize the LCDF
    LCD_enuInitialize();



    while (1)
    {
        u8 row;
        // Bool for toggling the row
        bool isRow1 = false;
        u8 name[] = "Yousef";

        for (int i = 0;  i <= 15  ; i++)
        {
        	// ask if row is false or true if true then row = 2 else row = 1 .... just a way for the chars to be displayed first row then second
            row = isRow1 ? 2 : 1;

            // go the row(1 or 2) and col : i .... i looping from 0 to 15 as there are 16 chars
            LCD_voidGotoXY(row, i);
            // send name to be displayed on lcd
            LCD_vidSendStr(name);

			isRow1 ^= true;
            _delay_ms(300);
            LCD_enuSendInstruction(0x01);
        }
    }

    return 0;
}
