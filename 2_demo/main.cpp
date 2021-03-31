#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led3(LED3);
InterruptIn button(USER_BUTTON);

EventQueue printQueue;
Thread lowThread(osPriorityLow);
Thread norThread(osPriorityNormal);


void flip_led1()
{
	led1 = !led1;
	printQueue.call(printf, "printQueue is Working\r\n");
	printQueue.call(printf, "LED is %d\r\n", (int)led1);
}

void normal_thread()
{
	while(1) {
		led3 = !led3;
		ThisThread::sleep_for(1s);
	}
}

int main()
{
	lowThread.start(callback(&printQueue, &EventQueue::dispatch_forever));
	norThread.start(normal_thread);
	button.rise(&flip_led1);
	while (1) ThisThread::sleep_for(500ms);
}
