#pragma once
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>
#include "NodeHandler.h"

using namespace std;


class clsDoublyLinkedList : public clsNode
{
public:

	clsNode* Head;

	clsDoublyLinkedList();
	clsDoublyLinkedList(clsNode* n);

	void AppendNode(clsNode* n);
	void PrependNode(clsNode* n);
	void InsertNode(uint32 k, clsNode* n);
	void DeleteNode(uint32 k);
	void DisplayLinkedList(void);
	void ChangeNode(uint32 k, int32 d);
	clsNode* KeyExist(uint32 k);

protected:

private:

};
