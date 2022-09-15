/*
 * interrupts.h
 *
 * Created: 9/2/2022 8:51:16 PM
 *  Author: hp
 */ 

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../../Utilities/registers.h"
/************************************************************************/
/*                    Interrupts Vectors                                */
/************************************************************************/
/* External Interrupt Request 0 */
#define INT0_vect __vector_1
/* Interrupt 0 Port */
#define EXT_INT0_PORT PORT_D
/* Interrupt0 Pin Number Macro */
#define INT0 6
#define INTF0 6

/************************************************************************/
/* Set Global Interrupts - Set the I-bit in status register to 1        */
/************************************************************************/
#define sei() __asm__ __volatile__ ("sei" ::: "memory")
/************************************************************************/
/* Clear Global Interrupts - Set the I-bit in status register to 0      */
/************************************************************************/
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/*ISR Definition*/
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)


#endif /* INTERRUPTS_H_ */