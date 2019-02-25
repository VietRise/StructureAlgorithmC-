#ifndef __SORT_SEARCH_ALGORITHM_H__
#define __SORT_SEARCH_ALGORITHM_H__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void swap(int& x, int &y);

class SortSearchAlgorithm
{
    public:
        static void bubbleSort(int* array, int size);
        static void selectionSort(int* array, int size);
        static void mergeSort(int* array, int l, int r);
        static void quickSort(int* array, int l, int r);
        static void bucketSort(float* array, int size);

    private:
        static void merge(int* array, int l, int m, int r);
        static int partition(int* array, int l, int r);
};

#endif