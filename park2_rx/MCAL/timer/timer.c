
#include "timer.h"

void pwm_timer0(uint8_t duty_cycle)
{
	DDRB|=1<<3;
	OCR0=(256*duty_cycle/100)-1;
	TCCR0=0x64;

}


void pwm_timer2(uint8_t duty_cycle)
{
	DDRD|=1<<7;
	OCR2=(256*duty_cycle/100)-1;
	TCCR2=0x64;

}
