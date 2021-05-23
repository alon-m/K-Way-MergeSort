#include "KWayMergeSort.h"



int* KWayMergeSort::Sort(int* i_IntArray, int i_Size, int i_KValue)
{
	int* resultArr;
	MinHeap Heap = MinHeap(i_KValue);

	if (i_Size < i_KValue)
	{
		QuickSort::QSort(i_IntArray, 0, i_Size - 1);
		resultArr = i_IntArray;
	}
	else
	{
		int* sizesArr = new int[i_KValue];
		int** kArrays = SplitArrToKArrays(i_IntArray, i_Size, i_KValue, sizesArr);

		for (int i = 0; i < i_KValue; i++)
		{
			Sort(kArrays[i], sizesArr[i], i_KValue);
			Heap.Insert(kArrays[i][0], kArrays[i], i, sizesArr[i]);
		}

		//resultArr = MergeArrays(kArrays, i_KValue, i_Size,Heap);
		resultArr = MergeArrays(Heap, i_Size);
	}

	return resultArr;
}

int KWayMergeSort::SetSubArraySize(int i_BigArrSize, int i_KValue, int i_RemainingElements)

{
	int subArraySize = i_BigArrSize / i_KValue;

	if (i_RemainingElements < (i_KValue * 2) && i_RemainingElements > i_KValue)
	{
		subArraySize = i_RemainingElements;
	}

	return subArraySize;
}


int** KWayMergeSort::SplitArrToKArrays(int* i_IntArray, int i_Size, int i_KValue, int* i_SizesArr)
{
	int remainingElements = i_Size, inputArrIndex = 0;
	int** result = new int* [i_KValue];
	
	for (int i = 0; i < i_KValue; i++)
	{
		i_SizesArr[i] = SetSubArraySize(i_Size, i_KValue, remainingElements);
		result[i] = new int[i_SizesArr[i]];
		
		for (int j = 0; j < i_SizesArr[i]; j++)
		{
			result[i][j] = i_IntArray[inputArrIndex];
			inputArrIndex++;
		}
		
		remainingElements -= i_SizesArr[i];
	}

	return result;
}

int* KWayMergeSort::MergeArrays(MinHeap i_MinHeap,int i_Size)
{
	int resultIndex = 0;
	int* result = new int[i_Size];

	while (resultIndex < i_Size)
	{
		result[resultIndex] = i_MinHeap.DeleteMin();
		resultIndex++;
	}

	return result;
}
