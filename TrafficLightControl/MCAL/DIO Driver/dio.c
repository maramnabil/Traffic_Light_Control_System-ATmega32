/*
 * dio.c
 *
 * Created: 9/2/2022 7:12:56 PM
 *  Author: hp
 */ 
#include "dio.h"
/************************************************************************/
/* Functions Implementations                                            */
/************************************************************************/
// initialize pin direction
DIO_ERROR_STATE DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction) {
	/*
		1. Check for the input port number.
		   1.1 If it's port A, check the direction.
		       1.1.1 If it's an output, set the DDRA register by 1 at the pinNumber and check if it's set successfully.
					 1.1.1.1 If it's set, return DIO_OK.
					 1.1.1.2 Else, return DIO_ERROR.
			   1.1.2 If it's an input, clear the DDRA register at the pinNumber and check if it's cleared successfully.
					 1.1.2.1 If it's cleared, return DIO_OK.
					 1.1.2.2 Else, return DIO_ERROR.
			   1.1.3 If the direction was something else, return DIO_ERROR.
		   1.2 Repeat the previous logic for the other ports (the used ports in this project are PORTA, PORTB and PORTD).
	*/
	switch(portNumber) {
		case PORT_A:
			if (direction == OUT) {
				DDRA |= (1<<pinNumber);
				if (((DDRA>>pinNumber)&1) == OUT)
					return DIO_OK;
				else
					return DIO_ERROR;
			} else if (direction == IN) {
				DDRA &= ~(1<<pinNumber);
				if (((DDRA>>pinNumber)&1) == IN)
					return DIO_OK;
				else
					return DIO_ERROR;
			} else {
				return DIO_ERROR;
			}
		case PORT_B:
			if (direction == OUT) {
				DDRB |= (1<<pinNumber);
				if (((DDRB>>pinNumber)&1) == OUT)
					return DIO_OK;
				else
					return DIO_ERROR;
				} else if (direction == IN) {
				DDRB &= ~(1<<pinNumber);
				if (((DDRB>>pinNumber)&1) == IN)
					return DIO_OK;
				else
					return DIO_ERROR;
			} else {
				return DIO_ERROR;
			}
		case PORT_D:
			if (direction == OUT) {
				DDRD |= (1<<pinNumber);
				if (((DDRD>>pinNumber)&1) == OUT)
					return DIO_OK;
				else
					return DIO_ERROR;
				} else if (direction == IN) {
				DDRD &= ~(1<<pinNumber);
				if (((DDRD>>pinNumber)&1) == IN)
					return DIO_OK;
				else
					return DIO_ERROR;
			} else {
				return DIO_ERROR;
			}
		default:
			return DIO_ERROR;
	}
}
// write data to dio
DIO_ERROR_STATE DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value) {
	/*
		1. Check for the input port number.
			1.1 If it's port A, check the value.
				1.1.1 If it's high, set the PORTA register by 1 at the pinNumber and check if it's set successfully by reading the PINA register at the specified pin.
					1.1.1.1 If it's set, return DIO_OK.
					1.1.1.2 Else, return DIO_ERROR.
				1.1.2 If it's low, clear the PORTA register at the pinNumber and check if it's cleared successfully by reading the PINA register at the specified pin.
					1.1.2.1 If it's cleared, return DIO_OK.
					1.1.2.2 Else, return DIO_ERROR.
				1.1.3 If the value was something else, return DIO_ERROR.
		1.2 Repeat the previous logic for the other ports (the used ports in this project are PORTA, PORTB and PORTD).
	*/
	switch (portNumber) {
		case PORT_A:
			if (value == HIGH) {
				PORTA |= (1<<pinNumber);
				if (((PINA>>pinNumber)&1) == HIGH)
					return DIO_OK;
				else
					return DIO_ERROR;
			} else if (value == LOW) {
				PORTA &= ~(1<<pinNumber);
				if (((PINA>>pinNumber)&1) == LOW)
					return DIO_OK;
				else
					return DIO_ERROR;
			} else {
				return DIO_ERROR;
			}
		case PORT_B:
			if (value == HIGH) {
				PORTB |= (1<<pinNumber);
				if (((PINB>>pinNumber)&1) == HIGH)
					return DIO_OK;
				else
					return DIO_ERROR;
				} else if (value == LOW) {
				PORTB &= ~(1<<pinNumber);
				if (((PINB>>pinNumber)&1) == LOW)
					return DIO_OK;
				else
					return DIO_ERROR;
				} else {
				return DIO_ERROR;
			}
		case PORT_D:
			if (value == HIGH) {
				PORTD |= (1<<pinNumber);
				if (((PIND>>pinNumber)&1) == HIGH)
					return DIO_OK;
				else
					return DIO_ERROR;
				} else if (value == LOW) {
				PORTD &= ~(1<<pinNumber);
				if (((PIND>>pinNumber)&1) == LOW)
					return DIO_OK;
				else
					return DIO_ERROR;
				} else {
				return DIO_ERROR;
			}
		default:
			return DIO_ERROR;
	}
}
// read data from dio
DIO_ERROR_STATE DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value) {
	/*
		1. Check for the input port number.
			1.1 If it's port A, read the required pin number and save the value in the *value pointer variable, then return DIO_OK.
			1.2 Repeat the previous logic for the other used ports.
		2. If the input portNumber was something that's not used (not PORTA, PORTB or PORTD), return DIO_ERROR.
	*/
	switch (portNumber) {
		case PORT_A:
			*value = ((PINA & (1<<pinNumber))>>pinNumber);
			return DIO_OK;
		case PORT_B:
			*value = ((PINB & (1<<pinNumber))>>pinNumber);
			return DIO_OK;
		case PORT_D:
			*value = ((PINB & (1<<pinNumber))>>pinNumber);
			return DIO_OK;
		default:
			return DIO_ERROR;
	}
}
// toggle dio value
DIO_ERROR_STATE DIO_toggle(uint8_t portNumber, uint8_t pinNumber) {
	/*
		1. Check for the input port number.
			1.1 If it's port A, toggle the required pin number, then return DIO_OK.
			1.2 Repeat the previous logic for the other used ports (PORTA, PORTB and PORTD).
		2. If the input portNumber was something that's not used (not PORTA, PORTB or PORTD), return DIO_ERROR.
	*/
	switch (portNumber) {
		case PORT_A:
			PORTA ^= (1<<pinNumber);
			return DIO_OK;
		case PORT_B:
			PORTB ^= (1<<pinNumber);
			return DIO_OK;
		case PORT_D:
			PORTD ^= (1<<pinNumber);
			return DIO_OK;
		default:
			return DIO_ERROR;
	}
}