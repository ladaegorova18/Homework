#include "pch.h"
#include <iostream>
#include <locale>
#include <cstring>
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
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Stack *myStack = new Stack();
	myStack->makeStack();
	char myString[MAX] = " ";
	cout << "Введите строку:" << endl;
	cin >> myString;
	int length = strlen(myString);
	for (int i = 0; i < length; i++)
	{
		if (isBracket(myString[i]))
		{
			myStack->push((int)myString[i]);
			if (myStack->top >= 2)
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
	if (myStack->top > 0)
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
