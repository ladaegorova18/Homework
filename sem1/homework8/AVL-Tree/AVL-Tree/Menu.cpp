#include "pch.h"
#include "Menu.h"
using namespace std;

void mainText()
{
	cout << "������������! ��� ������� ����. �������:" << endl;
	cout << "1, ����� �������� �������� �� ��������� ����� � ������������� ������;" << endl;
	cout << "2, ����� �������� �������� �� ��������� ����� �� �������������� �������;" << endl;
	cout << "3, ����� ��������� ������� ��������� �����;" << endl;
	cout << "4, ����� ������� �������� ���� � ��������� � ��� �������� �� �������������� �������;" << endl;
	cout << "0, ����� �����." << endl;
}

string readString()
{
	string data = " ";
	cin >> data;
	return data;
}

int readKey()
{
	int key = 0;
	cin >> key;
	return key;
}

void mainMenu(Tree* myTree)
{
	mainText();
	char option = ' ';
	cin >> option;
	while (option != '0')
	{
		switch (option)
		{
		case '1':
		{
			cout << "����� ����� �������� �������� � ������������� ������. ������� ����:" << endl;
			int index = readKey();
			cout << "������� ��������:" << endl;
			string data = readString();
			Node* root = myTree->getRoot();
			if (myTree->adding(data, index, root))
			{
				cout << "�������� ���������!" << endl;
			}
			break;
		}
		case '2':
		{
			cout << "������� ����, ����� �������� ������� ��������:" << endl;
			int key = readKey();
			Node* root = myTree->getRoot();
			cout << "������� ��������: " << myTree->getData(key, root) << endl;
			break;
		}
		case '3':
		{
			cout << "������� ����, ����� ��������� ��� �������:" << endl;
			int key = readKey();
			Node* root = myTree->getRoot();
			if (myTree->isEmpty())
			{
				cout << "������ ����:(" << endl;
			}
			else if (myTree->findData(key, root) != nullptr)
			{
				cout << "���� ���� � �������:)" << endl;
			}
			else
			{
				cout << "����� ��� � �������:(" << endl;
			}
			break;
		}
		case '4':
		{
			cout << "������� ����, ����� ������� ��� � ��������� � ��� ��������:" << endl;
			int key = readKey();
			Node* root = myTree->getRoot();
			if (myTree->isEmpty())
			{
				break;
			}
			if (myTree->findData(key, root) != nullptr)
			{
				myTree->deleteData(key, root);
				cout << "�������� �������!" << endl;
			}
			break;
		}
		}
		mainText();
		cin >> option;
	}
	cout << "�� ��������!" << endl;
}
