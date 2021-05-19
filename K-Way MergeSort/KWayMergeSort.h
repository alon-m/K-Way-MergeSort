#pragma once
#include "QuickSort.h"

class KWayMergeSort
{
private:

	static int** splitArrToKArrays(int* i_IntArray, int i_Size, int i_KValue, int* o_AmountOfArrays)
	{
		int remainingElements = i_Size;
		int** result = new int*[i_KValue];

		for (int i = 0; i < i_KValue; i++)
		{
			int size = remainingElements / i_KValue;
			result[i] = new int[size];

			remainingElements -= i_KValue;
		}


		return result;
	}

	static int* mergeArrays(int** i_Arrays, int i_AmountOfArrays, int i_AmountOfItems)
	{
		int* result = new int[i_AmountOfItems];



		return result;
	}

public:

	static int* Sort(int* i_IntArray, int i_Size, int i_KValue)
	{
		if (i_Size < i_KValue)
		{
			QuickSort<int>::Sort(i_IntArray, 0, i_Size - 1);
		}
		else
		{
			int amountOfArrays;
			int** kArrays = splitArrToKArrays(i_IntArray, i_Size, i_KValue, &amountOfArrays);

			for (int i = 0; i < amountOfArrays; i++)
			{
				int sizeOfArray = sizeof(kArrays[i]) / sizeof(int);
				Sort(kArrays[i], sizeOfArray, i_KValue);
			}

			i_IntArray = mergeArrays(kArrays, amountOfArrays, i_Size);
		}

		return i_IntArray;
	}

};

