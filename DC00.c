/*
 * DC_00.c
 *
 * Created: 1/11/2020 9:43:15 AM
 * Author : Abdullah saeed
 */ 
#define F_CPU (8000000ul)
#include <avr/io.h>
#include "SW.h"
#include <avr/interrupt.h>
#include "TIME.h"
#include "PORT.h"
#include "main.h"
#include "DISPLAY.h"
#include "SSD.h"

tTIME t ={1,10,0};


ISR(TIMER0_COMP_vect)
{
	
	SSD_update();
	SW_update();
	TIME_update();
	Display_update();

	
	
}

int main(void)
{
	SW_init(SW_SET  ,SW_RELEASED);
	SW_init(SW_PLUS ,SW_RELEASED);
	SW_init(SW_MINUS,SW_RELEASED);

	Init_TIME(&t);
	Display_init();

	OS_Init();
	OS_Start();


    /* Replace with your application code */
    while (1) 
    {
	
    }
}

