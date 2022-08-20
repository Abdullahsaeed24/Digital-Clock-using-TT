/*
 * OS.c
 *
 * Created: 1/7/2020 3:55:07 AM
 *  Author: Abdullah saeed
 */ 

#include "OS.h"
#include <avr/interrupt.h>

void OS_Init(void)
{

/**/	
TCCR0 = 0x0C ;
OCR0 = 255;
TIMSK =0x02 ;

}



void OS_Start(void)
{
	/**/
	sei();
}