/*
 * timer.h
 *
 * Created: 9/10/2022 11:30:13 AM
 *  Author: hp
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"
#include "../Interrupt Library/interrupts.h"

//uint8_t interrupt0On;

/************************************************************************/
/* Function-like Macros                                                 */
/************************************************************************/
#define TMAX (256.0/1000000) // Calculate the maximum delay, ((2^8 * 1) / 1MHz) 8: number of timer register bits, 1000000: CPU frequency (prescaler = 1)

/************************************************************************/
/* Functions Prototypes                                                 */
/************************************************************************/
void timer0_init(uint8_t initialValue); // initialize timer with initial value

void _delay_ms(double milliSeconds); // delay for input milliseconds

uint32_t NumberOfOverflows(double delayInMs); // calculate number of overflows for the required input delay


#endif /* TIMER_H_ */