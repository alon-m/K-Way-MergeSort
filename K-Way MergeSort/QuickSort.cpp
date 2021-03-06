#include "QuickSort.h"

void QuickSort::Sort(int* i_Arr, int i_Low, int i_High)
{
    if (i_Low < i_High)
    {
        int pivotIndex = partition(i_Arr, i_Low, i_High);

        QuickSort::Sort(i_Arr, i_Low, pivotIndex - 1);
        QuickSort::Sort(i_Arr, pivotIndex + 1, i_High);

    }
}

void QuickSort::swap(int* i_A, int* i_B)
{
    auto t = *i_A;
    *i_A = *i_B;
    *i_B = t;
}

int QuickSort::partition(int i_Arr[], int i_Low, int i_High)
{
    int pivot = i_Arr[i_High];
    int i = (i_Low - 1);

    for (int j = i_Low; j <= i_High - 1; j++)
    {
        if (i_Arr[j] <= pivot)
        {
            i++;
            QuickSort::swap(&i_Arr[i], &i_Arr[j]);
        }
    }

    QuickSort::swap(&i_Arr[i + 1], &i_Arr[i_High]);

    return (i + 1);
}


