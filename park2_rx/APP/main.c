

#ifndef F_CPU
# define F_CPU 8000000UL
#endif

#include "park/park.h"

//rx
int main()
{
park_init();
while(1)
{
	park_monitor_enterAndExit();
}
return 0;
}
