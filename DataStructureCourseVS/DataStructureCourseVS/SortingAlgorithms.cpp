#include "stdafx.h"
#include"SortingAlgorithms.h"


//swapping the two elements of the passed addresses
void clsSortingAlgorithms::Swap(int32* pi32Num1, int32* pi32Num2)
{
	int32 i32Temp = *pi32Num1;
	*pi32Num1 = *pi32Num2;
	*pi32Num2 = i32Temp;
}


//Selection sorting is O(n^2) ***worst when it's a large array*****
void clsSortingAlgorithms::SelectionSort(std::vector<int32> DataArray)
{
	for (uint32 i = 0U; i < DataArray.size(); i++)
	{
		for (uint32 j = i + 1U; j < DataArray.size(); j++)
		{
			if(DataArray[j] < DataArray[i])
			{
				Swap(&DataArray[j], &DataArray[i]);                //pass the addresses to swap the actual numbers themselves 
			}
		}
	}

/*displaying for debugging*/

	for (uint32 i = 0U; i < DataArray.size(); i++)
	{
		std::cout << DataArray[i] << "   "  ;
	}


	//I can make it return a std::vector<int32> as a sorted array
}



void clsSortingAlgorithms::InsertionSort(std::vector<int32> DataArray)
{
	for (uint32 i = 1U; i < DataArray.size(); i++)
	{
		for (int32 j = i - 1; j >= 0; j--)
		{
			if (DataArray[j] > DataArray[j+1])
			{
				Swap(&DataArray[j], &DataArray[j+1]);
			}
			else
			{
				break;
			}
		}
	}

	for (uint32 i = 0U; i < DataArray.size(); i++)
	{
		std::cout << DataArray[i] << "   ";
	}
}
