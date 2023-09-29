/*
 * DIO_prv.h
 *
 * Yousef-Alsayed-Abdelfattah
 */

#ifndef MCAL_DIO_DRIVER_DIO_PRV_H_
#define MCAL_DIO_DRIVER_DIO_PRV_H_

// Register addresses for PORTA, DDRA, and PINA
#define DIO_u8_PORTA_REG (*(volatile u8*)0x3B)
#define DIO_u8_DDRA_REG (*(volatile u8*)0x3A)
#define DIO_u8_PINA_REG (*(volatile u8*)0x39)

// Register addresses for PORTB, DDRB, and PINB (Unique addresses)
#define DIO_u8_PORTB_REG (*(volatile u8*)0x38)
#define DIO_u8_DDRB_REG (*(volatile u8*)0x37)
#define DIO_u8_PINB_REG (*(volatile u8*)0x36)

// Register addresses for PORTC, DDRC, and PINC (Unique addresses)
#define DIO_u8_PORTC_REG (*(volatile u8*)0x35)
#define DIO_u8_DDRC_REG (*(volatile u8*)0x34)
#define DIO_u8_PINC_REG (*(volatile u8*)0x33)

// Register addresses for PORTD, DDRD, and PIND (Unique addresses)
#define DIO_u8_PORTD_REG (*(volatile u8*)0x32)
#define DIO_u8_DDRD_REG (*(volatile u8*)0x31)
#define DIO_u8_PIND_REG (*(volatile u8*)0x30)

// Define NULL pointer
#define NULL ((void*)0)

#endif /* MCAL_DIO_DRIVER_DIO_PRV_H_ */
