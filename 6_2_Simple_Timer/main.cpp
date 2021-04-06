#include "mbed.h"

using namespace std::chrono;

Timer t;
AnalogOut aout(PA_4);
AnalogIn ain(PC_5);

int main()
{
   t.start();
   // printf("Hello World!\n");
   // aout.write_u16(65400);
   // float i = 90 / 89.0 * 1.283;
   float v_in = ain;
   // t.elapsed_time().count();
   t.stop();
   auto s = chrono::duration_cast<chrono::seconds>(t.elapsed_time()).count();
   auto ms = chrono::duration_cast<chrono::milliseconds>(t.elapsed_time()).count();
   auto us = t.elapsed_time().count();
   printf ("Timer time: %llu s\n", s);
   printf ("Timer time: %llu ms\n", ms);
   printf ("Timer time: %llu us\n", us);
}
