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
		if (TempNode->m_u32Key == k)
		{
			return TempNode;
		}
		TempNode = TempNode->m_pNext;

	}
	return NullNode;
}



void clsDoublyLinkedList::AppendNode(clsNode* n)
{
	if (clsDoublyLinkedList::KeyExist(n->m_u32Key) != NULL)
	{
		std::cout << "The key entered already exists, Can't Append this node\n";
	}

	
	else
	{
		//add node at the very start if linkedlist is empty
		if (Head == NULL)
		{
			Head = n;
			n->m_pNext = NULL;
			n->m_pPrevious = Head;
			std::cout << "Node appended successfully\n";
		}
		else
		{
			clsNode* TempNode = Head;

			while (TempNode->m_pNext != NULL)
			{
				TempNode = TempNode->m_pNext;
			}
			n->m_pPrevious = TempNode;
			TempNode->m_pNext = n;
			n->m_pNext = NULL;

			std::cout << "Node appended successfully\n";
		}
	}
}


void clsDoublyLinkedList::PrependNode(clsNode* n) 
{
	//if list is already empty, just stick it to the front
	if (Head == NULL)
	{
		n->m_pPrevious = Head;
		Head = n;
		n->m_pNext = NULL;
	}

	if (clsDoublyLinkedList::KeyExist(n->m_u32Key) != NULL)
	{
		std::cout << "The key entered already exist, Can't prepend this node\n";
	}
	else
	{
		//first make n points at the first element to keep this pointer
		n->m_pNext = Head;
		//Make the previous pointer of node that head was pointing at points at n
	    Head->m_pPrevious = n;
		//Now head points at n
		Head = n;
		//now n previous points at head itself
		n->m_pPrevious = Head;
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

			while ((TempNode->m_pNext)->m_u32Key != k)
			{
				TempNode = TempNode->m_pNext;
			}
			//works but doesn't look easy to read 
			((TempNode->m_pNext)->m_pNext)->m_pPrevious = TempNode;
			TempNode->m_pNext = (TempNode->m_pNext)->m_pNext;
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
			std::cout << "The key entered doesn't exist\n";
		}

		else
		{
			clsNode* TempNode = Head;
			while (TempNode->m_u32Key != k)
			{
				TempNode = TempNode->m_pNext;
			}
			TempNode->m_i32Data = d;

			std::cout << "Data changed successfully\n";
		}

	}
}

void clsDoublyLinkedList::InsertNode(uint32 k, clsNode* n)
{
	if (clsDoublyLinkedList::KeyExist(n->m_u32Key) != NULL)
	{
		std::cout << "Node with the same key already exist, Can't insert node\n";
	}
	else if (clsDoublyLinkedList::KeyExist(k) == NULL)
	{
		std::cout << "The key to insert after doesn't exist\n";
	}

	else
	{
		if (Head == NULL)
		{
			n->m_pPrevious = Head;
			Head = n;
			n->m_pNext = NULL;
		}
		else
		{
			clsNode* TempNode = Head;

			while (TempNode->m_u32Key != k)
			{
				TempNode = TempNode->m_pNext;
			}

			n->m_pNext = TempNode->m_pNext;
			(TempNode->m_pNext)->m_pPrevious = n;
			TempNode->m_pNext = n;
			n->m_pPrevious = TempNode;
			std::cout << "Node inserted successfully\n";
		}
	}
}
void clsDoublyLinkedList::DisplayNode(uint32 k)
{
	if (Head == NULL)
	{
		std::cout << "The list is empty, Nothing to display\n";
	}
	else 
	{
		if(clsDoublyLinkedList::KeyExist(k) == NULL)
		{
			std::cout << "The key entered doesn't exist\n";
		}

		else
		{
			clsNode* TempNode = Head;

			while (TempNode->m_u32Key != k)
			{
				TempNode = TempNode->m_pNext;
			}

			std::cout << "\nNode Address : " << TempNode
				<< "\tPrevious Address : " << TempNode->m_pPrevious
				<< "\tKey : " << TempNode->m_u32Key
				<< "\tData : " << TempNode->m_i32Data
				<< "\tNext Address : " << TempNode->m_pNext << "\n";
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
			<< "\tPrevious Address : " << TempNode->m_pPrevious
			<< "\tKey : " << TempNode->m_u32Key
			<< "\tData : " << TempNode->m_i32Data
			<< "\tNext Address : " << TempNode->m_pNext << "\n";

		TempNode = TempNode->m_pNext;
	}
}