#pragma once
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>

class clsNode
{
public:
	int32 Data;
	uint32 Key;
	clsNode* Previous; //only being used in doubly linked list
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
