#include "stdafx.h"
#include "DoublyLinkedList.h"

clsDoublyLinkedList::clsDoublyLinkedList()
{
	//initialise head
	Head = NULL;
}

clsDoublyLinkedList::clsDoublyLinkedList(clsNode* n)
{
	//make head point at this very first node
	Head = n;
}



clsNode* clsDoublyLinkedList::KeyExist(uint32 k)
{

	//create a temp node points to null to return it in case we didn't find the key
	clsNode* NullNode = NULL;

	if (Head == NULL)
	{
		return NullNode;
	}

	clsNode* TempNode = Head;

	while (TempNode != NULL)
	{
		if (TempNode->Key == k)
		{
			return TempNode;
		}
		TempNode = TempNode->Next;

	}
	return NullNode;
}



void clsDoublyLinkedList::AppendNode(clsNode* n)
{
	if (clsDoublyLinkedList::KeyExist(n->Key) != NULL)
	{
		std::cout << "The key entered already exists\n";
	}

	//add node at the very start if linkedlist is empty
	if (Head == NULL)
	{
		Head = n;
		n->Next = NULL;
		n->Previous = Head;
	}
	else
	{
		clsNode* Temp = Head;

		while (Temp->Next != NULL)
		{
			Temp = Temp->Next;
		}
		n->Previous = Temp;
		Temp->Next = n;
		n->Next = NULL;
		std::cout << "Node appended successfully\n";
	}
}



void clsDoublyLinkedList::DisplayLinkedList(void)
{
	if (Head == NULL)
	{
		std::cout << "The linked list is empty, Nothing to display\n";
	}

	clsNode* TempNode = Head;

	while (TempNode != NULL)
	{
		std::cout << "Node Address : " << TempNode 
			<< "\tPrevious Address : " << TempNode->Previous
			<< "\tKey : " << TempNode->Key 
			<< "\tData : " << TempNode->Data
			<< "\tNext Address : " << TempNode->Next << "\n";

		TempNode = TempNode->Next;
	}
}