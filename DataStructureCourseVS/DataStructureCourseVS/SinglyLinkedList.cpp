#include "stdafx.h"
#include "SinglyLinkedList.h"


clsSinglyLinkedList::clsSinglyLinkedList()
{
	//initialise head
	Head = NULL;
}

clsSinglyLinkedList::clsSinglyLinkedList(clsNode* n)
{
	//make head point at this very first node
	Head = n;
}

//to check if the key exists in the linked list or not to avoid duplication
clsNode* clsSinglyLinkedList::KeyExist(uint16 K)
{
	//create a temp node points to null to return it in case we didn't find the key
	clsNode* NullNode = NULL;

	//create a local temp node to traverse the entire linked list
	clsNode* TempNode = Head;

	//traverse until the last node which points to NULL
	while (TempNode != NULL)
	{
		if (TempNode->Key == K)
		{
			return TempNode;
		}
		TempNode = TempNode->Next;
	}
	return NullNode;
}

//Add node at the end
void clsSinglyLinkedList::AppendNode(clsNode* n)
{
	//check first if the key exists in the linked list
	if (clsSinglyLinkedList::KeyExist(n->Key) != NULL)
	{
		std::cout << "The key you entered of " << n->Key << " already exists\n";
	}

	else
	{
		//if linked list already empty
		if (Head == NULL)
		{
			Head = n;
			n->Next = NULL; //he doesn't add this one??
			std::cout << "Node appended successfully\n";
		}

		else
		{
			//create a local temp node to traverse the entire linked list
			clsNode* TempNode = Head;

			//traverse the linked list until last node
			while (TempNode->Next != NULL)
			{
				TempNode = TempNode->Next;
			}

			TempNode->Next = n;
			n->Next = NULL;   //he doesn't add this one??
			std::cout << "Node appended successfully\n";
		}
	}

}

//add node at the start
void clsSinglyLinkedList::PrependNode(clsNode* n)
{
	if (clsSinglyLinkedList::KeyExist(n->Key) != NULL)
	{
		std::cout << "The key you entered of " << n->Key << " already exists\n";
	}

	else
	{
		//first make n points at the first element to keep this pointer
		n->Next = Head;
		//Then make head points at new element as it's the first one now
		Head = n;
		std::cout << "Node prepended successfully\n";

	}
}

void clsSinglyLinkedList::DeleteNode(uint16 K)
{
	if (clsSinglyLinkedList::KeyExist(K) == NULL)
	{
		std::cout << "The key you entered of " << K << " doesn't exists\n";
	}
	else
	{
		clsNode* TempNode = Head;

		//if the node is the evry first one
		if (TempNode->Key == K)
		{
			Head = TempNode->Next;
			std::cout << "The node of key " << K << " has been deleted successfully\n";

		}

		else
		{
			//keep checking if the next one is the key we are looking for
			while ((TempNode->Next)->Key != K)
			{
				TempNode = TempNode->Next;
			}
			//make the previous one to this node points at the next one of this node as bypass
			TempNode->Next = (TempNode->Next)->Next;
			std::cout << "The node of key " << K << " has been deleted successfully\n";
		}
	}
	//technically the node is still there but we lost it's address and built a bypass link
}


//insert a node after a certain node in the list
void clsSinglyLinkedList::InsertNode(uint16 K, clsNode* n)
{
	if (clsSinglyLinkedList::KeyExist(K) == NULL)
	{
		std::cout << "The key you entered of " << K << " doesn't exists\n";
	}

	else
	{
		//if the key of this node already exist
		if (clsSinglyLinkedList::KeyExist(n->Key) != NULL)
		{
			std::cout << "The key you entered of " << n->Key << " already exists\n";
		}
		else
		{
			clsNode* TempNode = Head;
			while (TempNode->Key != K)
			{
				TempNode = TempNode->Next;
			}
			n->Next = TempNode->Next;
			TempNode->Next = n;
		}
	}
}


void clsSinglyLinkedList::ChangeNode(uint16 K, int16 D)
{
	if (clsSinglyLinkedList::KeyExist(K) == NULL)
	{
		std::cout << "The key you entered of " << K << " doesn't exists\n";
	}

	else
	{
		clsNode* TempNode = Head;
		while (TempNode->Key != K)
		{
			TempNode = TempNode->Next;
		}

		TempNode->Data = D;
		std::cout << "Node changed successfully\n";
	}
}

void clsSinglyLinkedList::DisplayNode(uint16 K)
{
	if (clsSinglyLinkedList::KeyExist(K) == NULL)
	{
		std::cout << "The key you entered of " << K << " doesn't exists\n";
	}
	else
	{
		clsNode* TempNode = Head;
		while (TempNode->Key != K)
		{
			TempNode = TempNode->Next;
		}
		std::cout << "Node address: " << TempNode << "\tNode key: " << TempNode->Key
			<< "\tNode data: " << TempNode->Data << "\tNode next:" << TempNode->Next
			<< "\n";
	}
}

void clsSinglyLinkedList::DisplayLinkedList(void)
{

	if (Head == NULL)
	{

		std::cout << "The linked list is empty\n";
	}

	else
	{
		clsNode* TempNode = Head;

		while (TempNode != NULL)
		{
			std::cout << "Node address: " << TempNode << "\tNode key: " << TempNode->Key
				<< "\tNode data: " << TempNode->Data << "\tNode next:" << TempNode->Next
				<< "\n";

			TempNode = TempNode->Next;
		}
	}
}

