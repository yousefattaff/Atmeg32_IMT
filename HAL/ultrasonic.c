#include <avr/interrupt.h>
#include <util/delay.h>
#include "ultrasonic.h"
static volatile int pulse = 0;
static volatile int i = 0;

ISR(INT0_vect)
{
    if (i == 0)
    {
        TCCR1B |= (1 << CS10); // Start Timer1 with no prescaler
        i = 1;
    }
    else
    {
        TCCR1B = 0; // Stop Timer1
        pulse = TCNT1; // Save the pulse duration
        TCNT1 = 0; // Reset Timer1
        i = 0;
    }
}

void initializeDistanceMeasurement()
{
	DDRD = 0b11111011; // Configure PIND0 (INT0 pin) as input
    _delay_ms(50);
    GICR |= (1 << INT0); // Enable external interrupt INT0
    MCUCR |= (1 << ISC00); // Trigger INT0 on any logical change
    sei(); // Enable global interrupts
}

int16_t measureDistance()
{
    PORTD |= (1 << PIND0); // Generate trigger pulse
    _delay_us(15);
    PORTD &= ~(1 << PIND0);

    return pulse / 466.47; // Convert pulse duration to distance in centimeters
}
