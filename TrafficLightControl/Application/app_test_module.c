/*
 * app_test_module.c
 *
 * Created: 9/15/2022 7:44:34 PM
 *  Author: hp
 */ 

#if 0
#include "app.h"
int main() {
	int appInitError = APP_init();
	if (appInitError == APP_ERROR) {
		while (1)
		{
			LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
			LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
		}
	}
	int appStartError = APP_start();
	if (appStartError == APP_ERROR) {
		while (1)
		{
			LED_on(CAR_RED_LED_PORT, CAR_RED_LED_PIN);
			LED_on(PED_RED_LED_PORT, PED_RED_LED_PIN);
		}
	}
	return 0;
}

#endif