#include "pch.h"
#include "List.h"
#include <iostream>

int main()
{
	Node* head = new Node();
	head = nullptr;
	add(head, 3);
	add(head, 4);
	add(head, 1);
	add(head, 8);

	print(head);
	reverse(head);
	print(head);
	deleteList(head);
}