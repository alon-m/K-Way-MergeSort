#include "QuickSort.h"

void QuickSort::QSort(int* i_Arr, int i_Low, int i_High)
{
    if (i_Low < i_High)
    {
        int pivotIndex = Partition(i_Arr, i_Low, i_High);

        QuickSort::QSort(i_Arr, i_Low, pivotIndex - 1);
        QuickSort::QSort(i_Arr, pivotIndex + 1, i_High);

    }
}

void QuickSort::Swap(int* i_A, int* i_B)
{
    auto t = *i_A;
    *i_A = *i_B;
    *i_B = t;
}

int QuickSort::Partition(int i_Arr[], int i_Low, int i_High)
{
    int pivot = i_Arr[i_High];
    int i = (i_Low - 1);

    for (int j = i_Low; j <= i_High - 1; j++)
    {
        if (i_Arr[j] <= pivot)
        {
            i++;
            QuickSort::Swap(&i_Arr[i], &i_Arr[j]);
        }
    }

    QuickSort::Swap(&i_Arr[i + 1], &i_Arr[i_High]);

    return (i + 1);
}


