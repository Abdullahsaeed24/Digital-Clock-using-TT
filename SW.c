/*
 * SW.c
 *
 * Created: 12/27/2019 3:15:18 PM
 *  Author: Abdullah saeed
 */ 


#include "SW.h"
#include "PORT.h"

static sw_periode;
#define SAMPLES_NO  (2)
#define SW_NO       (3)

#define PRESSED_VOLT  (1)
#define RELEASED_VOLT  (0)

typedef struct
			{
			 tBYTE samples[SAMPLES_NO];
			 tSW_State state ;
			
			}tSW_DATA;


static volatile tSW_DATA sw_Data[SW_NO];


void SW_init(tSW sw , tSW_State state)
{
	
	switch(sw)
	{
		case SW_PLUS:
		GPIO_InitPortPin(SW_PLUS_CONT_REG , SW_PLUS_PIN , GPIO_IN);
		break;
		
		case SW_MINUS:
		GPIO_InitPortPin(SW_MINUS_CONT_REG , SW_MINUS_PIN , GPIO_IN);
		break;
		
		
		case SW_SET:
		GPIO_InitPortPin(SW_SET_CONT_REG , SW_SET_PIN , GPIO_IN);
		break;
	
		
	}


	
	switch(state)
	{
		case SW_PRE_PRESSED:
		case SW_PRESSED:
		sw_Data[sw].samples[0] = PRESSED_VOLT;
	    sw_Data[sw].samples[1] = PRESSED_VOLT;
		break;
		
		case SW_RELEASED:
		case SW_PRE_RELEASED:
		sw_Data[sw].samples[0] = RELEASED_VOLT;
		sw_Data[sw].samples[1] = RELEASED_VOLT;
		break;
		
		default:
		/**/
		break;	
		
	}
	 	
	
}


void SW_update(void)
{
	
	 /*increment time periode*/
	 sw_periode = sw_periode + OS_PERIOD ;
	 /*check his time */
	 if (sw_periode != SW_PERIOD) {	return; }
	 
	 sw_periode = 0;
tBYTE INDEX = SW_SET ;
	
	for (INDEX = SW_SET ; INDEX <= SW_MINUS ; INDEX ++ )
	{
		
		sw_Data[INDEX].samples[0] = sw_Data[INDEX].samples[1];

		
		if (INDEX == SW_PLUS)
		{
			sw_Data[INDEX].samples[1] = GPIO_ReadPortPin(SW_PLUS_PINA_CHECK , SW_PLUS_PIN );
			
		}
		
	   
	   else if (INDEX == SW_MINUS)
		{
			sw_Data[INDEX].samples[1] = GPIO_ReadPortPin(SW_MINUS_PINA_CHECK , SW_MINUS_PIN );
			
		}


		else if (INDEX == SW_SET)
		{
			sw_Data[INDEX].samples[1] = GPIO_ReadPortPin(SW_SET_PINA_CHECK , SW_SET_PIN );
			
		}
		

		else 
		{
		/*
		
		*/
		
		}

	switch(sw_Data[INDEX].state)
	{
		case SW_RELEASED:
		if ((sw_Data[INDEX].samples[0] == PRESSED_VOLT) && 
		   (sw_Data[INDEX].samples[1] == PRESSED_VOLT))
		{
			
			sw_Data[INDEX].state = SW_PRE_PRESSED ;
		
		}
		
		break;
		
		case SW_PRE_PRESSED:
		if  (sw_Data[INDEX].samples[1] == PRESSED_VOLT)
		{
			sw_Data[INDEX].state = SW_PRESSED ;
		
		}
		
		break;	
		
		case SW_PRESSED:
		if ((sw_Data[INDEX].samples[0] == RELEASED_VOLT) &&
		   (sw_Data[INDEX].samples[1] == RELEASED_VOLT))
		{
			
			sw_Data[INDEX].state = SW_PRE_RELEASED ;
		}
		
		break;
		
		case SW_PRE_RELEASED:
		if (sw_Data[INDEX].samples[1] == RELEASED_VOLT)
		{
			
			sw_Data[INDEX].state = SW_RELEASED ;
		}
		
		break;
		
		default:
		/**/
		break;
		
	}
	




	}
	
	
	
}




tSW_State GET_SW_STATE(tSW SW)
{
	
tSW_State ret =	sw_Data[SW].state;
	return ret;
	
}


