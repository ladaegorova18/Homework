#include "pch.h"
#include "Hash-Table.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

void test()
{

}

int main()
{
	setlocale(LC_ALL, "rus");
	Set* set = new Set();
	set->makeSet();
	ifstream file("text.txt");
	if (!file)
	{
		cout << "���� �� ������!" << endl;
		return -1;
	}
	while (!file.eof())
	{
		string buffer = " ";
		file >> buffer;
		set->adding(buffer);
	}
	file.close();
	cout << "�����, ������������� � ���� ������:" << endl;
	set->printing();
	set->statistics();
	set->deleteSet();
	cout << "�� ��������!" << endl;
	system("pause");
	return 0;
}