#pragma once

struct Element
{
	char operand;
	Element* leftChild;
	Element* rightChild;
	Element* parent;
	int value;
};

struct Tree
{
private:
	Element* root;
public:
	// ��������� ��������� ��������������� ���������
	int count(Element* current);
	// ������� ������ ������ � ������ ����� nullptr'���
	void makeTree();
	// ��������� ������ �� ��������� �� ���� ����� � ������
	Element* adding(const char symbol, Element *current);
	// ����������, ����� �� ������ nullptr
	bool isEmpty();
	// ���������� ������ ������
	Element* getRoot();
	// �������� ������ � ����� ����
	void printing(Element* current, const int level);
	// ������� ������
	void deleteTree(Element* current);
};