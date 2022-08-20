/*
 * IME.h
 *
 * Created: 1/11/2020 10:21:53 AM
 *  Author: Abdullah saeed
 */ 


#ifndef IME_H_
#define IME_H_

#include "SW.h"
#include "PORT.h"

     typedef struct
    {
	   tWORD HOURES;
	   tWORD MINUTES;
	   tWORD SECONDS;
	
    }tTIME;




	typedef enum
	{
	  NORMAL_MODE,
	  ADJUST_HOURES,
	  ADJUST_MINUTES
	
	}tMODE;



void Init_TIME(tTIME *time);

void TIME_update(void);

tMODE GET_TIME_MODE(void);
void GET_TIME(tTIME *time);






#endif /* IME_H_ */