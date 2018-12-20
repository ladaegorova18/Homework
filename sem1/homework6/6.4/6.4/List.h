#ifndef HEADER_H
#define HEADER_H
#include <iostream>

struct List;

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

#endif // HEADER_H
