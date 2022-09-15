/*
 * isr.c
 *
 * Created: 9/14/2022 4:42:59 AM
 *  Author: hp
 */ 
#include "../LED Driver/led.h"
/************************************************************************/
/* Interrupt 0 ISR implementation                                       */
/************************************************************************/

ISR(INT0_vect) {
	/************************************************************************/
	/* 1. Check if which traffic LED is on/blinking when the button is pressed.
	      1.1 If the green LED was on or the yellow LED was blinking:
				- The cars yellow and pedestrian red LEDs are off.
				- The pedestrian red LED is on for 1 second
				- The pedestrian red and cars green LEDs are off (to make sure they aren't left on).
				- The cars yellow and pedestrian yellow LEDs blink for 5 seconds
				- The cars red and pedestrian green LEDs are on for 5 seconds.
			1.2 If the red LED was on:
				- The cars red and pedestrian green LEDs are still on for 5 seconds.
	    2. The cars red LED is off.
		3. The two yellow LEDs blink for 5 seconds.
		4. The pedestrian green LED is off.
		5. The cars green and pedestrian red LEDs are on for 5 seconds.
		6. The system returns to the normal mode by calling the main function. (it doesn't 
		return by itself because probably a stack overflow occurs which prevents it from 
		returning back to the main on its own, so I have to call it manually).*/
	/************************************************************************/
	if (getOnLED() == CAR_GREEN_LED || getOnLED() == CAR_YELLOW_LED) {
		LED_off(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
		LED_off(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
		LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
		_delay_ms(1000);
		LED_off(PED_RED_LED_PORT, PED_RED_LED_PIN);
		LED_off(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
		two_LEDs_blink(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN, 5000);
		LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
		LED_on(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
		_delay_ms(5000);
		
		} else if (getOnLED() == CAR_RED_LED) {
		LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
		LED_on(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
		_delay_ms(5000);
	}
	LED_off(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	two_LEDs_blink(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN, 5000);
	LED_off(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
	LED_on(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
	LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
	main();
}