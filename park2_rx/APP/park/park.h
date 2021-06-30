
#ifndef _PARK_H_
#define	_PARK_H_

//rx
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include "../../MCAL/UART/uart.h"
#include "../../MCAL/timer/timer.h"
#include "../../HAL/LCD/LCD.h"
#include "../../LIB/string/STRING.h"



#define ENTER_MOTOR_CTR_PIN				5
#define ENTER_MOTOR_CTR__PORT_DIR		DDRB
#define ENTER_MOTOR_CTR_PORT_OUT		PORTB




#define EXIT_MOTOR_CTR_PIN				5
#define EXIT_MOTOR_CTR__PORT_DIR		DDRD
#define EXIT_MOTOR_CTR_PORT_OUT			PORTD








#define ENTER_MOTOR_START()				(pwm_timer0(100))
#define ENTER_MOTOR_STOP()				TCCR0=0;\
										ENTER_MOTOR_CTR_PORT_OUT&=~(1<<ENTER_MOTOR_CTR_PIN)

#define EXIT_MOTOR_START()				(pwm_timer2(100))
#define EXIT_MOTOR_STOP()				TCCR2=0;\
										EXIT_MOTOR_CTR_PORT_OUT&=~(1<<EXIT_MOTOR_CTR_PIN)

#define ENTER_GATE_OPENING()			ENTER_MOTOR_CTR_PORT_OUT|=(1<<ENTER_MOTOR_CTR_PIN);\
										ENTER_MOTOR_START()

#define ENTER_GATE_CLOSING()		 	ENTER_MOTOR_CTR_PORT_OUT&=~(1<<ENTER_MOTOR_CTR_PIN) ;\
										ENTER_MOTOR_START()


#define EXIT_GATE_OPENING()			EXIT_MOTOR_CTR_PORT_OUT|=(1<<EXIT_MOTOR_CTR_PIN);\
									EXIT_MOTOR_START()


#define EXIT_GATE_CLOSING()			EXIT_MOTOR_CTR_PORT_OUT&=~(1<<EXIT_MOTOR_CTR_PIN);\
									EXIT_MOTOR_START();

void park_init();
void park_monitor_enterAndExit();


#endif
