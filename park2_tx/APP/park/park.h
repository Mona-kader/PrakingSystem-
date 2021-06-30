
//tx
#ifndef _PARK_H_
#define	_PARK_H_

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include "../../MCAL/UART/uart.h"
#include "../../MCAL/timer/timer.h"


#define ENTER_PIN						4
#define ENTER_PORT_DIR					DDRB
#define ENTER_PORT_OUT					PORTB
#define ENTER_PORT_IN					PINB




#define EXIT_PIN						4
#define EXIT_PORT_DIR					DDRD
#define EXIT_PORT_OUT					PORTD
#define EXIT_PORT_IN					PIND







#define READING_ENTERING_GATE() 					( !( (ENTER_PORT_IN)  & (1<<ENTER_PIN) ) )
#define READING_EXITING_GATE()						( !( (EXIT_PORT_IN)   & (1<<EXIT_PIN) ) )







void park_init();
void park_monitor_enterAndExit();
uint8_t is_entering();
uint8_t is_exiting();


#endif
