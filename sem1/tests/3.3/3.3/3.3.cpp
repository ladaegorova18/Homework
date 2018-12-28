#include "pch.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
using namespace std;

void fileReading(ifstream &file, DynList* list, const int count)
{
	for (int i = 1; i <= count; i++)
	{
		int hourStart = 0;
		int minuteStart = 0;
		int hourEnd = 0;
		int minuteEnd = 0;
		file >> hourStart >> minuteStart >> hourEnd >> minuteEnd;
		int start = hourStart * 60 + minuteStart;
		int end = hourEnd * 60 + minuteEnd;
		insertion(list, start, true);
		insertion(list, end, false);
	}
}

void test()
{
	DynList *test = makingList();
	ifstream testFile("test.txt");
	if (!testFile)
	{
		cout << "Test file not found!" << endl;
		return;
	}
	fileReading(testFile, test, 6);
	testFile.close();
	assert(maxCount(test) == 2);
	deleteList(test);
	cout << "Test passed!" << endl;
}

int main()
{
	test();
	ifstream file("clients.txt");
	if (!file)
	{
		cout << "File not found!" << endl;
		return -1;
	}
	DynList *list = makingList();
	int count = 0;
	file >> count;
	fileReading(file, list, count);
	file.close();
	std::cout << "Max count of clients:" << std::endl;
	std::cout << maxCount(list);
	deleteList(list);
	return 0;
}