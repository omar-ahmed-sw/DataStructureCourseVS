#pragma once
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>
#include <vector>



class clsSortingAlgorithms 
{
public:
	
	void Swap(int32* pi32Num1, int32* pi32Num2);
	void SelectionSort(std::vector<int32> DataArray);
	void InsertionSort(std::vector<int32> DataArray);
	void BubbleSort(std::vector<int32> DataArray);

	void MergeSort(int32 DataArray[], uint32 StartIndex, uint32 EndIndex);
	void Merge(int32 DataArray[],uint32 StartIndex,uint32 MidIndex,uint32 EndIndex);
	
	void QuickSort(int32 DataArray[], uint32 StartIndex, uint32 EndIndex);
	uint32 QuickPartitioning(int32 DataArray[], uint32 StartIndex, uint32 EndIndex);

	void CountingSort(int32 DataArray[], uint32 ArraySize, uint32 ArrayRange);

	void MyCountingSort(int32 DataArray[], uint32 ArraySize, const uint32 ArrayRange);
        

protected:

private:

};