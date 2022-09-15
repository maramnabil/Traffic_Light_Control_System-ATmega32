/*
 * button.c
 *
 * Created: 9/2/2022 7:23:08 PM
 *  Author: hp
 */ 
#include "button.h"
// initialize button pin
BUTTON_ERROR_STATE Button_init(uint8_t ButtonPort, uint8_t ButtonPin) {
	/*
		1. Initialize the required button pin as an input, and return the initialization error state into the returnState variable.
		2. Initialize interrupt 0 (as this button works with interrupt).
			2.1 Enable global interrupts.
			2.2 Choose the interrupt sense (rising edge).
			2.3 Enable interrupt 0 (the used interrupt for the button)
		3. Check if there is an error in the button initialization, return error.
		4. Else return ok.
	*/
	/* Button Initialization */
	int returnState = DIO_init(ButtonPort, ButtonPin, IN);
	//buttonPressed = 0; // clearing the buttonPressed flag
	/* Interrupt Initialization */
	sei(); // Enable global interrupt
	MCUCR |= 0X03; // rising edge sense
	GICR |= (1<<INT0); // Enable interrupt 0
	/* Error Checking */
	if (returnState == DIO_ERROR) {
		return BUTTON_ERROR;
	} else if (returnState == DIO_OK) {
		return BUTTON_OK;
	} else {
		return BUTTON_ERROR;
	}
}