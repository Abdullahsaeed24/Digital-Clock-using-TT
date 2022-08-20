/*
 * SSD.c
 *
 * Created: 1/12/2020 6:51:41 AM
 *  Author: Abdullah saeed
 */ 

#include "SSD.h"
#include "main.h"
#include "PORT.h"
#include "TIME.h"


#define SSD_NO  (4)
#define N_SSD_SYMBOLS (11)


static tWORD SSD_values[SSD_NO] = {SSD_NULL};
/*
 tBYTE SSD_Data[N_SSD_SYMBOLS] =
 {
	 0b00000000,
	 0b00000001,
	 0b00000010,
	 0b00000011,
	 0b00000100,
	 0b00000101,
	 0b00000110,
	 0b00000111,
	 0b00001000,
	 0b00001001,
	 0b00001010,
 };
*/
  tBYTE SSD_Data[N_SSD_SYMBOLS] =
 {
	 0b01000000,//0
	 0b11111001,//1
	 0b00100100,//2
	 0b00110000,//3
	 0b00011001,//4
	 0b00010010,//5
	 0b00000010,//6
	 0b01111000,//7
	 0b00000000,//8
	 0b00010000,//9
	 0b01111111,//10
 };


static void SSD_OUT(tSSD ssd ,tSSD_SYMBOLE symbole);

static tSSD current_ssd = SSD_MINUTES_UNIT;

void SSD_init(tSSD ssd , tSSD_STATE ssd_state)
{
	
	
	
	switch(ssd)
	{
		case SSD_MINUTES_UNIT:
		GPIO_InitPortPin(SSD_MINUTES_UNITS_CR , SSD_MINUTES_UNITS_PIN , GPIO_OUT);
		break;
		
		case SSD_MINUTES_TENS:
		GPIO_InitPortPin(SSD_MINUTES_TENS_CR , SSD_MINUTES_TENS_PIN , GPIO_OUT);
		break;
		
		
		case SSD_HOURES_UNIT:
		GPIO_InitPortPin(SSD_HOURES_UNITS_CR , SSD_HOURES_UNITS_PIN , GPIO_OUT);
		break;
		
		
		case SSD_HOURES_TENS:
		GPIO_InitPortPin(SSD_HOURES_TENS_CR , SSD_HOURES_TENS_PIN , GPIO_OUT);
		break;
		
		
		default:
		/* */
		break;
		
	}
	
	SSD_SET_STATE(ssd ,ssd_state);
	
}



void SSD_update(void)
{

	SSD_OUT(current_ssd , SSD_values[current_ssd]);
	
	if (current_ssd == SSD_HOURES_TENS)
	{
		current_ssd = SSD_MINUTES_UNIT ;
	}
	
	else
	{
		current_ssd ++;

	}		
	
	
	}
	
void SSD_SET_STATE(tSSD ssd , tSSD_STATE ssd_state)
{
	
	
		switch(ssd)
		{
			case SSD_MINUTES_UNIT:
			GPIO_WritePortPin(SSD_MINUTES_UNITS_DR , SSD_MINUTES_UNITS_PIN ,ssd_state );
			break;
			
			case SSD_MINUTES_TENS:
			GPIO_WritePortPin(SSD_MINUTES_TENS_DR , SSD_MINUTES_TENS_PIN , ssd_state);
			break;
			
			
			case SSD_HOURES_UNIT:
			GPIO_WritePortPin(SSD_HOURES_UNITS_DR ,SSD_HOURES_UNITS_PIN ,ssd_state);
			break;
			
			
			case SSD_HOURES_TENS:
			GPIO_WritePortPin(SSD_HOURES_TENS_DR, SSD_HOURES_TENS_PIN , ssd_state );
			break;
			
			
			default:
			/* */
			break;
			
		}
	
}



void SSD_SET_Symbole(tSSD ssd ,tSSD_SYMBOLE symbole)
{
	
	SSD_values[ssd] = symbole ;
}



tSSD_SYMBOLE SSD_GET_Symbole(tSSD ssd)
{
	
	return SSD_values[ssd];
	
}

tSSD_STATE SSD_GET_STATE(tSSD ssd)
{
	tSSD_STATE ret ;
		switch(ssd)
		{
			case SSD_MINUTES_UNIT:
			ret = GPIO_ReadPortPin(SSD_MINUTES_UNITS_CHECK , SSD_MINUTES_UNITS_PIN);
			break;
			
			case SSD_MINUTES_TENS:
			ret = GPIO_ReadPortPin(SSD_MINUTES_TENS_CHECK , SSD_MINUTES_TENS_PIN);
			break;
			
			
			case SSD_HOURES_UNIT:
			ret = GPIO_ReadPortPin(SSD_HOURES_UNITS_CHECK ,SSD_HOURES_UNITS_PIN);
			break;
			
			
			case SSD_HOURES_TENS:
			ret = GPIO_ReadPortPin(SSD_HOURES_TENS_CHECK, SSD_HOURES_TENS_PIN);
			break;
			
			
			default:
			/* */
			break;
			
		}

return ret ;
}


static void SSD_OUT(tSSD ssd ,tSSD_SYMBOLE symbole)
{
	
	SSD_SET_STATE(SSD_MINUTES_UNIT , SSD_OFF);
	SSD_SET_STATE(SSD_MINUTES_TENS , SSD_OFF);
	SSD_SET_STATE(SSD_HOURES_UNIT  , SSD_OFF);
	SSD_SET_STATE(SSD_HOURES_TENS  , SSD_OFF);
	
	GPIO_WritePort(SSD_DATA_BUS , SSD_Data[symbole]);
	SSD_SET_STATE(ssd , SSD_ON);
}


 void Toggle_sec_led(void)
 {
	 SEC_LED_DR^=(1<<SEC_LED_PIN);
	 
 }
 
 void turn_off_sec_led(void)
 {
	 
	 GPIO_WritePortPin(SEC_LED_DR , SEC_LED_PIN , 1);
 }