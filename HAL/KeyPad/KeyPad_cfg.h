
#ifndef HAL_KEYPAD_KPD_CONFIG_H_
#define HAL_KEYPAD_KPD_CONFIG_H_

#include "../../MCAL/DIO/DIO_int.h"





#define KPD_INITILIAZE_VALUE   0xff

#define KEPAD_u8_NUMBER_OF_ROWS      4
#define KEPAD_u8_NUMBER_OF_COLS      4

#define KPD_VALUES {{1, 2, 3, 'A'}, {4, 5, 6, 'B'}, {7, 8, 9, 'C'}, {10, 11, 12, 'D'}}

#define KPD_ROW_PORT      DIO_u8_PORTA


#define KPD_u8_ROW0       DIO_u8_PIN4
#define KPD_u8_ROW1       DIO_u8_PIN5
#define KPD_u8_ROW2       DIO_u8_PIN6
#define KPD_u8_ROW3       DIO_u8_PIN7



#define KPD_COLUMN_PORT   DIO_u8_PORTA


#define KPD_u8_COLUMN0    DIO_u8_PIN3
#define KPD_u8_COLUMN1    DIO_u8_PIN2
#define KPD_u8_COLUMN2    DIO_u8_PIN1
#define KPD_u8_COLUMN3    DIO_u8_PIN0

#endif /* HAL_KEYPAD_KPD_CONFIG_H_ */
