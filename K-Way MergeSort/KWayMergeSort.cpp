#include "KWayMergeSort.h"


int* KWayMergeSort::Sort(int* i_IntArray, int i_Size, int i_KValue)
{
	int* resultArr;
	int size = ceil(i_Size / i_KValue);
	MinHeap Heap(size);
	if (i_Size < i_KValue)
	{
		QuickSort::QSort(i_IntArray, 0, i_Size - 1);
		resultArr = i_IntArray;
	}
	else
	{
		int** kArrays = SplitArrToKArrays(i_IntArray, i_Size, i_KValue);

		for (int i = 0; i < i_KValue; i++)
		{
			int sizeOfArray = (sizeof(kArrays[i]) / sizeof(int));
			Sort(kArrays[i], sizeOfArray, i_KValue);
			Heap.Insert(kArrays[i][0], kArrays[i], i, sizeOfArray);
		}

		//resultArr = MergeArrays(kArrays, i_KValue, i_Size,Heap);
		resultArr = MergeArrays(Heap, i_Size);
	}

	return resultArr;
}


int** KWayMergeSort::SplitArrToKArrays(int* i_IntArray, int i_Size, int i_KValue)
{
	int remainingElements = i_Size, inputArrIndex = 0;
	int** result = new int* [i_KValue];
	
	for (int i = 0; i < i_KValue; i++)
	{
		int subArraySize = SetSubArraySize(i_Size, i_KValue, remainingElements);
		result[i] = new int[subArraySize];
		
		for (int j = 0; j < subArraySize; j++)
		{
			result[i][j] = i_IntArray[inputArrIndex];
			inputArrIndex++;
		}
		
		remainingElements -= subArraySize;
	}

	return result;
}

int* KWayMergeSort::MergeArrays(MinHeap i_MinHeap,int i_Size)
{
	int ResultIndex = 0;
	int* result = new int[i_Size];
	while (ResultIndex != i_Size)
	{
		result[ResultIndex] = i_MinHeap.DeleteMin();
	}
	return result;


	/*int* result = new int[i_AmountOfItems];

	for (int i = 0; i < i_AmountOfArrays; i++)
	{
		int currentArrSize = (sizeof(i_Arrays[i]) / sizeof(int));
	}

	return result;*/
}
