#pragma once
#include <iostream>
#include <string>

struct Node
{
	int value;
	Node* next;
	Node(int newValue)
	{
		value = newValue;
		next = nullptr;
	}
};

Node* increaseList(Node* list);

// ������� ������
void makeList(Node*& head);

// ��������� ������� � ������
void adding(Node*& head, int value);

// ��������� ������ �� �������
bool isEmpty(Node* head);

// �������� ������
void printing(Node* head);

// ������� ������
void deleteList(Node*& head);