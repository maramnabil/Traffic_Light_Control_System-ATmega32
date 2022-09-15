/*
 * dio.h
 *
 * Created: 9/2/2022 7:12:47 PM
 *  Author: hp
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

// All registers functions prototypes

/************************************************************************/
/* Return States                                                        */
/************************************************************************/
typedef enum DIO_ERROR_STATE{
	DIO_ERROR = 0,
	DIO_OK = 1
	}DIO_ERROR_STATE;

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/

DIO_ERROR_STATE DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); // initialize pin direction

DIO_ERROR_STATE DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); // write data to dio

DIO_ERROR_STATE DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); // read data from dio

DIO_ERROR_STATE DIO_toggle(uint8_t portNumber, uint8_t pinNumber); // toggle dio value



#endif /* DIO_H_ */