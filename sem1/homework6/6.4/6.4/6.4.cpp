#include "pch.h"
#include <iostream>
#include <locale>
#include <fstream>
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	DynList *myList = new DynList();
	makingList(myList);
	ifstream file;
	file.open("phonebook.txt");
	if (!file)
	{
		cout << "Файл не найден!" << endl;
		return 0;
	}
	while (!file.eof())
	{
		string tempName = "";
		string tempPhoneNumber = "";
		file >> tempName;
		file >> tempPhoneNumber;
		addingData(myList, tempName, tempPhoneNumber);
	}
	file.close();
	/*cout << "Выберите, как отсортировать записи в файле: по имени (нажмите 1) или по номеру телефона (нажмите 2)" << endl;
	
	
	(key == '1') ? nameSorting(myList) : phoneNumberSorting(myList);*/
	
	mergeSort(myList->head);

	cout << "Отсортированный файл выглядит так:" << endl;
	printData(myList->head);
	delete[] myList;
	return 0;
}

