#pragma once
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>

class clsNode
{
public:
	int32 m_i32Data;
	uint32 m_u32Key;
	clsNode* m_pPrevious; //only being used in doubly linked list
	clsNode* m_pNext;

	clsNode()
	{
		m_i32Data = 0;
		m_u32Key = 0U;
		m_pPrevious = NULL;
		m_pNext = NULL;
	}

	clsNode(uint32 k, int32 d)
	{
		m_u32Key = k;
		m_i32Data = d;
	}

};
