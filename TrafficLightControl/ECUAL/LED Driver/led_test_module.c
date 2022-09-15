/*
 * led_test_module.c
 *
 * Created: 9/15/2022 5:26:41 AM
 *  Author: hp
 */ 
#if 0
#include "led.h"

int main() {
	// LEDs initialization
	LED_init(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
	LED_init(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN);
	LED_init(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
	LED_init(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
	LED_init(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN);
	LED_init(PED_RED_LED_PORT, PED_RED_LED_PIN);
	
	while (1) {
		/* Test LED_on, LED_toggle, LED_off, and two_LEDs_blink functions */
		// Turn on car green LED, and turn on car red LED for 1 second
		LED_on(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
		LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
		_delay_ms(1000);
		LED_off(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
		// Toggle the pedestrian green LED
		LED_toggle(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
		// Blink the two yellow LEDs for 2 seconds
		two_LEDs_blink(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN, 2000);	
		
		
		///* Test getLEDState function */
		//LED_on(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
		//int carGreenLEDState = getLEDState(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
		//if (carGreenLEDState == ON) {
			//LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
		//}
		
		///* Test getOnLED function */
		//LED_on(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
		//int onLED = getOnLED();
		//if (onLED == CAR_GREEN_LED) {
			//LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
		//}
	}
	return 0;
}

#endif