﻿#include "pch.h"
#include <ctype.h>
#include <iostream>
#include "MathTree.h"

struct Element
{
	char operation = ' ';
	Element* leftChild = nullptr;
	Element* rightChild = nullptr;
	Element* parent = nullptr;
	int value = 0;
};

struct Tree
{
	Element* root;
};

Element* makeElement()
{
	Element* temp = new Element();
	return temp;
}

Tree* makeTree()
{
	Tree* tree = new Tree();
	tree->root = nullptr;
	return tree;
}

int operation(const char operand, const int firstNumber, const int secondNumber)
{
	switch (operand)
	{
	case '+':
	{
		return firstNumber + secondNumber;
	}
	case '-':
	{
		return firstNumber - secondNumber;
	}
	case '*':
	{
		return firstNumber * secondNumber;
	}
	case '/':
	{
		return firstNumber / secondNumber;
	}
	}
	return 0;
}

bool isOperation(char symbol)
{
	return ((symbol == '/') || (symbol == '*') || (symbol == '+') || (symbol == '-'));
}

Element* getRoot(Tree* tree)
{
	return tree->root;
}

int count(Element* current)
{
	if ((current->leftChild == nullptr) && (current->rightChild == nullptr))
	{
		return current->value;
	}
	current->value = operation(current->operation, count(current->leftChild), count(current->rightChild));
	return current->value;
}

bool isEmpty(Tree* tree)
{
	return (tree->root == nullptr);
}

Element* adding(Tree*& tree, const char symbol, Element *current)
{
	if (symbol == ')')
	{
		if (current->parent != nullptr)
		{
			current = current->parent;
		}
		return current;
	}
	Element *temp = new Element();
	if (isOperation(symbol))
	{
		temp->operation = symbol;
		temp->value = 'N';
		if (isEmpty(tree))
		{
			tree->root = temp;
			current = tree->root;
		}
		else
		{
			temp->parent = current;
			if (current->leftChild == nullptr)
			{
				current->leftChild = temp;
				current = current->leftChild;
			}
			else if (current->rightChild == nullptr)
			{
				current->rightChild = temp;
				current = current->rightChild;
			}
		}
	}
	else if (isdigit(symbol))
	{
		temp->value = symbol - '0';
		temp->parent = current;
		if (current->leftChild == nullptr)
		{
			current->leftChild = temp;
		}
		else
		{
			current->rightChild = temp;
		}
	}
	else
	{
		delete temp;
	}
	return current;
}

void printing(Element *current, const int level)
{
	if (current != nullptr)
	{
		printing(current->leftChild, level + 1);
		for (int i = 0; i < level; i++)
		{
			std::cout << "\t";
		}
		if (current->value != 'N')
		{
			std::cout << current->value << "\n";
		}
		else
		{
			std::cout << current->operation << "\n";
		}
		printing(current->rightChild, level + 1);
	}
}

void deleteElements(Element*& current)
{
	if (current)
	{
		deleteElements(current->leftChild);
		deleteElements(current->rightChild);
		delete current;
	}
}

void deleteTree(Tree*& tree)
{
	deleteElements(tree->root);
	delete tree;
}