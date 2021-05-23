#pragma once
#include "QuickSort.h"
#include "MinHeap.h"

class KWayMergeSort
{
public:

	static int* Sort(int* i_IntArray, int i_Size, int i_KValue);
	
	static int SetSubArraySize(int i_BigArrSize, int i_KValue, int i_RemainingElements);

	static int** SplitArrToKArrays(int* i_IntArray, int i_Size, int i_KValue, int* i_SizesArr);
	
	static int* MergeArrays(MinHeap i_MinHeap, int i_Size);
	
};

