/*
 * Seven_Segement_cfg.h
 *
 *  Created on: Sep 17, 2023
 *      Author: youse
 */

#ifndef HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_CFG_H_
#define HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_CFG_H_

#define SEGMENT_A   DIO_u8_PIN6
#define SEGMENT_B   DIO_u8_PIN5
#define SEGMENT_C   DIO_u8_PIN4
#define SEGMENT_D   DIO_u8_PIN3
#define SEGMENT_E   DIO_u8_PIN2
#define SEGMENT_F   DIO_u8_PIN1
#define SEGMENT_G   DIO_u8_PIN0

#define SEGMENT_A_PORT    DIO_u8_PORTB
#define SEGMENT_B_PORT    DIO_u8_PORTB
#define SEGMENT_C_PORT    DIO_u8_PORTB
#define SEGMENT_D_PORT    DIO_u8_PORTB
#define SEGMENT_E_PORT    DIO_u8_PORTB
#define SEGMENT_F_PORT    DIO_u8_PORTB
#define SEGMENT_G_PORT    DIO_u8_PORTB


#define Anode1_Cathode0       1      // make it 1 if the seven segment is common anode, 0 if it's common cathode

#endif /* HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_CFG_H_ */
