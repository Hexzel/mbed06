#include "mbed.h"
using namespace std::chrono;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
Thread thr;

void led2_thread()
{
   while (true)
   {
      led2 = !led2;
      ThisThread::sleep_for(1s);
   }
}

int main()
{
   thr.start(led2_thread);

   while (true)
   {
      led1 = !led1;
      ThisThread::sleep_for(500ms);
   }
}
