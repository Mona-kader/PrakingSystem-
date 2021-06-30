
//tx
#include "timer.h"
void timer0_start()
{
 TCNT0=0;
 OCR0=0xFF;
 TCCR0=(1<<CS00)|(1<<CS02)|(1<<WGM01);

}


void timer2_start()
{
 TCNT2=0;
 OCR2=0xFF;
 TCCR2=(1<<CS20)|(1<<CS21)|(1<<CS22)|(1<<WGM21);

}
