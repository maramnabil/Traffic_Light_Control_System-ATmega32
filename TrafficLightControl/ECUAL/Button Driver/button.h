/*
 * button.h
 *
 * Created: 9/2/2022 7:23:00 PM
 *  Author: hp
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
/************************************************************************/
/* Include files                                                        */
/************************************************************************/
#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Library/interrupts.h"

/************************************************************************/
/* Button Port and Pin Macros                                               */
/************************************************************************/
#define BUTTON_PORT PORT_D
#define BUTTON_PIN PIN2


/************************************************************************/
/* Needed Typedefs                                                      */
/************************************************************************/
//typedef enum BUTTON_DOUBLE_PRESSED{
	//DOUBLE_PRESSED,
	//NOT_DOUBLE_PRESSED
	//}BUTTON_DOUBLE_PRESSED;

/************************************************************************/
/* Return States                                                        */
/************************************************************************/
typedef enum BUTTON_ERROR_STATE{
	BUTTON_ERROR,
	BUTTON_OK
}BUTTON_ERROR_STATE;

/************************************************************************/
/* Global Variables                                                     */
/************************************************************************/
//int buttonPressed;

/************************************************************************/
/* Function Prototypes                                                  */
/************************************************************************/
BUTTON_ERROR_STATE Button_init(uint8_t ButtonPort, uint8_t ButtonPin); // initialize button pin

#endif /* BUTTON_H_ */