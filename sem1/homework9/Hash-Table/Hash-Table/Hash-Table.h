#pragma once
#include "List.h"
#include <vector>
#include <list>
#include <string>

struct Set
{
private:
	std::vector<List> buckets;
	int elements;

public:
	// ������� �������, ���������� ���� head ������� �������� nullptr
	void makeSet();

	// ��������� �������
	void adding(std::string data);

	// ��������� ������� �������� � ������� 
	bool exists(std::string const &str);

	// ������� ���-������� �� �����
	void printing();

	// ���������� ������������ ����� ������ � �������
	int theMaxLength();

	// ��������� ������� ����� ������ � �������
	int theAverageLength();
	
	// ��������� ����������� ������������� �������
	double coefHash();

	// ������� ���-�������
	void deleteSet();

	// �������, ������� ��� ���������� ������� �����
	int count(std::string const &data);

};

// ������� �������������� ������ � ���-�������
void statistics(Set* set);