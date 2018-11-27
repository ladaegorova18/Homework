#include "pch.h"
#include <clocale>
#include <iostream>
#include <cstring>
#include <assert.h>
#include "options.h"
using namespace std;

void makingList(DynList *myList)
{
	myList->head = nullptr;
}

void test()
{
	DynList* testListOneToFive = new DynList;
	makingList(testListOneToFive);
	for (int j = 1; j <= 5; j++)
	{
		insertion(testListOneToFive, j);
	}
	Element *current = testListOneToFive->head;
	while (current)
	{
		if (current->next != nullptr)
		{
			assert(current->value <= current->next->value);
			current = current->next;
		}
		else
		{
			for (int j = 5; j >= 1; j--)
			{
				deleting(testListOneToFive, j);
			}
			assert(isEmpty(testListOneToFive) == 1);
			deleteList(testListOneToFive);
			current = nullptr;
		}
	}
	DynList *testListOneElement = new DynList();
	makingList(testListOneElement);
	insertion(testListOneElement, 7);
	assert(isEmpty(testListOneElement) == 0);
	deleting(testListOneElement, 7);
	assert(isEmpty(testListOneElement) == 1);
	deleteList(testListOneElement);
	cout << "Тест пройден:)" << endl;
}

void textMenu()
{
	cout << "Это главное меню для работы со списком. Нажмите:" << endl;
	cout << "1, чтобы добавить значение в список;" << endl;
	cout << "2, чтобы удалить значение из списка;" << endl;
	cout << "3, чтобы распечатать список;" << endl;
	cout << "0, чтобы выйти." << endl;
}

void menu(DynList *myList)
{
	textMenu();
	int key = -1;
	cin >> key;
	while (key != 0)
	{

		switch (key)
		{
		case 1:
		{
			cout << "Здесь вы можете добавлять компоненты в список. Для выхода нажмите Q;\n";
			addingData(myList);
			cout << "Значения добавлены!" << endl;
			break;
		}
		case 2:
		{
			cout << "Здесь можно удалять определеннные значения из списка. Введите значение или нажмите Q, чтобы выйти:" << endl;
			deleteData(myList);
			cout << "Значение удалено!" << endl;
			break;
		}
		case 3:
		{
			if (isEmpty(myList))
			{
				cout << "Список пуст:(" << endl;
			}
			else
			{
				cout << "Сейчас список выглядит так:" << endl;
				printData(myList);
				break;
			}
			break;
		}
		}
		textMenu();
		cin >> key;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	test();
	DynList* myList = new DynList;
	makingList(myList);
	menu(myList);
	cout << "До свидания!" << endl;
	deleteList(myList);
 	return 0;
}
