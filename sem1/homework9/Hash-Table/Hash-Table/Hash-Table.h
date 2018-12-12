#pragma once
#include <vector>
#include <list>
#include <string>
const int SIZE = 100;

struct Node
{
	std::string data;
	int count;
	Node(std::string newData)
	{
		data = newData;
		count = 1;
	}
};

struct Set
{
	std::vector<std::list<Node>> buckets;
	int elements;
};

// ������� �������������� ������ � ���-�������
void statistics(Set set);

// ������� �������, ���������� ���� head ������� �������� nullptr
void makeSet(Set& set);

// ��������� �������
void adding(Set& set, std::string data);

// ��������� ������� �������� � ������� 
bool exists(Set set, std::string str);

// ������� ���-������� �� �����
void printing(Set set);

// �������, ������� ��� ���������� ������� �����
int count(Set set, std::string data);

// ��������� ������� ����� ������ � �������
int theAverageLength(Set set);

// ���������� ������������ ����� ������ � �������
int theMaxLength(Set set);

// ��������� ����������� ������������� �������
double coefHash(Set set);

// ������� ���-�������
void deleteSet(Set set);