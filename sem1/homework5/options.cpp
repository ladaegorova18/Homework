#include <iostream>
using namespace std;

int insertion(dynList *mylist, int newValue)
{
    Element* data = new Element;
    Element* previous = nullptr;
    data->value = newValue;
    if (isEmpty(mylist))
    {
        mylist->head = data;
        data->next = nullptr;
        return 0;
    }
    else
    {
        Element* current = mylist->head;
        while (current != nullptr)
        {
            if (current->value >= newValue)
            {
                data->next = current;
                if (previous != nullptr)
                {
                    previous->next = data;
                }
                else
                {
                    mylist->head = data;
                }
                return 0;
            }
        previous = current;
        current = current->next;
        }
    previous->next = data;
    }
}

int addingData(dynList *mylist)
{
    cout << "����� �� ������ ��������� ���������� � ������. ��� ������ ������� Q;\n";
    char key = ' ';
    cin >> key;
    while (key != 'Q')
    {
        cout << "������� �����:" << endl;
        int newValue = (int)key - 48;
        insertion(mylist, newValue);
        cin >> key;
    }
}

void deleteData(dynList *mylist)
{
    cout << "����� ����� ������� ������������� �������� �� ������. ������� �������� ��� ������� Q, ����� �����:" << endl;
    char key = ' ';
    cin >> key;
    if (key != 'Q')
    {
        int order = (int)key - 48;
        Element* current = mylist->head; // �������� �� ���� ��������� � ���������� ������ � ����� "�������"
        Element* previous = nullptr;
        while (current != nullptr)
        {
            if (current->value == order) // ���� �������, �� ������� �� ����������
            {
                if (previous == nullptr) // ���� ��� ���, �� �� ��������� � ������ ������ � ����� �������� head �� ���������
                {
                    mylist->head = mylist->head->next;
                }
                else
                {
                    previous->next = current->next; // ���� �� ����, �� ������ ��������� �� ��� �� �������, � ��������� �� �������
                }
            }
            previous = current;
            current = current->next;
        }
    }
    cout << "�������� �������!";
}

void printData(dynList *mylist)
{
    if (mylist->head == nullptr)
    {
        cout << "������ ����:(" << endl;
    }
    else
    {
        cout << "������ ������ �������� ���:" << endl;
        struct Element *current;
        current = mylist->head;
        while (current)
        {
            cout << current->value << endl;
            cout << endl;
            current = current->next;
        }
    }
}
