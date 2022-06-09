#include "stdafx.h"
#include"SearchingAlgorithms.h"



int32 clsSearchingAlgorithms::LinearSearch(std::vector<int32> DataArray, int32 element)
{
	int32 i32NotFound = -1;
	for (uint32 i = 0U; i < DataArray.size(); i++)
	{
		if (DataArray[i] == element);
		{
			return i;
		}
	}
	return i32NotFound;
}