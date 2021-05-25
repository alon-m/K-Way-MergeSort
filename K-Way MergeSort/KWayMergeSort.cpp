#include "KWayMergeSort.h"
#include <iostream>
using namespace std;

int* KWayMergeSort::Sort(int* i_IntArray, int i_Size, int i_KValue)
{
	int* resultArr = nullptr;

	if (i_Size <= i_KValue)
	{
		QuickSort::Sort(i_IntArray, 0, i_Size - 1);
		resultArr = i_IntArray;
	}
	else
	{
 		int* sizesArr = CreateSizesArr(i_Size, i_KValue);
		int** kArrays = SplitArrToKArrays(i_IntArray, i_Size, i_KValue, sizesArr);

		for (int i = 0; i < i_KValue; i++)
		{
			kArrays[i] = Sort(kArrays[i], sizesArr[i], i_KValue);
		}

		resultArr = MergeArrays(kArrays, i_Size, i_KValue, sizesArr);

		for (int i = 0; i < i_KValue; i++)
		{
			delete[] kArrays[i];
		}

		delete[] kArrays;
		delete[] sizesArr;
	}


	return resultArr;
}



int* KWayMergeSort::CreateSizesArr(int i_ArrSize, int i_KValue)
{
	int numOfSubArrays = i_KValue;
	int numOfElements = i_ArrSize;
	int* sizesArr = new int[i_KValue];

	for (int i = 0; i < i_KValue; i++)
	{
		sizesArr[i] = numOfElements / numOfSubArrays;
		numOfElements -= sizesArr[i];
		numOfSubArrays--;
	}

	return sizesArr;
}

int** KWayMergeSort::SplitArrToKArrays(int* i_IntArray, int i_Size, int i_KValue, int* i_SizesArr)
{
	int inputArrIndex = 0;
	int** result = new int* [i_KValue];

	for (int i = 0; i < i_KValue ; i++)
	{	
		result[i] = new int[i_SizesArr[i]];

		for (int j = 0; j < i_SizesArr[i]; j++)
		{
			result[i][j] = i_IntArray[inputArrIndex];
			inputArrIndex++;
		}
	}

	return result;
}

int* KWayMergeSort::MergeArrays(int** i_KArrays, int i_Size, int i_KValue, int *i_SizesArr)
{
	MinHeap heap = MinHeap(i_KValue);
	int* resultArr = new int[i_Size];

	for (int i = 0; i < i_KValue; i++)
	{
		heap.Insert(i_KArrays[i][0], i_KArrays[i], 0, i_SizesArr[i] - 1);
	}
	
	HeapToResultArr(resultArr, i_Size, heap);

	return resultArr;
}

void KWayMergeSort::HeapToResultArr(int* i_ResultArr, int i_ArrSize, MinHeap& i_Heap)
{
	for (int i = 0; i < i_ArrSize; i++)
	{
		i_ResultArr[i] = i_Heap.DeleteMin();
	}
}
