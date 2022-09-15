/*
 * timer_test_module.c
 *
 * Created: 9/15/2022 3:22:08 AM
 *  Author: hp
 */ 
#if 0
#include "../DIO Driver/dio.h"
#include "timer.h"

int main() {
	DIO_init(PORT_A, PIN0, OUT);
	while (1) {
		DIO_write(PORT_A, PIN0, HIGH);
		_delay_ms(1000);
		DIO_write(PORT_A, PIN0, LOW);
		_delay_ms(1000);
	}	
	return 0;
}

#endif