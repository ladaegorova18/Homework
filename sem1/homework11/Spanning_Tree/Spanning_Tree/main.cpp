#include "pch.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <locale>

void test()
{
	Graph *test = new Graph(4);
	test->addNode(1, 0, 1);
	test->addNode(1, 1, 0);
	test->addNode(1, 1, 2);
	test->addNode(1, 2, 1);
	test->addNode(1, 2, 3);
	test->addNode(1, 3, 2);
	test->algorithmPrima();
	
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::ifstream file("matrix.txt");
	std::cout << "Enter count of vertices:" << std::endl;
	int size = 0;
	std::cin >> size;
	Graph *graph = new Graph(size);
	if (!file)
	{
		std::cout << "Файл не найден!" << std::endl;
		return -1;
	}
	int value = 0;
	while (!file.eof())
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				file >> value;
				if (value != 0)
				{
					graph->addNode(value, i, j);
				}
			}
		}
	}
	file.close();
	graph->algorithmPrima();
	std::cout << "Наименьшее остовное дерево этого графа:" << std::endl;
	//graph->printResult();
	graph->deleteGraph();
	std::cout << "До свидания!" << std::endl;
	return 0;
}