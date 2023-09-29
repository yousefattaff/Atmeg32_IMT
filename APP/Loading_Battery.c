#include <avr/io.h>
#include <util/delay.h>
#include "../HAL/LCD/LCD_int.h"


u8 loading1[8] = {
		 0x0E,
		  0x0E,
		  0x0E,
		  0x1F,
		  0x11,
		  0x11,
		  0x11,
		  0x1F
};
u8 loading2[8] = {
		0x0E,
		  0x0E,
		  0x0E,
		  0x1F,
		  0x11,
		  0x11,
		  0x1F,
		  0x1F
};
u8 loading3[8] = {
		0x0E,
		  0x0E,
		  0x0E,
		  0x1F,
		  0x11,
		  0x1F,
		  0x1F,
		  0x1F
};
u8 loading4[8] = {
		0x0E,
		  0x0E,
		  0x0E,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F
};


int main() {
    // Initialize the LCD
    LCD_enuInitialize();


    if (LCD_enuSendSpecChar(CUSTOM_CHAR_0, loading1, 1, 0) == LCD_OK &&
    		LCD_enuSendSpecChar(CUSTOM_CHAR_1, loading2, 1, 0) == LCD_OK &&
			LCD_enuSendSpecChar(CUSTOM_CHAR_2, loading3, 1, 0) == LCD_OK &&
			LCD_enuSendSpecChar(CUSTOM_CHAR_3, loading4, 1, 0) == LCD_OK )
    {

    	while(1)
    	{
    		for (u8 i = 0; i <=3; i++)
    		{
    			LCD_voidGotoXY(1, 0);
    			LCD_enuSendData(i);
    			_delay_ms(1000);
    		}
    	}
    }
    else
    {
    	return 1;
    }
    return 0;
}
