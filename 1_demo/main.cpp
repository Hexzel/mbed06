#include "mbed.h"
using namespace std::chrono;

Ticker blink;
DigitalOut led_blue(LED3);

void flip()
{
	led_blue = !led_blue;
}

int main()
{
	led_blue = 1;
	blink.attach(&flip, 500ms);
	while(1);
}
