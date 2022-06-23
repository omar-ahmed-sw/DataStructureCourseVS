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



//Insertion sort is based on having a subarray that's sorted on the left hand side
//and everytime you pick next element in line, go put it where it should be in sorted subarray on the left
//by shifting all the elements to accomodate that new one in its right position. until last element 
//TIME COMPLEXITY : O(n^2)

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

	/*displaying for debugging*/
	for (uint32 i = 0U; i < DataArray.size(); i++)
	{
		std::cout << DataArray[i] << "   ";
	}
}


//bubble sort is based on swapping every 2 adjecenet elemnts if right side < left side keep doing that until end of array, for number of array elements times
//TIME COMPLEXITY : O(n^2)
void clsSortingAlgorithms::BubbleSort (std::vector <int32> DataArray)
{
	for (uint32 i = 0U; i < DataArray.size(); i++)
	{
		bool Flag = false;
		for (uint32 j = 0U; j < DataArray.size() - 1U - i; j++)      //-i to discount the right side element/s which have been sorted already and no need to repeat them again 
		{
			if (DataArray[j] > DataArray[j + 1])
			{
				Swap(&DataArray[j], &DataArray[j + 1]);
				Flag = true;
			}
		}
		if(!Flag)   //optimising, to reduce time, if we didn't swap at least once in the last iteration, so no need to continue next time as it's sorted already
		{
			break;
		}
	}

	/*displaying for debugging*/
	for (uint32 i = 0U; i < DataArray.size(); i++)
	{
		std::cout << DataArray[i] << "   ";
	}
}


//Merge sort is dividing conqure algorithm
//Time Complexity : O(nlog(n))
void clsSortingAlgorithms::MergeSort(std::vector<int32> DataArray, uint32 StartIndex, uint32 EndIndex)
{
	//bool isSorted = false;
	if (StartIndex < EndIndex)
	{
		uint32 MidIndex = (StartIndex + EndIndex) / 2U;       //to get mid index when it's on left side or right side
		MergeSort(DataArray, StartIndex, MidIndex);
		MergeSort(DataArray, MidIndex + 1U, EndIndex);
		Merge(DataArray, StartIndex, MidIndex, EndIndex);
	}

 /*//debugging display

	if (isSorted)
	{
		for (uint32 i = 0U; i < DataArray.size(); i++)
		{
			std::cout << DataArray[i] << "   ";
		}
	}

*/
}

void clsSortingAlgorithms::Merge(std::vector<int32> DataArray, uint32 StartIndex,uint32 MidIndex, uint32 EndIndex)
{
	uint32 LeftIndex = StartIndex;
	//uint32 RightIndex = (MidIndex == LeftIndex) ? (MidIndex) : (MidIndex + 1U) ;
	uint32 RightIndex =  (MidIndex + 1U);
	uint32 TempIndex = 0U;
	std::vector <int32> TempArray;


	while (LeftIndex <= MidIndex && RightIndex <= EndIndex)
	{
		if (DataArray[LeftIndex] <= DataArray[RightIndex])
		{
			TempArray.push_back( DataArray[LeftIndex]);
			LeftIndex++;
		}
		else
		{
			TempArray.push_back(DataArray[RightIndex]);
			RightIndex++;
		}
	}

	while (LeftIndex <= MidIndex)
	{
		TempArray.push_back(DataArray[LeftIndex]);
		LeftIndex++;
	}

	while (RightIndex <= EndIndex)
	{
		TempArray.push_back(DataArray[RightIndex]);
		RightIndex++;
	}

	for (uint32 i = StartIndex; i <= EndIndex; i++)
	{
		DataArray[i] = TempArray[TempIndex];
		TempIndex++;
	}
}