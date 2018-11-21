#include "pch.h"
#include <locale>
#include <iostream>
#include <cctype>
#include <assert.h>
#include "Stack1.h"
using namespace std;

bool isOperand(char symbol)
{
	return ((symbol == '/') || (symbol == '*') || (symbol == '+') || (symbol == '-'));
}

bool isBracket(char symbol)
{
	return ((symbol == '(') || (symbol == ')'));
}

bool isLeftBracket(char symbol)
{
	return (symbol == '(');
}

void makeSpace(string &postfixExpression)
{
	postfixExpression += " ";
}

void makingExpression(Stack *myStack, char symbol, string &postfixExpression, int countLeftBrackets)
{
	if (isOperand(symbol))
	{
		myStack->push(myStack, symbol);
	}
	else if (isdigit((int)symbol))
	{
		postfixExpression += symbol;
		makeSpace(postfixExpression);
	}
	else if (isBracket(symbol))
	{
		if (isLeftBracket(symbol))
		{
			countLeftBrackets += 1;
		}
		else if ((countLeftBrackets > 0) || (symbol == ')'))
		{
			postfixExpression += myStack->pop(myStack);
			makeSpace(postfixExpression);
			countLeftBrackets--;
		}
	}
}

void operandsOfExpression(string &postfixExpression, Stack *myStack)
{
	while (myStack->top != 0)
	{
		postfixExpression += myStack->pop(myStack);
		makeSpace(postfixExpression);
	}
}

void test()
{	// Тест 1
	Stack *testNineStack = new Stack();
	string testNineString = "5 + 4 Q";
	string resultExpression = "";
	int leftTestNineBrackets = 0;
	int i = 0;
	while (testNineString[i] != 'Q')
	{
		makingExpression(testNineStack, testNineString[i], resultExpression, leftTestNineBrackets);
		i++;
	}
	operandsOfExpression(resultExpression, testNineStack);
	assert (resultExpression == "5 4 + ");
	// Тест 2
	Stack *testBracketsStack = new Stack();
	string testBracketsString = "(1 + 1) * 2 Q";
	resultExpression = "";
	leftTestNineBrackets = 0;
	i = 0;
	while (testBracketsString[i] != 'Q')
	{
		makingExpression(testBracketsStack, testBracketsString[i], resultExpression, leftTestNineBrackets);
		i++;
	}
	operandsOfExpression(resultExpression, testBracketsStack);
	assert(resultExpression == "1 1 + 2 * ");
	delete[] testNineStack;
	delete[] testBracketsStack;
	cout << "Тест пройден:)" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	test();
	Stack *myStack = new Stack();
	string postfixExpression = "";
	cout << "Введите арифметическое выражение в инфиксной форме, для окончания ввода нажмите Q:" << endl;
	char symbol = ' ';
	int countLeftBrackets = 0;
	while (symbol != 'Q')
	{
		cin >> symbol;
		makingExpression(myStack, symbol, postfixExpression, countLeftBrackets);
	}
	operandsOfExpression(postfixExpression, myStack);
	cout << "Выражение в постфиксной форме:" << endl;
	cout << postfixExpression << endl;
	cout << "До свидания!" << endl;
	delete[] myStack;
	return 0;
}