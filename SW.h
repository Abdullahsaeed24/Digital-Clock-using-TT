/*
 * SW.h
 *
 * Created: 12/26/2019 2:00:17 AM
 *  Author: Abdullah saeed
 */ 


#ifndef SW_H_
#define SW_H_
typedef enum
			{
			SW_SET ,	
			SW_PLUS,
			SW_MINUS
			}tSW;

typedef enum
{
	SW_RELEASED    ,
	SW_PRE_PRESSED ,
	SW_PRESSED     ,
	SW_PRE_RELEASED
	
}tSW_State;


void SW_init(tSW sw , tSW_State state);
void SW_update(void);

tSW_State GET_SW_STATE(tSW SW);

#endif /* SW_H_ */