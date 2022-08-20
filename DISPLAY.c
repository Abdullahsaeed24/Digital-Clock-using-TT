/*
 * DISPLAY.c
 *
 * Created: 1/12/2020 6:51:25 AM
 *  Author: Abdullah saeed
 */ 

#include "DISPLAY.h"
#include "SSD.h"
#include "TIME.h"

static tWORD display_periode;
 static tWORD second_Value ;

static tBYTE flag0 = 0;


static void Blink_Second (tTIME *TIme);
static void Blink_Minutes(tTIME *TIme);
static void Blink_Houres (tTIME *TIme);


 void Display_init(void)
 {
	 
	/*initiate the ssd */ 
	SSD_init(SSD_MINUTES_UNIT , SSD_OFF);
	SSD_init(SSD_MINUTES_TENS , SSD_OFF);
	SSD_init(SSD_HOURES_UNIT  , SSD_OFF);
	SSD_init(SSD_HOURES_TENS  , SSD_OFF); 
	
	/*LED CONF*/
	 GPIO_InitPortPin(SEC_LED_CR , SEC_LED_PIN , GPIO_OUT);
	 	 
	 /*DATA BUS CONFIG*/
 	 DATA_BUS_CONFIG(SSD_CONT_BUS , 0XFF);


	/*initiate the buffer*/
    SSD_SET_Symbole(SSD_MINUTES_UNIT , SSD_NULL);
    SSD_SET_Symbole(SSD_MINUTES_TENS , SSD_NULL);
    SSD_SET_Symbole(SSD_HOURES_UNIT  , SSD_NULL);
    SSD_SET_Symbole(SSD_HOURES_TENS  , SSD_NULL);
 
 
 }
 
 
 void Display_update(void)
 {
	 tTIME Time;
	 static tMODE Mode;
	 
    display_periode = display_periode + OS_PERIOD ;

    /*check display_periode time ?*/
    if (display_periode != DISP_PERIOD) {	return; }

    display_periode = 0;


	/*check second time */
	second_Value = second_Value + DISP_PERIOD ;

	if (second_Value == SECONED_TIMES) {second_Value = 0 ;}
		

	GET_TIME(&Time);
    Mode=GET_TIME_MODE();

	switch(Mode)
	{
		case NORMAL_MODE :
		Blink_Second(&Time);
		break;

		case ADJUST_HOURES :
		Blink_Houres(&Time);
		break;
	
		case ADJUST_MINUTES :
		Blink_Minutes(&Time);
		break;

		default:
		/**/
		break;
	}



}



static void Blink_Second (tTIME *TIme)
{
	/*check sec time */
	if(second_Value == 0)
	{
		
	/* write data in buffer*/
	SSD_SET_Symbole(SSD_MINUTES_UNIT , TIme->MINUTES%10);
	SSD_SET_Symbole(SSD_MINUTES_TENS , TIme->MINUTES/10);
	SSD_SET_Symbole(SSD_HOURES_UNIT  , TIme->HOURES%10);
	SSD_SET_Symbole(SSD_HOURES_TENS  , TIme->HOURES/10);
	Toggle_sec_led();
	
	}
}






static void Blink_Minutes(tTIME *TIme)
{

	
	if (second_Value == 0)
	{

	
	/*show the hours data*/
	
	/*check which data on SSD minutes*/
	/*if ((SSD_GET_Symbole(SSD_MINUTES_UNIT)||SSD_GET_Symbole(SSD_MINUTES_UNIT)) != SSD_NULL)
	{

	SSD_SET_Symbole(SSD_MINUTES_UNIT , (TIme->MINUTES)%10);
	SSD_SET_Symbole(SSD_MINUTES_TENS ,	(TIme->MINUTES)/10);
		
	}*/



		if (SSD_GET_Symbole(SSD_MINUTES_UNIT) == SSD_NULL)
		{


			SSD_SET_Symbole(SSD_MINUTES_UNIT , (TIme->MINUTES)%10);
			SSD_SET_Symbole(SSD_MINUTES_TENS , (TIme->MINUTES)/10);

			
		}
	
				
		else 

		{

		
		SSD_SET_Symbole(SSD_MINUTES_UNIT , SSD_NULL);
		SSD_SET_Symbole(SSD_MINUTES_TENS , SSD_NULL);
		
		
		}
	
		
		SSD_SET_Symbole(SSD_HOURES_UNIT  ,(TIme->HOURES)%10);
		SSD_SET_Symbole(SSD_HOURES_TENS  , (TIme->HOURES)/10);
		turn_off_sec_led();
	
	}


}




static void Blink_Houres (tTIME *TIme)
{
	if (second_Value == 0)
	{
	
	
	/*show the minutes data*/
	SSD_SET_Symbole(SSD_MINUTES_UNIT ,(TIme->MINUTES)%10);
	SSD_SET_Symbole(SSD_MINUTES_TENS ,(TIme->MINUTES)/10 );
	turn_off_sec_led();
	
	
		
		if (SSD_GET_Symbole(SSD_HOURES_UNIT) == SSD_NULL)
		{

				SSD_SET_Symbole(SSD_HOURES_UNIT  , TIme->HOURES%10);
				SSD_SET_Symbole(SSD_HOURES_TENS  , TIme->HOURES/10);

			
		}

		else
		{
			SSD_SET_Symbole(SSD_HOURES_UNIT  , SSD_NULL );
			SSD_SET_Symbole(SSD_HOURES_TENS  , SSD_NULL );

				
		}
		
	}
	
	}




	 
	 
	 
 