/*
 * dio_test_module.c
 *
 * Created: 9/15/2022 4:57:31 AM
 *  Author: hp
 */ 
#if 0
#include "dio.h"
#include "../Timer Driver/timer.h"

int main() {
	int dioError1 = DIO_init(PORT_A, PIN0, OUT);
	int dioError2 = DIO_init(PORT_A, PIN1, 2);
	//int dioError2 = DIO_init(PORT_A, PIN1, OUT);
	DIO_init(PORT_A, PIN2, OUT);
	DIO_init(PORT_B, PIN0, OUT);
	DIO_init(PORT_B, PIN1, OUT);
	uint8_t* value;
	
	while (1) {
		if (dioError2 == DIO_ERROR || dioError1 == DIO_ERROR)
		DIO_write(PORT_A, PIN2, HIGH);
		else {
			DIO_write(PORT_A, PIN2, LOW);
			DIO_write(PORT_A, PIN1, HIGH);
		}
		DIO_read(PORT_A, PIN2, value);
		DIO_write(PORT_B, PIN0, *value);
		DIO_toggle(PORT_B, PIN1);
		_delay_ms(2000);
	}
	
	
	return 0;
}

#endif