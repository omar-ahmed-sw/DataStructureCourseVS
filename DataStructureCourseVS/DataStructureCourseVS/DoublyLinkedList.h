#pragma once
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>

using namespace std;

class clsNode
{
public:
	int32 Data;
	uint32 Key;
	clsNode* Previous;
	clsNode* Next;

	clsNode()
	{
		Data = 0;
		Key = 0U;
		Previous = NULL;
		Next = NULL;
	}

	clsNode(uint32 K, int32 D)
	{
		Key = K;
		Data = D;
	}

};
class clsDoublyLinkedList : public clsNode
{
	clsNode* Head;

	clsDoublyLinkedList();
	clsDoublyLinkedList(clsNode* n);

	void AppendNode(clsNode* n);
	clsNode* KeyExist(uint32 k);

};
