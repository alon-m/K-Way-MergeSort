#pragma once
#include "QuickSort.h"

class KWayMergeSort
{
public:

	static int* Sort(int* i_IntArray, int i_Size, int i_KValue);
	
	static int SetSubArraySize(int i_BigArrSize, int i_KValue, int i_RemainingElements)
	{
		int subArraySize = i_BigArrSize / i_KValue;

		if (i_RemainingElements < (i_KValue * 2) )
		{
			subArraySize = i_RemainingElements;
		}

		return subArraySize;
	}

	static int** SplitArrToKArrays(int* i_IntArray, int i_Size, int i_KValue);
	
	static int* MergeArrays(int** i_Arrays, int i_AmountOfArrays, int i_AmountOfItems);
	
};

