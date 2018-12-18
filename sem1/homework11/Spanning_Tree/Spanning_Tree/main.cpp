#include "pch.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <assert.h>

void test()
{
	Graph test;
	makeGraph(test, 4);
	addNode(test, 1, 0, 1);
	addNode(test, 1, 1, 0);
	addNode(test, 1, 1, 2);
	addNode(test, 1, 2, 1);
	addNode(test, 1, 2, 3);
	addNode(test, 1, 3, 2);
	algorithmPrima(test);
	int parents[] = {0, 0, 2, 3};
	int currentVert[] = { 0, 1, 2, 3 };
	int distances[] = { 0, 1, 1, 1 };
	for (int i = 0; i < 4; ++i)
	{
		assert(test.parent[i] == parents[i]);
		//assert(test.) keys
	}
	std::cout << "Тест пройден!" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	test();
	std::ifstream file("matrix.txt");
	std::cout << "Enter count of vertices:" << std::endl;
	int size = 0;
	std::cin >> size;
	Graph graph;
	makeGraph(graph, size);
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
					addNode(graph, value, i, j);
				}
			}
		}
	}
	file.close();
	algorithmPrima(graph);
	std::cout << "Наименьшее остовное дерево этого графа:" << std::endl;
	//graph->printResult();
	deleteGraph(graph);
	std::cout << "До свидания!" << std::endl;
	return 0;
}