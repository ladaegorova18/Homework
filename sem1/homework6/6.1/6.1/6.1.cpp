#include "pch.h"
#include <assert.h>
#include <iostream>
#include <locale>
#include "Stack1.h"
using namespace std;

bool isOper(char symbol)
{
	return ((symbol == '/') || (symbol == '*') || (symbol == '-') || (symbol == '+'));
}

int operation(int a, int b, char symbol)
{
	int tempResult = 0;
	switch (symbol)
	{
		case '+':
		{
			tempResult = a + b;
			break;
		}
		case '-':
		{
			tempResult = a - b;
			break;
		}
		case '/':
		{
			tempResult = a / b;
			break;
		}
		case '*':
		{
			tempResult = a * b;
			break;
		}
	}
	return tempResult;
}

void reading(Stack *myStack)
{
	cout << "Введите последовательность цифр и арифметических операций, для окончания ввода введите Q:" << endl;
	char symbol = ' ';
	while (symbol != 'Q')
	{
		cin >> symbol;
		myStack->push(myStack, symbol);
		if ((myStack->top > 2) && (isOper(symbol)))
		{
			myStack->pop(myStack);
			int last = (int)myStack->pop(myStack) - 48;
			int first = (int)myStack->pop(myStack) - 48;
			myStack->push(myStack, (char)(operation(first, last, symbol) + 48));
		}
	}
}

void test()
{	//first test
	Stack *testNineStack = new Stack();
	testNineStack->push(testNineStack, '4');
	testNineStack->push(testNineStack, '5');
	testNineStack->push(testNineStack, '+');
	char symbol = testNineStack->pop(testNineStack);
	int last = (int)testNineStack->pop(testNineStack) - 48;
	int first = (int)testNineStack->pop(testNineStack) - 48;
	assert(operation(first, last, symbol) == 9);
	//second test

	cout << "Тест пройден" << endl;
	Stack *testOneStack = new Stack();
	testOneStack->push(testOneStack, '9');
	testOneStack->push(testOneStack, '8');
	testOneStack->push(testOneStack, '-');
	symbol = testOneStack->pop(testOneStack);
	last = (int)testOneStack->pop(testOneStack) - 48;
	first = (int)testOneStack->pop(testOneStack) - 48;
	assert(operation(first, last, symbol) == 1);

	delete[] testNineStack;
	delete[] testOneStack;
}

int main()
{
	setlocale(LC_ALL, "ru");
	test();
	Stack *myStack = new Stack;
	myStack->makeStack(myStack);
	reading(myStack);
	myStack->pop(myStack);
	int result = (int)myStack->pop(myStack) - 48;
	cout << "Результат равен: " << result << endl;
	delete[] myStack;
	return 0;
}
