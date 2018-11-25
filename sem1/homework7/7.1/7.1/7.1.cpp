#include "pch.h"
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
		mySet->addingData(data);
		cout << "Значение добавлено!" << endl;
		break;
	}
	case '2':
	{
		cout << "Здесь можно удалить значение из множества. Введите значение:" << endl;
		int data = 0; 
		cin >> data;
		if (!mySet->checkData(data, mySet->root))
		{
			cout << "Элемента нет в списке:(" << endl;
			return;
		}
		mySet->deleteData(mySet->root, data);
		cout << "Значение удалено!" << endl;
		break;
	}
	case '3':
	{
		cout << "Введите значение, чтобы проверить, принадлежит ли оно множеству" << endl;
		int data = 0;
		cin >> data;
		if (mySet->checkData(data, mySet->root))
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
		if (mySet->isEmpty())
		{
			cout << "Список пуст:(" << endl;
			return;
		}
		cout << "Элементы множества в возрастающем порядке:" << endl;
		mySet->printRise(mySet->root);
		cout << endl;
		break;
	}
	case '5':
	{
		if (mySet->isEmpty())
		{
			cout << "Список пуст:(" << endl;
			return;
		}
		cout << "Элементы множества в убывающем порядке:" << endl;
		mySet->printFalling(mySet->root);
		cout << endl;
		break;
	}
	}
}

void test()
{
	Set *testSet = new Set();
	for (int j = 1; j < 5; j++)
	{
		testSet->addingData(j);
	}
	testSet->checkData(4, testSet->root);
	testSet->deleteData(testSet->root, 4);
	for (int j = 1; j < 4; j++)
	{
		testSet->deleteData(testSet->root, j);
	}

}

void menu(Set *mySet)
{
	setlocale(LC_ALL, "ru");
	test();
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
	Set *mySet = new Set();
	menu(mySet);
	delete mySet;
	return 0;
}