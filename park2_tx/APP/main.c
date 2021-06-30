

#ifndef F_CPU
# define F_CPU 8000000UL
#endif

//include park file which have function we use here
#include "park/park.h"


//main of tx
int main()
{
/*
initialization function
to initiate the UART PROTOCAL
to put the switch direction (input)&& make pull up to
avoid the floating value because by using pull up we always read
high on the button but if user push the button the value will be
zero
we also enable  global interrupt to high using sei() function
we also enable the peripheral interrupt OCEI for timer0 & timer 1
*/
park_init();



while(1)
{
//monitor if car enter or exit
park_monitor_enterAndExit();

}
return 0;
}

//if compare match is happen we go to isr
ISR(TIMER0_COMP_vect)
{
	//create variables help us to do our operation and define it as static
	//to keep its value all life time of the program
	static uint8_t counter0=0;
	static uint8_t dir0=0;
	if(counter0 < 	50)
	{
		//if the counter0 less than 50 counter0 increases
		counter0++;
	}
	else
	{
		//if the counter0 is greater than 50 then
		//if dir0 equal to 0
		if(dir0==0)
		{
			//send char n to the rx using UART PROTOCAL IF RX DETECT THIS char
			//is stop the entering motor
			sendChar('n');
			//THEN TIMER0 START AGAIN
			timer0_start();
			//CHANGE THE dir0 containing to be one to execute another performance
			dir0=1;
			//initiate the counter0 to start again from 0
			counter0=0;
		}
		else if(dir0==1)
		{
			//if dir0 equal to 1 its indicate that the motor stopped after is
			//moving in forward direction so we here will swap the direction
			//to look as closing the gate of entering
			sendChar('R');
			//start the timer again
			timer0_start();
			//CHANGE THE dir0 containing to be two to execute another performance
			dir0=2;
			//initiate the counter0 to start again from 0
			counter0=0;
		}
		else
		{
			//if the dir0 not equal to one or zero
			//we will send this char to stop the motor
		sendChar('n');
		//initialize the timer register
		TCNT0=0;
		//stop the  timer by put the prescaller to be zero
		TCCR0=0;
		//put zero in dir0 to be ready again
		dir0=0;
		//initiate the counter0 to start again from 0
		counter0=0;
		}

	}
}

ISR(TIMER2_COMP_vect)
{
	//create variables help us to do our operation and define it as static
    //to keep its value all life time of the program
	static uint8_t counter2=0,dir2=0;
	if(counter2 < 50)
	{
		counter2++;
	}
	else
	{
		if(dir2==0)
		{
			sendChar('x');    //to stop exiting motor;
			timer2_start();
			dir2=1;
			counter2=0;
		}
		else if(dir2==1)
		{
			sendChar('T'); 	//rev direction of exiting motor
			timer2_start();
			dir2=2;
			counter2=0;
		}
		else
		{
		sendChar('x');    //to stop exiting motor;
		TCNT2=0;
		TCCR2=0; //stop timer
		dir2=0;
		counter2=0;
		}

	}
}

