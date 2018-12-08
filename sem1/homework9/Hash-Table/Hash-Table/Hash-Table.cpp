#include "pch.h"
#include "Hash-Table.h"
#include <iostream>
const int SIZE = 100;
using namespace std;

void Set::makeSet()
{
	int size = SIZE;
	buckets.resize(size);
	for (int i = 0; i < size; i++)
	{
		buckets[i].makeList();
	}
}

int hashFunction(std::string const &str)
{
	int sum = 0;
	for (size_t i = 0; i < str.size(); ++i)
	{
		sum += sum * 5 + str[i];
	}
	return sum;
}

void Set::adding(std::string data)
{
	elements++;
	int hash = hashFunction(data) % buckets.size();
	if (hash < 0)
	{
		hash *= -1;
	}
	if (!exists(data))
	{
		buckets[hash].adding(data);
	}
	else
	{
		buckets[hash].getNode(data)->count++;
	}
}

bool Set::exists(std::string const &data)
{
	int hash = hashFunction(data) % buckets.size();
	return buckets[hash].find(data);
}

void Set::printing()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (!buckets[i].isEmpty())
		{
			buckets[i].printing(i);
		}
	}
}

void Set::deleteSet()
{
	for (int i = 0; i < SIZE; i++)
	{
		buckets[i].deleteList();
	}
}

int Set::theAverageLength()
{
	int arifMean = 0;
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (!buckets[i].isEmpty())
		{
			arifMean += buckets[i].getLength();
			count++;
		}
	}
	return arifMean /= count;
}

int Set::theMaxLength()
{
	int max = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (max < buckets[i].getLength())
		{
			max = buckets[i].getLength();
		}
	}
	return max;
}

double Set::coefHash()
{
	return elements / (double) buckets.size();
}

void Set::statistics()
{
	cout << "Средняя длина списка таблицы: " << theAverageLength() << endl;
	cout << "Максимальная длина списка таблицы: " << theMaxLength() << endl;
	cout << "Коэффициент заполнения таблицы: " << coefHash() << endl;
}