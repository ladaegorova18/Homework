#ifndef HEADER_H
#define HEADER_H
#include <iostream>

struct List
{
	std::string name;
	int phoneNumber;
	List* next;
};

// ������� ������, ������� ������ �������
void makingList(List *&myList);

// ��������� �������� � ������
void addingData(List *&myList, std::string tempName, int tempPhoneNumber);

//�������� ������
void printData(List *head);

// ���������� ��������(�������� �������)
void mergeSort(List *&myList, char key);

// ������� ������
void deleteList(List *&myList);

#endif // HEADER_H
