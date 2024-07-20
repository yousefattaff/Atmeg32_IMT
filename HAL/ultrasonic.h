/*
 * ultrasonic.h
 *
 *  Created on: Feb 12, 2024
 *      Author: youse
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_

#include <avr/io.h>

void initializeDistanceMeasurement();
int16_t measureDistance();

#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
