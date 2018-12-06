#pragma once
#include <iostream>
#include <string>

struct Node
{
	Node* leftChild;
	Node* rightChild;
	std::string data;
	int key;
	int height;
	Node(int index, std::string newData) { 
		key = index; 
		data = newData;
		leftChild = nullptr; 
		rightChild = nullptr; 
		height = 1; 
	}
};

struct Tree
{
private:
	Node* root;
	int count;

public:
	// �������� ������, �������� ������ ������
	void makeTree();
	// ���������, ������ ������ ��� ���
	bool isEmpty();
	// ��������� �������� � ������
	Node* adding(std::string newData, const int index, Node* temp);
	// �������� �������� �� �����
	std::string getData(const int key, Node* temp);
	// ��������� ������� ��������� �����
	Node* findData(const int key, Node* temp);
	// ������� �������� �� ������
	Node* deleteData(const int key, Node* temp);
	// ������� ������� �� ����� ������
	Node* deleteFromRoot();
	// ���������� ������
	Node* getRoot();
	// ������� ������
	void deleteTree(Node* temp);
	// ���������� ���������� ��������� � �������
	int getSize();
};