#include "pch.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
using namespace std;

void fileRead(ifstream &file, DynamicList* list, const int count)
{
	for (int i = 1; i <= count; i++)
	{
		int hourStart = 0;
		int minuteStart = 0;
		int hourEnd = 0;
		int minuteEnd = 0;
		file >> hourStart >> minuteStart >> hourEnd >> minuteEnd;
		int start = hourStart;
		int end = hourEnd;
		insertion(list, start, true);
		insertion(list, end, false);
	}
}

void test()
{
	DynamicList *test = makingList();
	ifstream testFile("test.txt");
	if (!testFile)
	{
		cout << "Test file not found!" << endl;
		return;
	}
	fileRead(testFile, test, 6);
	testFile.close();
	assert(maxCount(test) == 3);
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
	DynamicList *list = makingList();
	int count = 0;
	file >> count; 
	fileRead(file, list, count);
	file.close();
	std::cout << maxCount(list);
	deleteList(list);
	return 0;
}