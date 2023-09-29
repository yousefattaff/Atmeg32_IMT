
#include "../../MCAL/DIO/DIO_int.h"
#include "KeyPad_int.h"
#include "KeyPad_cfg.h"




u8 KPD_u8GetPressedKey(void)
{
	    u8 Local_u8PressedKey = KPD_INITILIAZE_VALUE;
	    u8 Local_u8RowIndex;
	    u8 Local_u8ColumnIndex;
	    u8 Local_u8PinState;

	    static u8 Local_u8KPD_Arr[KEPAD_u8_NUMBER_OF_ROWS][KEPAD_u8_NUMBER_OF_COLS] = KPD_VALUES;
	    static u8 Local_u8RowArr[KEPAD_u8_NUMBER_OF_ROWS] = {
	        KPD_u8_ROW0, KPD_u8_ROW1, KPD_u8_ROW2, KPD_u8_ROW3
	    };

	    static u8 Local_u8ColumnArr[KEPAD_u8_NUMBER_OF_COLS] = {
	        KPD_u8_COLUMN0, KPD_u8_COLUMN1, KPD_u8_COLUMN2, KPD_u8_COLUMN3
	    };

	for(Local_u8ColumnIndex=0 ; Local_u8ColumnIndex <KEPAD_u8_NUMBER_OF_COLS ;Local_u8ColumnIndex++)
	{
		DIO_enuSetPinValue(KPD_COLUMN_PORT ,Local_u8ColumnArr[Local_u8ColumnIndex] ,DIO_u8_LOW);

		for(Local_u8RowIndex=0 ; Local_u8RowIndex < KEPAD_u8_NUMBER_OF_ROWS ; Local_u8RowIndex++)
		{
			DIO_enuGetPinValue(KPD_ROW_PORT , Local_u8RowArr[Local_u8RowIndex] , &Local_u8PinState);

			if(Local_u8PinState==DIO_u8_LOW)
			{
				Local_u8PressedKey=Local_u8KPD_Arr[Local_u8RowIndex][Local_u8ColumnIndex];

				while(Local_u8PinState==DIO_u8_LOW)
				{
					DIO_enuGetPinValue(KPD_ROW_PORT , Local_u8RowArr[Local_u8RowIndex] , &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
		}

		DIO_enuSetPinValue(KPD_COLUMN_PORT ,Local_u8ColumnArr[Local_u8ColumnIndex] ,DIO_u8_HIGH);

	}

	return Local_u8PressedKey;

}

void KPD_vidInit()
{
    // Initialize the rows as input with pull-up resistors
	DIO_enuSetPinDirection(KPD_ROW_PORT, KPD_u8_ROW0, DIO_u8_INPUT);
	DIO_enuSetPinDirection(KPD_ROW_PORT, KPD_u8_ROW1, DIO_u8_INPUT);
	DIO_enuSetPinDirection(KPD_ROW_PORT, KPD_u8_ROW2, DIO_u8_INPUT);
	DIO_enuSetPinDirection(KPD_ROW_PORT, KPD_u8_ROW3, DIO_u8_INPUT);

	DIO_enuSetPinValue(KPD_ROW_PORT, KPD_u8_ROW0, DIO_u8_HIGH);
	DIO_enuSetPinValue(KPD_ROW_PORT, KPD_u8_ROW1, DIO_u8_HIGH);
	DIO_enuSetPinValue(KPD_ROW_PORT, KPD_u8_ROW2, DIO_u8_HIGH);
	DIO_enuSetPinValue(KPD_ROW_PORT, KPD_u8_ROW3, DIO_u8_HIGH);


    // Initialize the columns as output
    DIO_enuSetPinDirection(KPD_COLUMN_PORT, KPD_u8_COLUMN0, DIO_u8_OUTPUT);
    DIO_enuSetPinDirection(KPD_COLUMN_PORT, KPD_u8_COLUMN1, DIO_u8_OUTPUT);
    DIO_enuSetPinDirection(KPD_COLUMN_PORT, KPD_u8_COLUMN2, DIO_u8_OUTPUT);
    DIO_enuSetPinDirection(KPD_COLUMN_PORT, KPD_u8_COLUMN3, DIO_u8_OUTPUT);

    // Initially, set all column pins to HIGH
    DIO_enuSetPortValue(KPD_COLUMN_PORT, DIO_u8_HIGH);
}









