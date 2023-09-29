#include "DcMotor_int.h"

// Initialize the motor pins
void DcMotor_Init(void)
{
    // Set the motor pins as output
    DIO_enuSetPinDirection(MOTOR_PIN1_PORT, MOTOR_PIN1, DIO_u8_OUTPUT);
    DIO_enuSetPinDirection(MOTOR_PIN2_PORT, MOTOR_PIN2, DIO_u8_OUTPUT);

    // Initially, stop the motor
    DIO_enuSetPinValue(MOTOR_PIN1_PORT, MOTOR_PIN1, DIO_u8_LOW);
    DIO_enuSetPinValue(MOTOR_PIN2_PORT, MOTOR_PIN2, DIO_u8_LOW);
}

// Control the motor direction
void DcMotor_SetDirection(u8 direction)
{
    switch (direction)
    {
    case STOP:
        // Set both motor pins low to stop the motor
        DIO_enuSetPinValue(MOTOR_PIN1_PORT, MOTOR_PIN1, DIO_u8_LOW);
        DIO_enuSetPinValue(MOTOR_PIN2_PORT, MOTOR_PIN2, DIO_u8_LOW);
        break;
    case CLOCKWISE:
        // Set motor pin1 low and pin2 high to rotate clockwise
        DIO_enuSetPinValue(MOTOR_PIN1_PORT, MOTOR_PIN1, DIO_u8_LOW);
        DIO_enuSetPinValue(MOTOR_PIN2_PORT, MOTOR_PIN2, DIO_u8_HIGH);
        break;
    case ANTICLOCKWISE:
        // Set motor pin1 high and pin2 low to rotate anticlockwise
        DIO_enuSetPinValue(MOTOR_PIN1_PORT, MOTOR_PIN1, DIO_u8_HIGH);
        DIO_enuSetPinValue(MOTOR_PIN2_PORT, MOTOR_PIN2, DIO_u8_LOW);
        break;
    }
}

// Stop the motor
void DcMotor_Stop(void)
{
    // Stop the motor by setting both motor pins low
    DIO_enuSetPinValue(MOTOR_PIN1_PORT, MOTOR_PIN1, DIO_u8_LOW);
    DIO_enuSetPinValue(MOTOR_PIN2_PORT, MOTOR_PIN2, DIO_u8_LOW);
}
