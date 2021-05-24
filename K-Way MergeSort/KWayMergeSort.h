#pragma once
#include "QuickSort.h"
#include "MinHeap.h"

class KWayMergeSort
{
public:

	static int* Sort(int* i_IntArray, int i_Size, int i_KValue);
	
	static int** SplitArrToKArrays(int* i_IntArray, int i_Size, int i_KValue, int* i_SizesArr);
	
	static int* MergeArrays(int** kArrays, int i_Size, int i_KValue,int* sizesArr);
	
	static int* CreateSizesArr(int i_BigArrSize,int i_KValue);

};

