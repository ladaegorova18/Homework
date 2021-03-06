﻿#include "pch.h"
#include "Set.h"
#include <locale>
#include <assert.h>
#include <iostream>
using namespace std;

void printMenu()
{
	cout << "Это структура 'множество'. Нажмите:" << endl;
	cout << "1, чтобы добавить значение в множество;" << endl;
	cout << "2, чтобы удалить значение из множества;" << endl;
	cout << "3, проверить, принадлежит ли значение множеству;" << endl;
	cout << "4, напечатать элементы множества в возрастающем порядке;" << endl;
	cout << "5, напечатать элементы множества в убывающем порядке;" << endl;
	cout << "0, чтобы выйти." << endl;
}

void options(char key, Set *mySet)
{
	switch (key)
	{
	case '1':
	{
		cout << "Здесь можно добавить значение в множество. Введите значение:" << endl;
		int data = 0;
		cin >> data;
		add(mySet, data);
		cout << "Значение добавлено!" << endl;
		break;
	}
	case '2':
	{
		cout << "Здесь можно удалить значение из множества. Введите значение:" << endl;
		int data = 0;
		cin >> data;
		if (!exists(mySet, data))
		{
			cout << "Элемента нет в списке:(" << endl;
			return;
		}
		remove(mySet, data);
		cout << "Значение удалено!" << endl;
		break;
	}
	case '3':
	{
		cout << "Введите значение, чтобы проверить, принадлежит ли оно множеству" << endl;
		int data = 0;
		cin >> data;
		if (exists(mySet, data))
		{
			cout << "Элемент есть в списке:)" << endl;
		}
		else
		{
			cout << "Элемента нет в списке:(" << endl;
		}
		break;
	}
	case '4':
	{
		if (isEmpty(mySet))
		{
			cout << "Список пуст:(" << endl;
			return;
		}
		cout << "Элементы множества в возрастающем порядке:" << endl;
		printIncrease(mySet);
		cout << endl;
		break;
	}
	case '5':
	{
		if (isEmpty(mySet))
		{
			cout << "Список пуст:(" << endl;
			return;
		}
		cout << "Элементы множества в убывающем порядке:" << endl;
		printDecrease(mySet);
		cout << endl;
		break;
	}
	}
}

void test()
{
	Set *testSetOneToFive = createSet();
	for (int j = 1; j < 6; j++)
	{
		add(testSetOneToFive, j);
	}
	for (int j = 1; j < 6; j++)
	{
		assert(exists(testSetOneToFive, j) == 1);
	}
	for (int j = 1; j < 6; j++)
	{
		remove(testSetOneToFive, j);
	}
	assert(isEmpty(testSetOneToFive) == 1);
	deleteSet(testSetOneToFive);
	cout << "Тест пройден!" << endl;
}

void menu(Set *mySet)
{
	printMenu();
	char key = ' ';
	cin >> key;
	while (key != '0')
	{
		options(key, mySet);
		printMenu();
		cin >> key;
	}
	cout << "До свидания!" << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	test();
	Set *mySet = createSet();
	menu(mySet);
	deleteSet(mySet);
	return 0;
}