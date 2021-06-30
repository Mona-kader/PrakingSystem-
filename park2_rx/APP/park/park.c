#include "park.h"

//rx

void park_init()
{

  iniatUart(9600);
  LCDIntiat();
  LCDPrint("welcome in our  parking mall :)");
  _delay_ms(5000);
  LCDClearScreen();
  LCDPrint("SLOTS:150");
  LCDRowColumn(2,1);
  LCDPrint("In:0");
  LCDRowColumn(2,11);
  LCDPrint("Out:0");
 ENTER_MOTOR_CTR__PORT_DIR|=(1<<ENTER_MOTOR_CTR_PIN);
  EXIT_MOTOR_CTR__PORT_DIR|=(1<<EXIT_MOTOR_CTR_PIN);

}

void park_monitor_enterAndExit()
{
	char event;
	static uint8_t park_availble_spaces=200;
	static uint8_t park_cars=0,entered_cars=0,exited_cars=0;
	event=receiveChar();
	if(event=='N')
	{
		ENTER_GATE_OPENING();


	}
	else if(event=='X')
	{


		EXIT_GATE_OPENING();


	}
	else if(event=='R')
	{
		ENTER_GATE_CLOSING();

		LCDRowColumn(1,8);
		LCDPrint("   ");
		LCDRowColumn(1,8);
		LCDPrint( intToString(--park_availble_spaces) );

		LCDRowColumn(2,4);
		LCDPrint("   ");

		LCDRowColumn(2,4);
		LCDPrint( intToString(++entered_cars) );

		LCDRowColumn(2,15);
		LCDPrint("   ");

		LCDRowColumn(2,15);
		LCDPrint( intToString(exited_cars) );

		++park_cars;
	}
	else if(event=='T')
	{
		EXIT_GATE_CLOSING();

		LCDRowColumn(1,8);
		LCDPrint("   ");
		LCDRowColumn(1,8);
		LCDPrint( intToString(++park_availble_spaces) );

		LCDRowColumn(2,4);
		LCDPrint("   ");

		LCDRowColumn(2,4);
		LCDPrint( intToString(entered_cars) );

		LCDRowColumn(2,15);
		LCDPrint("   ");

		LCDRowColumn(2,15);
		LCDPrint( intToString(++exited_cars) );
		--park_cars;
	}
	else if(event=='n')
	{
		ENTER_MOTOR_STOP();
	}
	else
	{
		EXIT_MOTOR_STOP();
	}


}

