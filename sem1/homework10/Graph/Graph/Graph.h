#pragma once
#include <vector>
#include <iostream>
const int INF = 1000000000;

struct Map
{
	// ������ ���������� ����� ��������
	std::vector< std::vector<int> > roads;

	// kingdoms[i] ������ ����������; � ������ ���� ������ ��������, ������������� ��
	std::vector< std::vector<int> > kingdoms;

	// �������� ����� ������, � ������� ����
	std::vector <bool> mark;

	// ������ ����������
	void war();
};

// ����� �� ����� ���������� � �� ��������
void printing(std::vector< std::vector<int> > kingdoms);
