#include "mbed.h"
using namespace std::chrono;

void simpleFunction(int a, int b)
{
	printf("%d\n", a * b);
}

int main()
{
	EventQueue queue;

	queue.call(printf, "called %d immediately\r\n", 2);
	queue.call_in(2s, simpleFunction, 3, 4);
	queue.call_every(1s, printf, "called every 1 seconds\r\n");
	queue.dispatch();
}
