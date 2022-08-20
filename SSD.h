/*
 * SSD.h
 *
 * Created: 1/12/2020 6:49:28 AM
 *  Author: Abdullah saeed
 */ 


#ifndef SSD_H_
#define SSD_H_

 typedef enum
 {
	 SSD_MINUTES_UNIT,
	 SSD_MINUTES_TENS,
	 SSD_HOURES_UNIT ,
	 SSD_HOURES_TENS
	 
 }tSSD;
 
 
 typedef enum
 {

	 SSD_OFF ,
	 SSD_ON
 }tSSD_STATE;
 
 
 typedef enum
 {
	 
	 SSD_0,
	 SSD_1,
	 SSD_2,
	 SSD_3,
	 SSD_4,
	 SSD_5,
	 SSD_6,
	 SSD_7,
	 SSD_8,
	 SSD_9,
	 SSD_NULL
	 
 }tSSD_SYMBOLE;
 

void SSD_init(tSSD ssd , tSSD_STATE ssd_state);
void SSD_update(void);

void SSD_SET_STATE(tSSD ssd , tSSD_STATE ssd_state);
void SSD_SET_Symbole(tSSD ssd ,tSSD_SYMBOLE symbole);


tSSD_SYMBOLE SSD_GET_Symbole(tSSD ssd);
tSSD_STATE SSD_GET_STATE(tSSD ssd);

void Toggle_sec_led(void);
void turn_off_sec_led(void);
 
#endif /* SSD_H_ */