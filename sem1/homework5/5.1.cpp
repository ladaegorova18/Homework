#include <locale>
#include <iostream>
#include <cstring>
#include "assert.h"
#include "header.h"
#include "options.cpp"
using namespace std;

void makingList(dynList *mylist)
{
    mylist->head = nullptr;
}

bool isEmpty(dynList *mylist)
{
    return (mylist->head == nullptr);
}

int test()
{
    dynList* testList = new dynList;
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
        cout << "���� �������" << endl;
            return 0;
        }
        else
        {
            assert(current->value <= current->next->value);
            current = current->next;
        }
    }
}

int menu(dynList *mylist)
{
    cout << "��� ������� ���� ��� ������ �� �������. �������:\n1, ����� �������� �������� � ������;\n2, ����� ������� �������� �� ������;\n3, ����� ����������� ������;\n0, ����� �����." << endl;;
    int key = -1;
    cin >> key;
    if (key == 0)
    {
        return 0;
    }
    switch (key)
    {
    case 1:
        {
            addingData(mylist);
            break;
        }
    case 2:
        {
            deleteData(mylist);
            break;
        }
    case 3:
        {
            printData(mylist);
            break;
        }
    }
    menu(mylist);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    test();
    dynList* mylist = new (dynList);
    makingList(mylist);
    menu(mylist);
    cout << "�� ��������!";
    return 0;
}
