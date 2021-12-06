#include <iostream>
#include "queue.h"

using namespace std;


int main()
{
	cout << "Priority queue data structure example!" << endl << endl;

	const int SIZE = 5;
	PriorityQueue<int> intQueue(SIZE);

	intQueue.push(125, 1);
	intQueue.push(420, 3);
	intQueue.push(360, 2);
	intQueue.push(450, 4);
	intQueue.push(500, 5);

	

	cout << "Priority queue content (Size - " << intQueue.GetSize() << ") : " << endl;

	while (intQueue.isEmpty() == false)
	{
		cout << "value: " << intQueue.front() << endl;
		intQueue.pop();
	}

	cout << endl << endl;

	if (intQueue.isEmpty() == true)
	{
		cout << "The int queue is empty." << endl << endl;
	}
	else
	{
		cout << "The int queue is NOT empty." << endl << endl;
	}
}