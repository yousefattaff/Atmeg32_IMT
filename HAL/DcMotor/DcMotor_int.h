
#ifndef HAL_DCMOTOR_DCMOTOR_INT_H_
#define HAL_DCMOTOR_DCMOTOR_INT_H_

#include "../../MCAL/DIO/DIO_int.h"

// Define the pins connected to the motor driver
#define MOTOR_PIN1 DIO_u8_PIN0
#define MOTOR_PIN2 DIO_u8_PIN1


#define MOTOR_PIN1_PORT DIO_u8_PORTA
#define MOTOR_PIN2_PORT DIO_u8_PORTA


// Define motor directions
#define STOP 0
#define CLOCKWISE 1
#define ANTICLOCKWISE 2

/**
 * Function name: DcMotor_Init
 * Description: Initializes the DC motor driver.
 * Inputs: None
 * Returns: None
 */
void DcMotor_Init(void);

/**
 * Function name: DcMotor_SetDirection
 * Description: Control the direction of the DC motor.
 * Inputs:
 *   - u8 direction: The desired direction (CLOCKWISE, or ANTICLOCKWISE).
 * Returns: None
 */
void DcMotor_SetDirection(u8 direction);

/**
 * Function name: DcMotor_Stop
 * Description: Stops the DC motor.
 * Inputs: None
 * Returns: None
 */
void DcMotor_Stop(void);


#endif /* HAL_DCMOTOR_DCMOTOR_INT_H_ */
