/*
 * app.h
 *
 * Created: 9/2/2022 4:11:00 AM
 *  Author: hp
 */ 


#ifndef APP_H_
#define APP_H_
#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/led.h"
/************************************************************************/
/* Return States Typedefs                                               */
/************************************************************************/
typedef enum APP_ERROR_STATE {
	APP_OK,
	APP_ERROR
}APP_ERROR_STATE;

/************************************************************************/
/* Functions Prototypes                                                 */
/************************************************************************/
APP_ERROR_STATE APP_init(); // initialize the application

APP_ERROR_STATE APP_start(); // start the application

//int normalMode;

#endif /* APP_H_ */