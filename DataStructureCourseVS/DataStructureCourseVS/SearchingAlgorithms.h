#pragma once

#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include <math.h>
#include <vector>


class clsSearchingAlgorithms
{
public:

	int32 LinearSearch(std::vector<int32>DataArray, int32 element);
	int32 BinarySearch(std::vector<int32>SortedDataArray, int32 element);

protected:

private:


};