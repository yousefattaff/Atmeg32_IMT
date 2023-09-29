

#ifndef HAL_STEPPERMOTOR_STEPPERMOTOR_INT_H_
#define HAL_STEPPERMOTOR_STEPPERMOTOR_INT_H_

#include "steppermotor_prv.h"
#include "steppermotor_cfg.h"

typedef enum
{
	STEPPER_OK,
	STEPPER_NOK
}StepperM_tenuErrorStatus;


/*
 * Function name: Stepper_Rotate
 * Description: Rotate the stepper motor to a specified angle and direction.
 * Inputs:
 *   - u32 Copy_u8Angle: The desired angle to rotate to (in degrees).
 *   - u8 Copy_u8Direction: The rotation direction (STEPPERM_DIRECTION_CW for clockwise or STEPPERM_DIRECTION_ACW for anticlockwise).
 *   - u16 Copy_u16TimeInMs: The time to complete the rotation (in milliseconds).
 * Returns:
 *   - StepperM_tenuErrorStatus: STEPPER_OK if the operation was successful, STEPPERM_NOK otherwise.
 */
StepperM_tenuErrorStatus Stepper_Rotate(u32 Copy_u8Angle, u8 Copy_u8Direction, u16 Copy_u16TimeInMs);


#define STEPPER_u8_CW 0
#define STEPPER_u8_ACW 1


#endif /* HAL_STEPPERMOTOR_STEPPERMOTOR_INT_H_ */
