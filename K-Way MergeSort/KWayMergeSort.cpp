#include "KWayMergeSort.h"
#include <iostream>
using namespace std;


int* KWayMergeSort::Sort(int* i_IntArray, int i_Size, int i_KValue)
{
	int* resultArr = new int[i_Size];

	if (i_Size <= i_KValue)
	{
		QuickSort::QSort(i_IntArray, 0, i_Size - 1);
		return i_IntArray;
	}
	else
	{
 		int* sizesArr =CreateSizesArr(i_Size, i_KValue);
		int** kArrays = SplitArrToKArrays(i_IntArray, i_Size, i_KValue, sizesArr);
		for (int i = 0; i < i_KValue; i++)
		{
			kArrays[i]=Sort(kArrays[i], sizesArr[i], i_KValue);
		}
		return MergeArrays(kArrays, i_Size, i_KValue,sizesArr);
	}
	return resultArr;
}



int* KWayMergeSort::CreateSizesArr(int i_BigArrSize, int i_KValue)
{
	int NumOfSubArrays = i_KValue;
	int NumOfElements = i_BigArrSize;
	int* SizesArr = new int[i_KValue];
	for (int i = 0; i < i_KValue; i++)
	{
		SizesArr[i] = NumOfElements / NumOfSubArrays;
		NumOfElements -= SizesArr[i];
		NumOfSubArrays--;
	}
	return SizesArr;
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

int* KWayMergeSort::MergeArrays(int** kArrays,int i_Size,int i_KValue,int *sizesArr)
{
	for (int o = 0; o < i_KValue; o++)
	{
		cout <<endl<< "ARR " << o << " :";
		for (int w = 0; w < sizesArr[o]; w++)
		{
			cout << kArrays[o][w] << " ";
		}
	}


	MinHeap Heap = MinHeap(i_KValue);
	for(int KIndex=0;KIndex<i_KValue;KIndex++)
		Heap.Insert(kArrays[KIndex][0], kArrays[KIndex], 0, sizesArr[KIndex]-1);

	

	int resultIndex = 0;
	int* result = new int[i_Size];

	while (resultIndex < i_Size)
	{
		result[resultIndex] = Heap.DeleteMin();
		resultIndex++;
	}

	return result;
}
