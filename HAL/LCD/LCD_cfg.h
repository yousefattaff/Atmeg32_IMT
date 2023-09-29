/*
 * LCD_cfg.h
 *
 *
 *
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

#include "../../MCAL/DIO/DIO_int.h"
#include "../LCD/LCD_int.h"



#define LCD_u8_ONE_LINE		0
#define LCD_u8_TWO_LINE		1
#define LCD_u8_5_7_CHAR		0x00
#define LCD_u8_5_10_CHAR	0x04


/* options are:
 * 			1- LCD_u8_ONE_LINE
 * 			2- LCD_u8_TWO_LINE
 */
#define LCD_u8_MUBER_OF_LINES	 LCD_u8_ONE_LINE

/* options are:
 * 			1- LCD_u8_5_10_CHAR
 * 			2- LCD_u8_5_7_CHAR
*/
#define LCD_u8_FONT		LCD_u8_5_10_CHAR



// Define your port and pin numbers for Control Pins
#define LCD_RS_PORT   DIO_u8_PORTD
#define LCD_RS_PIN    DIO_u8_PIN2

#define LCD_RW_PORT   DIO_u8_PORTD
#define LCD_RW_PIN    DIO_u8_PIN1

#define LCD_EN_PORT   DIO_u8_PORTD
#define LCD_EN_PIN    DIO_u8_PIN0

// Define your port and pin numbers for Data Pins (D0 to D7)
#define LCD_D0_PORT   DIO_u8_PORTA
#define LCD_D0_PIN    DIO_u8_PIN7

#define LCD_D1_PORT   DIO_u8_PORTA
#define LCD_D1_PIN    DIO_u8_PIN6

#define LCD_D2_PORT   DIO_u8_PORTA
#define LCD_D2_PIN    DIO_u8_PIN5

#define LCD_D3_PORT   DIO_u8_PORTA
#define LCD_D3_PIN    DIO_u8_PIN4

#define LCD_D4_PORT   DIO_u8_PORTA
#define LCD_D4_PIN    DIO_u8_PIN3

#define LCD_D5_PORT   DIO_u8_PORTA
#define LCD_D5_PIN    DIO_u8_PIN2

#define LCD_D6_PORT   DIO_u8_PORTA
#define LCD_D6_PIN    DIO_u8_PIN1

#define LCD_D7_PORT   DIO_u8_PORTA
#define LCD_D7_PIN    DIO_u8_PIN0

// Define your port and pin numbers for Backlight Pin
#define LCD_BACKLIGHT_PORT
#define LCD_BACKLIGHT_PIN


// Define your structure here


#endif /* HAL_LCD_LCD_CFG_H_ */
