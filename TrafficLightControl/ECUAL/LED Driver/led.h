/*
 * led.h
 *
 * Created: 9/2/2022 7:22:43 PM
 *  Author: hp
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"

/************************************************************************/
/* Needed Typedefs and Return States                                                        */
/************************************************************************/
typedef enum LED_ERROR_STATE{
	LED_ERROR,
	LED_OK
	}LED_ERROR_STATE;

typedef enum ON_LED{
	CAR_GREEN_LED,
	CAR_YELLOW_LED,
	CAR_RED_LED
}ON_LED;

typedef enum LED_STATE {
	ON,
	OFF,
	BLINKING
}LED_STATE;
/************************************************************************/
/* LEDs Ports and Pins Macros                                                     */
/************************************************************************/
// ports
#define CAR_GREEN_LED_PORT 'A'
#define CAR_YELLOW_LED_PORT 'A'
#define CAR_RED_LED_PORT 'A'
#define PED_GREEN_LED_PORT 'B'
#define PED_YELLOW_LED_PORT 'B'
#define PED_RED_LED_PORT 'B'

// cars and pedestrians pins
#define CAR_GREEN_LED_PIN 0
#define CAR_YELLOW_LED_PIN 1
#define CAR_RED_LED_PIN 2
#define PED_GREEN_LED_PIN 0
#define PED_YELLOW_LED_PIN 1
#define PED_RED_LED_PIN 2

/************************************************************************/
/* Global variables                                                     */
/************************************************************************/ 
int isBlinking; // Flag for checking if an LED is blinking

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/
LED_ERROR_STATE LED_init(uint8_t ledPort, uint8_t ledPin); // initialize led pin

LED_ERROR_STATE LED_on(uint8_t ledPort, uint8_t ledPin); // turn on the led

LED_ERROR_STATE LED_off(uint8_t ledPort, uint8_t ledPin); // turn off the led

LED_ERROR_STATE LED_toggle(uint8_t ledPort, uint8_t ledPin); // toggle the led value

LED_ERROR_STATE two_LEDs_blink(uint8_t ledPort1, uint8_t ledPin1, uint8_t ledPort2, uint8_t ledPin2, uint16_t delayMilli); // Blink two leds together for a given time

LED_STATE getLEDState(uint8_t ledPort, uint8_t ledPin); // get the state of the led, on, off or blinking

ON_LED getOnLED(); // get the on/blinking LED of the cars LEDs right now

#endif /* LED_H_ */