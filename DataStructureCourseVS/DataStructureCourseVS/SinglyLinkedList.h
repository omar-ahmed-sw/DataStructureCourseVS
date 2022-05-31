#pragma once
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>
#include "NodeHandler.h"


using namespace std;

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



