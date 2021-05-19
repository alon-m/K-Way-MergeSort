#pragma once

template<class T> class QuickSort
{
private:

    static void swap(T* a, T* b)
    {
        T t = *a;
        *a = *b;
        *b = t;
    }
    
    static int partition(T arr[], int low, int high)
    {
        T pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[high]);

        return (i + 1);
    }

public:

    static void Sort(T arr[], int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partition(arr, low, high);
            
            Sort(arr, low, pivotIndex - 1);
            Sort(arr, pivotIndex + 1, high);
        }
    }
};


