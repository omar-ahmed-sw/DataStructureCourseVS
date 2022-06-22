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
	void MergeSort(std::vector<int32> DataArray, uint32 StartIndex, uint32 EndIndex);
	void Merge(std::vector<int32> DataArray,uint32 StartIndex,uint32 MidIndex,uint32 EndIndex);
        

protected:

private:

};