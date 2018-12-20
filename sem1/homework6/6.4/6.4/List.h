#ifndef HEADER_H
#define HEADER_H
#include <iostream>

struct List;

std::string getName(List *list);

// ������� ������, ������� ������ �������
List* makingList();

// ��������� �������� � ������
void addingData(List *&myList, std::string tempName, int tempPhoneNumber);

//�������� ������
void printData(List *head);

// ���������� ��������(�������� �������)
void mergeSort(List *&myList, char key);

// ������� ������
void deleteList(List *&myList);

List* nextNode(List *list);

int getNumber(List* list);

#endif // HEADER_H
