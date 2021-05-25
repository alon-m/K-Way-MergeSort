#pragma once

class QuickSort
{
public:

    static void Sort(int* i_Arr, int i_Low, int i_High);

private:

    static void swap(int* i_A, int* i_B);

    static int partition(int i_Arr[], int i_Low, int i_High);

};


