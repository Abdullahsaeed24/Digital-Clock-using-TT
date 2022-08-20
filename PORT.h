/*
 * PORT.h
 *
 * Created: 12/26/2019 2:02:58 AM
 *  Author: Abdullah saeed
 */ 


 #ifndef PORT_H_
 #define PORT_H_
 
 #include "main.h"
 
 #define SW_PLUS_DATA_REG   (GPIO_PORTA_DATA)
 #define SW_PLUS_CONT_REG   (GPIO_PORTA_CONTROL)
 #define SW_PLUS_PINA_CHECK (GPIO_PINA_CHECK)
 #define SW_PLUS_PIN        (GPIO_PIN_0)
 
 #define SW_MINUS_DATA_REG   (GPIO_PORTA_DATA)
 #define SW_MINUS_CONT_REG   (GPIO_PORTA_CONTROL)
 #define SW_MINUS_PINA_CHECK (GPIO_PINA_CHECK)
 #define SW_MINUS_PIN        (GPIO_PIN_1)
 
 #define SW_SET_DATA_REG   (GPIO_PORTA_DATA)
 #define SW_SET_CONT_REG   (GPIO_PORTA_CONTROL)
 #define SW_SET_PINA_CHECK (GPIO_PINA_CHECK)
 #define SW_SET_PIN        (GPIO_PIN_2) 
 


 
 
 
 #define SSD_DATA_BUS		(GPIO_PORTC_DATA)
 #define SSD_CONT_BUS       (GPIO_PORTC_CONTROL)



							
							/*SSD CONTRIL PINS */
							 
 #define SSD_MINUTES_UNITS_DR		(GPIO_PORTD_DATA)
 #define SSD_MINUTES_UNITS_CR		(GPIO_PORTD_CONTROL)
 #define SSD_MINUTES_UNITS_CHECK    (GPIO_PIND_CHECK)
 #define SSD_MINUTES_UNITS_PIN		(GPIO_PIN_0) 

  
 #define SSD_MINUTES_TENS_DR		(GPIO_PORTD_DATA)
 #define SSD_MINUTES_TENS_CR		(GPIO_PORTD_CONTROL)
 #define SSD_MINUTES_TENS_CHECK     (GPIO_PIND_CHECK)
 #define SSD_MINUTES_TENS_PIN		(GPIO_PIN_1)


 #define SSD_HOURES_UNITS_DR		(GPIO_PORTD_DATA)
 #define SSD_HOURES_UNITS_CR		(GPIO_PORTD_CONTROL)
 #define SSD_HOURES_UNITS_CHECK     (GPIO_PIND_CHECK) 
 #define SSD_HOURES_UNITS_PIN		(GPIO_PIN_2)
  
  
  
 #define SSD_HOURES_TENS_DR			(GPIO_PORTD_DATA)	
 #define SSD_HOURES_TENS_CR			(GPIO_PORTD_CONTROL)
 #define SSD_HOURES_TENS_CHECK      (GPIO_PIND_CHECK)	
 #define SSD_HOURES_TENS_PIN		(GPIO_PIN_3)
  
  
 #define SEC_LED_DR			(GPIO_PORTD_DATA)
 #define SEC_LED_CR			(GPIO_PORTD_CONTROL)
 #define SEC_LED_PIN		(GPIO_PIN_4)
 

 #define DATA_BUS_OUT(REG)  (REG = 0xff)
 #define DATA_BUS_IN(REG)   (REG = 0x00)
  
 #define DATA_BUS_CONFIG(REG , DATA)  (REG = DATA)


 #endif /* PORT_H_ */