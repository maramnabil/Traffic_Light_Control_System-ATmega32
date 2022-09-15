/*
 * app.c
 *
 * Created: 9/2/2022 8:08:01 PM
 *  Author: hp
 */ 
#include "app.h"
//volatile uint8_t normalMode;

// initialize the application
APP_ERROR_STATE APP_init() {
	/*
		1. Initialize the button and the interrupt.
		2. Initialize all the cars and pedestrian LEDs pins as outputs.
	*/
	/* Button and Interrupt initialization */
	int buttonErrorState = Button_init(BUTTON_PORT, BUTTON_PIN);
	/* LEDs initialization */
	int carGreenLEDErrorState = LED_init(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN); // Car green led initialization
	int carYellowLEDErrorState = LED_init(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN); // Car yellow led initialization
	int carRedLEDErrorState = LED_init(CAR_RED_LED_PORT, CAR_RED_LED_PIN); // Car red led initialization
	int pedGreenLEDErrorState = LED_init(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN); // Pedestrian green led initialization
	int pedYellowLEDErrorState = LED_init(PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN); // Pedestrian yellow led initialization
	int pedRedLEDErrorState = LED_init(PED_RED_LED_PORT, PED_RED_LED_PIN); // Pedestrian red led initialization
	if (buttonErrorState == BUTTON_OK && carGreenLEDErrorState == LED_OK && carYellowLEDErrorState == LED_OK && 
	carRedLEDErrorState == LED_OK && pedGreenLEDErrorState == LED_OK &&	pedYellowLEDErrorState == LED_OK &&
	pedRedLEDErrorState == LED_OK) {
		return APP_OK;
	} else
		return APP_ERROR;
	/* Initializing normalMode flag by 1 */
	//buttonPressed = 0;
	//normalMode = buttonPressed == 0 ? 1 : 0;
	//interrupt0On = 0;
	//normalMode = 1;
}

APP_ERROR_STATE APP_start() {
	/*
		* The normal mode:
		1. Turn on the cars green and pedestrian red LEDs for 5 seconds.
		2. Turn them off, and blink the cars and pedestrian yellow LEDs together for 5 seconds.
		3. Turn on the cars red and pedestrian green LEDs for 5 seconds.
		4. Turn them off, and blink the cars and pedestrian yellow LEDs together for 5 seconds.
		5. Repeat the procedure from the beginning until the pedestrian button is pressed (the interrupt occurs).
	*/
	while (1) {
		int carGreenLEDOnError = LED_on(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
		int pedRedLEDOnError = LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
		_delay_ms(5000);
		int carGreenLEDOffError = LED_off(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN);
		int pedRedLEDOffError = LED_off(PED_RED_LED_PORT, PED_RED_LED_PIN);
		int twoLEDsBlinkError1 = two_LEDs_blink(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN, 5000);
		int carRedLEDOnError = LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
		int pedGreenLEDOnError = LED_on(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
		_delay_ms(5000);
		int carRedLEDOffError = LED_off(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
		int pedGreenLEDOffError = LED_off(PED_GREEN_LED_PORT, PED_GREEN_LED_PIN);
		int twoLEDsBlinkError2 = two_LEDs_blink(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN, PED_YELLOW_LED_PORT, PED_YELLOW_LED_PIN, 5000);
		if (carGreenLEDOnError == LED_ERROR || pedRedLEDOnError == LED_ERROR || carGreenLEDOffError == LED_ERROR || 
		pedRedLEDOffError == LED_ERROR || twoLEDsBlinkError1 == LED_ERROR || carRedLEDOnError == LED_ERROR || 
		pedGreenLEDOnError == LED_ERROR || carRedLEDOffError == LED_ERROR || pedGreenLEDOffError == LED_ERROR || 
		twoLEDsBlinkError2 == LED_ERROR)
			return APP_ERROR;
	}
}

//ISR(INT0_vect) {
	//normalMode = 0;
	//interrupt0On = 1;
//}