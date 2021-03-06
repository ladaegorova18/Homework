﻿#include "pch.h"
#include <iostream>
#include <locale>
#include <cstring>
#include <assert.h>
#include "Stack1.h"
using namespace std;

bool isBracket(char symbol)
{
	return ((symbol == '[') || (symbol == '(') || (symbol == '{') || (symbol == ']') || (symbol == ')') || (symbol == '}'));
}

bool equasion(char leftBracket, char rightBracket)
{
	switch (leftBracket)
	{
	case '[':
	{
		return (rightBracket == ']');
	}
	case '{':
	{
		return (rightBracket == '}');
	}
	case '(':
	{
		return (rightBracket == ')');
	}
	default:
	{
		return false;
	}
	}
}

void bracketPushing(Stack *myStack, char symbol)
{
	if (isBracket(symbol))
	{
		myStack->push((int)symbol);
		if (myStack->sizeOfStack() >= 2)
		{
			char rightBracket = myStack->pop();
			char leftBracket = myStack->pop();
			if (!equasion(leftBracket, rightBracket))
			{
				myStack->push(leftBracket);
				myStack->push(rightBracket);
			}
		}
	}
}

void test()
{
	Stack *testRightStack = new Stack();
	testRightStack->makeStack();
	bracketPushing(testRightStack, '(');
	bracketPushing(testRightStack, '[');
	bracketPushing(testRightStack, '{');
	bracketPushing(testRightStack, '}');
	bracketPushing(testRightStack, ']');
	bracketPushing(testRightStack, ')');
	assert(testRightStack->sizeOfStack() == 0);
	Stack *testWrongStack = new Stack();
	testWrongStack->makeStack();
	bracketPushing(testWrongStack, '(');
	bracketPushing(testWrongStack, '[');
	bracketPushing(testWrongStack, '[');
	bracketPushing(testWrongStack, ']');
	bracketPushing(testWrongStack, ')');
	assert(testWrongStack->sizeOfStack() != 0);
	delete testRightStack;
	delete testWrongStack;
	cout << "Тест пройден!" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	test();
	Stack *myStack = new Stack();
	myStack->makeStack();
	string myString = " ";
	cout << "Введите строку:" << endl;
	cin >> myString;
	size_t length = myString.length();
	for (size_t i = 0; i < length; i++)
	{
		bracketPushing(myStack, myString[i]);
	}
	if (myStack->sizeOfStack() > 0)
	{
		cout << "Скобки в строке расставлены неправильно:(" << endl;
	}
	else
	{
		cout << "Скобки в строке стоят правильно:)" << endl;
	}
	delete myStack;
	return 0;
}