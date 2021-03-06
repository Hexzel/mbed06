#include "mbed.h"
using namespace std::chrono;

Timeout flipper;
DigitalOut led1(LED1);
DigitalOut led2(LED2);

volatile int lever;
void flip()
{
	lever = 0;
   led2 = !led2;
}

int main()
{
   led2 = 1;
   for (int i = 0; i < 10; i++) {
   		lever = 1;
   		flipper.attach(&flip, 2s); // setup flipper to call flip after 2 seconds
		while (lever) ;
	}
   // spin in a main loop. flipper will interrupt it to call flip
   while (1)
   {
      led1 = !led1;
      ThisThread::sleep_for(200ms);
   }
}
