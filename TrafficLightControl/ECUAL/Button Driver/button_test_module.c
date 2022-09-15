/*
 * button_test_module.c
 *
 * Created: 9/15/2022 5:26:29 AM
 *  Author: hp
 */ 
#if 0
#include "button.h"
#include "../LED Driver/led.h"
int main() {
	LED_init(PORT_A, PIN2);
	
	int buttonError1 = Button_init(PORT_D, PIN2);
	//int buttonError2 = Button_init('C', PIN1);
	int buttonError2 = Button_init(PORT_B, PIN1);
	
	
	if (buttonError1 == BUTTON_ERROR || buttonError2 == BUTTON_ERROR) {
		LED_on(PORT_A, PIN2);
	} else {
		LED_off(PORT_A, PIN2);
	}
	return 0;
}

#endif