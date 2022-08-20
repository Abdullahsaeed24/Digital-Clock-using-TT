/*
 * TIME.c
 *
 * Created: 1/11/2020 10:21:31 AM
 *  Author: Abdullah saeed
 */ 

#include "TIME.h"


 static void normal_update(tTIME *time);
 static void adjust_houres(tTIME *time);
 static void adjust_minutes(tTIME *time);

static tTIME TIME;
static tMODE MODE = NORMAL_MODE ;
static tBYTE time_periode ;

static tWORD second_time ;



void Init_TIME(tTIME *time)
{
	TIME.HOURES  = time->HOURES ;
	TIME.MINUTES = time->MINUTES ;
	TIME.SECONDS = time->SECONDS ;

}

void TIME_update(void)
{
	
	
  /*increment time periode*/
   time_periode = time_periode + OS_PERIOD ;
   
  /*check his time */
  if (time_periode != TIME_PERIOD) {	return; }

   time_periode = 0;	
   
   second_time = second_time + TIME_PERIOD;
	
	if (second_time == SECONED_TIMES )
	{
		second_time =0;
	}
 	 /*check set switch */
	 /*if (GET_SW_STATE(SW_SET) == SW_PRE_PRESSED)
	 {
		 if(MODE == NORMAL_MODE) {MODE = ADJUST_HOURES ;}
		 
		 else if(MODE == ADJUST_HOURES) { MODE = ADJUST_MINUTES;}
		 
		 else{MODE = NORMAL_MODE;}
	}
	*/

	switch(MODE)
	{
		
		case NORMAL_MODE :
		normal_update(&TIME);
		break;
		
		case ADJUST_HOURES :
		adjust_houres(&TIME);
		break;
		
		case  ADJUST_MINUTES:
		adjust_minutes(&TIME);
		break;
		
		
		default:
		/**/
		break;
		

}
	
		}
 
 
 
 
 static void normal_update(tTIME *time)
 {
	 
 /* check second is passed or not , if not break the function */
 
 if (GET_SW_STATE(SW_SET) == SW_PRE_PRESSED)
 {   
	 MODE = ADJUST_HOURES ;
	 return;	 
 
 }
 
 
 if (second_time == 0)
 {
	time->SECONDS ++;
	if (time->SECONDS == 60 )
   {
	   
	time->SECONDS = 0 ;	
	time->MINUTES ++ ;

	if (time->MINUTES == 60)
	{
		time->MINUTES = 0;
		time->HOURES++ ;
	
		if (time->HOURES == 24)
		{
			
			time->HOURES = 0;
		}
		
   }
 }
	 

	 
  }
 
 
 
 }
 


static void adjust_houres(tTIME *time)
{
	
	if (GET_SW_STATE(SW_SET) == SW_PRE_PRESSED)
	{
	
		MODE = ADJUST_MINUTES ;
		return;
		
	}
	
	
	if (GET_SW_STATE(SW_PLUS) == SW_PRE_PRESSED)
	{
		
		time->HOURES ++;
		if (time->HOURES == 24)
		{
			
			time->HOURES= 0;
			
		}
		
	}
	
	
	
	 if (GET_SW_STATE(SW_MINUS) == SW_PRE_PRESSED)
	{

		
		time->HOURES -- ;
		if (time->HOURES == (~0))
		{
			time->HOURES= 23;
			
		}
		
	}
	
	else
	{
		/**/
	}
	
}




static void adjust_minutes(tTIME *time)
{
	
	if (GET_SW_STATE(SW_SET) == SW_PRE_PRESSED)
	{
		MODE = NORMAL_MODE ;
		return;
		
	}
	


	
	else if (GET_SW_STATE(SW_PLUS) == SW_PRE_PRESSED)
	{
		
		time->MINUTES ++ ;
		if (time->MINUTES == 60)
		{
			time->MINUTES= 0;
			
		}
		
	}
	/**/
	
	
	else if (GET_SW_STATE(SW_MINUS) == SW_PRE_PRESSED)
	{
		
		time->MINUTES -- ;
		
		if (time->MINUTES == (~0))
		{
			time->MINUTES= 59;
			
		}
		
	}
	
	else
	{
		/**/
	}
	
	
}


 tMODE GET_TIME_MODE(void)
{
	
 return MODE ;	

}

void GET_TIME(tTIME *time)
{

time->HOURES  = TIME.HOURES; 
time->MINUTES = TIME.MINUTES;
}