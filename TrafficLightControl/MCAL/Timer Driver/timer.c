/*
 * timer.c
 *
 * Created: 9/10/2022 11:39:43 AM
 *  Author: hp
 */ 
#include "timer.h"
/************************************************************************/
/* Timer0 Functions Implementation                                      */
/************************************************************************/

// Timer initialization with input initial value
void timer0_init(uint8_t initialValue) {
	/************************************************************************/
	/* 1. Choose timer mode (normal mode).
	   2. Set timer initial value with the input parameter.                 */
	/************************************************************************/
	// Choose timer mode
	TCCR0 = 0x00; // Normal mode
	// Timer set initial value
	TCNT0 = initialValue;
}
// Calculate number of needed timer overflows for the given input delay
uint32_t NumberOfOverflows(double delayInMs) {
	/************************************************************************/
	/* 1. Multiply the delay (in ms) by 0.001 to convert it into seconds.
	   2. Divide the result by the maximum delay calculated from the TMAX macro.
	   3. Add 1 to the result then cast it to uint32_t to get the ceiling of the result. */
	/************************************************************************/
	return (uint32_t)((delayInMs*0.001)/TMAX)+1;
}
// Delay for a given input number of milliseconds
void _delay_ms(double milliSeconds) {
	/************************************************************************/
	/* 1. Set timer initial value to 0 (as the needed delays in this program can all start the timer from 0).
	   2. Create a variable to count the number of timer overflows.
	   3. Call the function NumberOfOverflows to return the needed number of overflows and store the result in a variable n.
	   4. Start the timer with the needed prescaler (I used no prescaler as the needed delays in this program don't need a prescaler).
	   5. Count the number of overflows and check in each overflow for the timer overflow flag.
	   6. After each timer overflow, clear the overflow flag and increment the overflow counter by 1.
	   7. After the number of overflows is completed, stop the timer.       */
	/************************************************************************/
	timer0_init(0); // set timer initial value = 0
	uint32_t overflowCounter = 0;
	uint32_t n = NumberOfOverflows(milliSeconds);
	/*Timer start -> setting the clock source (internal)*/
	TCCR0 |= (1<<0); // No prescaler
	while (overflowCounter < n) {
		// Wait until the overflow flag is set
		while((TIFR & (1<<0))==0); // wait for timer flag or interrupt flag to be set ..   && ((GIFR>>INTF0)&1 == 0)
		// Clear the overflow flag
		TIFR |= (1<<0);
		overflowCounter++;
	}
	// Timer stop
	TCCR0 = 0x00;
}