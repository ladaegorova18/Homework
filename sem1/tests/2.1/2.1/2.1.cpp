#include "pch.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <assert.h>
using namespace std;

void sort(std::vector<std::vector<int>> &matrix, int rows, int columns);

void print(std::vector<std::vector<int>> matrix, int rows, int columns);

void clear(std::vector<std::vector<int>> matrix, int columns)
{
	for (int i = 0; i < columns; ++i)
	{
		matrix[i].clear();
	}
}

void test()
{
	std::vector<std::vector<int>> test;
	int rows = 6;
	int columns = 5;
	test.resize(rows);
	for (int i = 0; i < rows; ++i)
	{
		test[i].resize(columns);
	}
	ifstream file("test.txt");
	if (!file)
	{
		std::cout << "File not found!" << std::endl;
		clear(test, columns);
		return;
	}
	while (!file.eof())
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				int value = 0;
				file >> value;
				test[i][j] = value;
			}
		}
	}
	file.close();
	sort(test, rows, columns);
	for (int i = 0; i < columns - 1; ++i)
	{
		assert(test[0][i] <= test[0][i + 1]);
	}
	clear(test, columns);
	std::cout << "Тест пройден!" << std::endl;
}

void sort(std::vector<std::vector<int>> &matrix, int rows, int columns)
{
	int k = columns - 1;
	while (k > -1)
	{
		int id = 0;
		for (int j = 0; j < k - 1; ++j)
		{
			if (matrix[0][j] > matrix[0][id])
			{
				id = j;
			}
		}
		for (int i = 0; i < rows; ++i)
		{
			std::swap(matrix[i][id], matrix[i][k]);
		}
		--k;
	}
}

void print(std::vector<std::vector<int>> matrix, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	test();
	std::vector<std::vector<int>> matrix;
	int rows = 6;
	int columns = 5;
	matrix.resize(rows);
	for (int i = 0; i < rows; ++i)
	{
		matrix[i].resize(columns);
	}
	ifstream file("matrix.txt");
	if (!file)
	{
		std::cout << "Файл не найден!" << std::endl;
		return -1;
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			int value = 0;
			file >> value;
			matrix[i][j] = value;
		}
	}
	file.close();
	std::cout << "Изначальный массив:" << std::endl;
	print(matrix, rows, columns);
	sort(matrix, rows, columns);
	std::cout << "Итоговый массив:" << std::endl;
	print(matrix, rows, columns);
	clear(matrix, columns);
	return 0;
}