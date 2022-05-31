#pragma once
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>



//#include "NodeHandler.hpp"
using namespace std;





class clsNode
{
public:
	//struct Node
	//{
	int16 Data;
	uint16 Key;   //like an index for elements
	clsNode* Next;
	//	};

	//clsNode node;

	clsNode()
	{
		Key = 0U;
		Data = 0;
		Next = NULL;
	}

	clsNode(uint16 K, int16 D)
	{
		Key = K;
		Data = D;
	}

};


class clsSinglyLinkedList : public clsNode
{
public:

	clsNode* Head;
	//Node* Current;

	clsSinglyLinkedList();
	//default constructor to create singly linked list and point at head to start
	clsSinglyLinkedList(clsNode* n);

	void AppendNode(clsNode* n);
	void PrependNode(clsNode* n);
	void InsertNode(uint16 K, clsNode* n);
	void DeleteNode(uint16 K);
	void ChangeNode(uint16 K, int16 D);
	void DisplayLinkedList(void);
	void DisplayNode(uint16 K);
	clsNode* KeyExist(uint16 K);

protected:

private:



};



