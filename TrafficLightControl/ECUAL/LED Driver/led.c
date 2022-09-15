/*
 * led.c
 *
 * Created: 9/2/2022 7:22:52 PM
 *  Author: hp
 */ 
#include "led.h"

// Initialize global variables
isBlinking = 0;

/************************************************************************/
/* Functions Implementations                                            */
/************************************************************************/
// initialize led pin
LED_ERROR_STATE LED_init(uint8_t ledPort, uint8_t ledPin) {
	/*
		1. Initialize LED DIO (using the given port and pin) to output.
		2. Check for the initialization error, if DIO_init returns an error, return LED_ERROR.
		3. If it returns DIO_OK, return LED_OK.
	*/
	// initialize LED DIO
	int errorState = DIO_init(ledPort, ledPin, OUT);
	// check if the initialization was correct
	if (errorState == DIO_ERROR) {
		return LED_ERROR;
	} else if (errorState == DIO_OK) {
		return LED_OK;
	}
}
// turn on the led
LED_ERROR_STATE LED_on(uint8_t ledPort, uint8_t ledPin) {
	/*
		1. Write High on the required pin in the required port to turn on the required led.
		2. If the write function returns an error, then return an LED_ERROR.
		3. Else, return LED_OK.
	*/
	int errorState = DIO_write(ledPort, ledPin, HIGH);
	if (errorState == DIO_ERROR) {
		return LED_ERROR;
	} else if (errorState == DIO_OK) {
		return LED_OK;
	}
}
// turn off the led
LED_ERROR_STATE LED_off(uint8_t ledPort, uint8_t ledPin) {
	/*
		1. Write LOW on the required pin in the required port to turn off the required led.
		2. If the write function returns an error, then return an LED_ERROR.
		3. Else, return LED_OK.
	*/
	int errorState = DIO_write(ledPort, ledPin, LOW);
	if (errorState == DIO_ERROR) {
		return LED_ERROR;
	} else if (errorState == DIO_OK) {
		return LED_OK;
	}
}
// toggle the led value
LED_ERROR_STATE LED_toggle(uint8_t ledPort, uint8_t ledPin) {
	/*
		1. Toggle the required pin in the required port to turn off the required led if it was on, or to turn it on if it was off.
		2. If the DIO_toggle function returns an error, then return an LED_ERROR.
		3. Else, return LED_OK.
	*/
	int errorState = DIO_toggle(ledPort, ledPin);
	if (errorState == DIO_ERROR) {
		return LED_ERROR;
	} else if (errorState == DIO_OK) {
		return LED_OK;
	}
}
// Blink two leds together for a given time
LED_ERROR_STATE two_LEDs_blink(uint8_t ledPort1, uint8_t ledPin1, uint8_t ledPort2, uint8_t ledPin2, uint16_t delayMilli) {
	/*
		1. Initialize timer 0
		2. Set the isBlinking flag to 1 (to indicate there is a blinking led right now).
		3. Delay for "delayMilli" milliseconds and toggle the two given leds through them with delay 200ms.
		4. After the timer is off, clear the isBlinking flag.
		5. Check for the errors in the LED_off functions, if any one returns an error, return error.
	*/
	/* initialize timer0 */
	timer0_init(0); // initial value = 0
	/* Setting the isBlinking flag */
	isBlinking = 1;
	/* Delay for 5 seconds (if delayMilli = 5000) and toggle the led through them */
	int i;
	for (i = 0; i <(delayMilli/200); i++) {  // delayMilli / 200ms = number of loops needed to delay for delayMilli time period
		LED_toggle(ledPort1, ledPin1);
		LED_toggle(ledPort2, ledPin2);
		_delay_ms(200);
	}
	/* Turn off the blinking LED */
	int errorState1 = LED_off(ledPort1, ledPin1);
	int errorState2 = LED_off(ledPort2, ledPin2);
	/* Turn off the isBlinking flag */
	isBlinking = 0;
	
	/* Return the errorState value */
	return errorState1 && errorState2;
}
// get the state of the led, on, off or blinking
LED_STATE getLEDState(uint8_t ledPort, uint8_t ledPin) {
	/*
		1. Read the pin of the required led and save it in the *value variable.
		2. Check for the isBlinking flag, if it's set, then return BLINKING (because there is a blinking led right now).
		3. If the value of the led is high, return ON.
		4. If it's low, return OFF.
	*/
	uint8_t* value;
	DIO_read(ledPort, ledPin, value);
	if (isBlinking == 1) {
		return BLINKING;
	} else if (*value == HIGH) {
		return ON;
	} else if (*value == LOW) {
		return OFF;
	}
}
// get the on/blinking led right now
ON_LED getOnLED() {
	/*
		1. Check if the cars green led is on, then return the car green led.
		2. Else if the cars yellow led is blinking (it can't be on, it only blinks), then return car yellow led.
		3. Else if the cars red led is on, return car red led.
	*/
	if (getLEDState(CAR_GREEN_LED_PORT, CAR_GREEN_LED_PIN) == ON) {
		return CAR_GREEN_LED;
	} else if (getLEDState(CAR_YELLOW_LED_PORT, CAR_YELLOW_LED_PIN) == BLINKING) {
		return CAR_YELLOW_LED;
	} else if (getLEDState(CAR_RED_LED_PORT, CAR_RED_LED_PIN) == ON) {
		return CAR_RED_LED;
	}
}
