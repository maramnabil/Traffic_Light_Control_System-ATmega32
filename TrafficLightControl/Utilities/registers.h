/*
 * registers.h
 *
 * Created: 9/2/2022 7:30:43 PM
 *  Author: hp
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

// All internal register macros

/************************************************************************/
/* Registers Addresses Macros                                           */
/************************************************************************/
// PORTA
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

// PORTB
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

// PORTD
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

/************************************************************************/
/* TIMER0 Registers Addresses Macros                                                                     */
/************************************************************************/
// TCCR0   --> 0x53
#define TCCR0 *((volatile uint8_t*)0x53)
// TCNT0   --> 0x52
#define TCNT0 *((volatile uint8_t*)0x52)
// TIFR    --> 0x58
#define TIFR *((volatile uint8_t*)0x58)

/************************************************************************/
/* External Interrupts Registers                                                  */
/************************************************************************/
#define GICR *((volatile uint8_t*)0x5B)
#define GIFR *((volatile uint8_t*)0x5A)
#define MCUCR *((volatile uint8_t*)0x55)
#define MCUCSR *((volatile uint8_t*)0x54)

/************************************************************************/
/* Ports Macros                                                     */
/************************************************************************/
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_D 'D'


#endif /* REGISTERS_H_ */