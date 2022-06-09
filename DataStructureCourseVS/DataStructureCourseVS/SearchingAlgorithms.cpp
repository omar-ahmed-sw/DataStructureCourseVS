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


int32 clsSearchingAlgorithms::BinarySearch(std::vector<int32>SortedDataArray, int32 element)
{
	int32 i32NotFound = -1;
	uint32 u32LeftIndex = 0U;
	uint32 u32MidIndex = SortedDataArray.size() / 2U;
	uint32 u32RightIndex = SortedDataArray.size() - 1U;

	while (u32LeftIndex <= u32RightIndex)
	{
		u32LeftIndex = (element > SortedDataArray[u32MidIndex]) ? (u32MidIndex + 1U) : (u32LeftIndex);
		u32RightIndex = (element > SortedDataArray[u32MidIndex]) ? (u32RightIndex) : (u32MidIndex - 1U);
		u32MidIndex = (element > SortedDataArray[u32MidIndex]) ? (u32LeftIndex + ((u32RightIndex - u32LeftIndex)  /2U)) : (u32RightIndex - ((u32RightIndex - u32LeftIndex) / 2U));
		if (SortedDataArray[u32MidIndex] == element)
		{
			return u32MidIndex;
		}	
	}

	return i32NotFound;
}