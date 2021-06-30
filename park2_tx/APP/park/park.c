#include "park.h"
//tx

void park_init()
{
	sei();
	//
	TIMSK=(1<<OCIE0)|(1<<OCIE2);
   iniatUart(9600);
   ENTER_PORT_DIR&=~(1<<ENTER_PIN);
   ENTER_PORT_OUT|=(1<<ENTER_PIN);
   EXIT_PORT_DIR&=~(1<<EXIT_PIN);
   EXIT_PORT_OUT|=(1<<EXIT_PIN);


}

void park_monitor_enterAndExit()
{
	if(is_entering()==1 )
	{
		sendChar('N');
		timer0_start();

	}
	if(is_exiting()==1)
	{
		sendChar('X');
		timer2_start();

	}

}

uint8_t is_entering()
{
	static uint8_t state=0;
	uint8_t prev_state;
	prev_state=state;
	state=READING_ENTERING_GATE();
	if( (state==1) && (prev_state==0) )
	{
		_delay_ms(1);
		state=READING_ENTERING_GATE();
		if( (state==1) && (prev_state==0) )
		{
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;

}
uint8_t is_exiting()
{
	static uint8_t state=0;
	uint8_t prev_state;
	prev_state=state;
	state=READING_EXITING_GATE();
	if( (state==1) && (prev_state==0) )
	{
		_delay_ms(1);
		state=READING_EXITING_GATE();
		if( (state==1) && (prev_state==0) )
		{
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;

}
