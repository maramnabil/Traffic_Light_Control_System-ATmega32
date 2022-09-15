/*
 * main.c
 *
 * Created: 9/11/2022 3:37:30 AM
 *  Author: hp
 */ 
#include "Application/app.h"
#if 1
int main() {
	int appInitError = APP_init();
	if (appInitError == APP_ERROR)
		return 1;  // Any suitable error handling procedure
	int appStartError = APP_start();
	if (appStartError == APP_ERROR)
		return 1;  // Any suitable error handling procedure
	return 0;
}

#endif