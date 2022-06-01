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
		std::cout << "The key entered already exists, Can't Append this node\n";
	}

	
	else
	{
		//add node at the very start if linkedlist is empty
		if (Head == NULL)
		{
			Head = n;
			n->Next = NULL;
			n->Previous = Head;
			std::cout << "Node appended successfully\n";
		}
		else
		{
			clsNode* TempNode = Head;

			while (TempNode->Next != NULL)
			{
				TempNode = TempNode->Next;
			}
			n->Previous = TempNode;
			TempNode->Next = n;
			n->Next = NULL;

			std::cout << "Node appended successfully\n";
		}
	}
}


void clsDoublyLinkedList::PrependNode(clsNode* n) 
{
	//if list is already empty, just stick it to the front
	if (Head == NULL)
	{
		n->Previous = Head;
		Head = n;
		n->Next = NULL;
	}

	if (clsDoublyLinkedList::KeyExist(n->Key) != NULL)
	{
		std::cout << "The key entered already exist, Can't prepend this node\n";
	}
	else
	{
		//first make n points at the first element to keep this pointer
		n->Next = Head;
		//Make the previous pointer of node that head was pointing at points at n
	    Head->Previous = n;
		//Now head points at n
		Head = n;
		//now n previous points at head itself
		n->Previous = Head;
		std::cout << "The node prepended successfully\n";
	}
}

void clsDoublyLinkedList::DeleteNode(uint32 k)
{
	if (Head == NULL)
	{
		std::cout << "The list is empty, Nothing to delete\n";
	}

	else
	{
		if (clsDoublyLinkedList::KeyExist(k) == NULL)
		{
			std::cout << "The key you entered doesn't exist\n";
		}
		else
		{
			clsNode* TempNode = Head;

			while ((TempNode->Next)->Key != k)
			{
				TempNode = TempNode->Next;
			}
			//works but doesn't look easy to read 
			((TempNode->Next)->Next)->Previous = TempNode;
			TempNode->Next = (TempNode->Next)->Next;
			std::cout << "The node has been deleted successfully\n";
		}
	}
	
}

void clsDoublyLinkedList::ChangeNode(uint32 k, int32 d)
{
	if (Head == NULL)
	{
		std::cout << "The list is empty\n";
	}

	else
	{
		if (clsDoublyLinkedList::KeyExist(k) == NULL)
		{
			std::cout << "The key entered doesn't exist";
		}

		else
		{
			clsNode* TempNode = Head;
			while (TempNode->Key != k)
			{
				TempNode = TempNode->Next;
			}
			TempNode->Data = d;

			std::cout << "Data changed successfully\n";
		}

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
		std::cout << "\nNode Address : " << TempNode 
			<< "\tPrevious Address : " << TempNode->Previous
			<< "\tKey : " << TempNode->Key 
			<< "\tData : " << TempNode->Data
			<< "\tNext Address : " << TempNode->Next << "\n";

		TempNode = TempNode->Next;
	}
}