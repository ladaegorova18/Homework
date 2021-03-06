#include "pch.h"
#include <iostream>
#include <vector>
#include "Queue.h"
#include <assert.h>
using namespace std;

void test()
{
	Queue* queue = makeQueue();
	enqueue(queue, "four", 4);
	enqueue(queue, "one", 1);
	enqueue(queue, "two", 2);
	enqueue(queue, "three", 3);
	enqueue(queue, "five", 5);
	enqueue(queue, "secondTwo", 2);
	std::string res[] = { "one", "two", "secondTwo", "three", "four", "five", "-1" };
	int i = 0;
	for (int i = 0; i < 7; ++i)
	{
		assert(dequeue(queue) == res[i]);
	}
	std::cout << "Test passed" << std::endl;
	deleteQueue(queue);
}

void mainText()
{
	std::cout << "Enter 1 to add element" << std::endl;
	std::cout << "Enter 2 to get value of top" << std::endl;
	std::cout << "Enter 0 to exit" << std::endl;
}

void menu(Queue *queue)
{
	char key = ' ';
	mainText();
	cin >> key;
	while (key != '0')
	{
		switch (key)
		{
		case '1':
		{
			std::cout << "Enter the value:\n";
			std::string value = "";
			std::cin >> value;
			std::cout << "Enter the priority:\n";
			int priority = 0;
			std::cin >> priority;
			enqueue(queue, value, priority);
			break;
		}
		case '2':
		{
			std::cout << dequeue(queue) << "\n";
			break;
		}
		}
		mainText();
		cin >> key;
	}
}

int main()
{
	test();
	Queue* queue = makeQueue();
	menu(queue);
	deleteQueue(queue);
	return 0;
}