#include "pch.h"
#include <iostream>
#include <string>
#include "List.h"

struct List
{
	std::string name;
	int phoneNumber;
	List* next;
};

List* makingList()
{
	List* head = nullptr;
	return head;
}

std::string getName(List *list)
{
	return list->name;
}

int getNumber(List* list)
{
	return list->phoneNumber;
}

List* nextNode(List *list)
{
	return list->next;
}

bool isEmpty(List *head)
{
	return (head == nullptr);
}

void addInTail(List *&head, List*& data)
{
	List* current = head;
	while (current)
	{
		if (current->next == nullptr)
		{
			current->next = data;
			return;
		}
		current = current->next;
	}
}

void addingData(List *&head, std::string newName, int newPhoneNumber)
{
	List* data = new List();
	data->name = newName;
	data->phoneNumber = newPhoneNumber;
	data->next = nullptr;
	if (isEmpty(head))
	{
		head = data;
	}
	else
	{
		addInTail(head, data);
	}
}

void printData(List *head)
{
	List *current = head;
	while (current)
	{
		std::cout << current->name << " " << current->phoneNumber << std::endl;
		current = current->next;
	}
}

int getSize(List *&head)
{
	List* current = head;
	int size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return size;
}

List* merge(List *&firstList, List *&secondList, char key);

List* mergeName(List *&firstList, List *&secondList, char key)
{
	List* newHead = nullptr;
	if (firstList->name < secondList->name)
	{
		newHead = firstList;
		newHead->next = merge(firstList->next, secondList, key);
	}
	else
	{
		newHead = secondList;
		newHead->next = merge(firstList, secondList->next, key);
	}
	return newHead;
}

List* mergeNumber(List *&firstList, List *&secondList, char key)
{
	List* newHead = nullptr;
	if (firstList->phoneNumber < secondList->phoneNumber)
	{
		newHead = firstList;
		newHead->next = merge(firstList->next, secondList, key);
	}
	else
	{
		newHead = secondList;
		newHead->next = merge(firstList, secondList->next, key);
	}
	return newHead;
}

List* merge(List *&firstList, List *&secondList, char key)
{
	List* newHead = nullptr;
	if (firstList == nullptr)
	{
		return secondList;
	}
	if (secondList == nullptr)
	{
		return firstList;
	}
	if (key == '1')
	{
		newHead = mergeName(firstList, secondList, key);
	}
	else
	{
		newHead = newHead = mergeNumber(firstList, secondList, key);
	}
	return newHead;
}

void mergeSort(List *&head, char key)
{
	if (head->next != nullptr)
	{
		List* firstList = nullptr;
		List* secondList = head;
		int len = getSize(head);
		for (int i = 0; i < len / 2; i++)
		{
			firstList = secondList;
			secondList = secondList->next;
		}
		firstList->next = nullptr;
		firstList = head;
		mergeSort(firstList, key);
		mergeSort(secondList, key);
		head = merge(firstList, secondList, key);
	}
}

void deleteList(List *&head)
{
	List* current = head;
	List* prev = nullptr;
	while (current)
	{
		prev = current;
		current = current->next;
		delete prev;
	}
	delete current;
}