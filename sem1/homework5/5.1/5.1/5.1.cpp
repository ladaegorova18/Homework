#include "pch.h"
#include <clocale>
#include <iostream>
#include <cstring>
#include "assert.h"
#include "header.h"
using namespace std;

void makingList(DynList *myList)
{
	myList->head = nullptr;
}

bool isEmpty(DynList *mylist)
{
	return (mylist->head == nullptr);
}

void test()
{
	DynList* testList = new DynList;
	makingList(testList);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			insertion(testList, j);
		}
	}
	Element *current = testList->head;
	while (current)
	{
		if (current->next == nullptr)
		{
			cout << "Тест пройден" << endl;
			return;
		}
		else
		{
			assert(current->value <= current->next->value);
			current = current->next;
		}
	}
	delete[] testList;
}

void textMenu()
{
	cout << "Это главное меню для работы со списком. Нажмите:" << endl;
	cout << "1, чтобы добавить значение в список;" << endl;
	cout << "2, чтобы удалить значение из списка;" << endl;
	cout << "3, чтобы распечатать список;";
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
			cout << "Значение добавлено!" << endl;
			break;
		}
		case 2:
		{
			cout << "Здесь можно удалять определеннные значения из списка. Введите значение или нажмите Q, чтобы выйти:" << endl;
			deleteData(myList);
			cout << "Значение удалено!";
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
		textMenu();
		cin >> key;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	dynList* myList = new dynList;
	makingList(myList);
	menu(myList);
	cout << "До свидания!" << endl;
	delete[] myList;
 	return 0;
}
