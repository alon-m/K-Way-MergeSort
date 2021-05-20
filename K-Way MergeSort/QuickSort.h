#pragma once

class QuickSort
{
public:

    static void Swap(int* i_A, int* i_B);

    static int Partition(int i_Arr[], int i_Low, int i_High);
	
    static void QSort(int* i_Arr, int i_Low, int i_High);
};


