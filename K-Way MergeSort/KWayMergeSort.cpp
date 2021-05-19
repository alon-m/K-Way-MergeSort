#include "KWayMergeSort.h"

int* KWayMergeSort::Sort(int* i_IntArray, int i_Size, int i_KValue)
{
	if (i_Size < i_KValue)
	{
		QuickSort::Sort(i_IntArray, 0, i_Size - 1);
	}
	else
	{
		int** kArrays = SplitArrToKArrays(i_IntArray, i_Size, i_KValue);

		for (int i = 0; i < i_KValue; i++)
		{
			int sizeOfArray = sizeof(kArrays[i]) / sizeof(int);
			Sort(kArrays[i], sizeOfArray, i_KValue);
		}

		i_IntArray = MergeArrays(kArrays, i_KValue, i_Size);
	}

	return i_IntArray;
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

int* KWayMergeSort::MergeArrays(int** i_Arrays, int i_AmountOfArrays, int i_AmountOfItems)
{
	int* result = new int[i_AmountOfItems];

	for (int i = 0; i < i_AmountOfArrays; i++)
	{
		int currentArrSize = sizeof(i_Arrays[i]) / sizeof(int);
	}


	return result;
}
