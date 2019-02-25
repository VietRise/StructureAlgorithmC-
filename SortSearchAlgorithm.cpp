#include "SortSearchAlgorithm.h"
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void SortSearchAlgorithm::bubbleSort(int* array, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void SortSearchAlgorithm::selectionSort(int* array, int size)
{
    int minIndex;
    for(int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < size; j++)
        {
            if(array[minIndex] > array[j])
            {
                minIndex = j;
            }
        }
        swap(array[minIndex], array[i]);
    }
}

void SortSearchAlgorithm::mergeSort(int* array, int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;
        mergeSort(array, l, m);
        mergeSort(array, m+1, r);
        merge(array, l, m, r);
    }
}

void SortSearchAlgorithm::merge(int* array, int l, int m, int r)
{
    int i = 0, j = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
    {
        L[i] = array[l + i];
    }
    for(i = 0; i < n2; i++)
    {
        R[i] = array[m + 1 + i];
    }

    i = 0;
    j = 0;
    int k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        array[k++] = L[i++];
    }

    while(j < n2)
    {
        array[k++] = R[j++];
    }
}

void SortSearchAlgorithm::quickSort(int* array, int l, int r)
{
    if(l < r)
    {
        int pi = SortSearchAlgorithm::partition(array, l, r);
        quickSort(array, l, pi - 1);
        quickSort(array, pi + 1, r);
    }
}

int SortSearchAlgorithm::partition(int* array, int l, int r)
{
    int pivot = array[r];
    int i = l - 1;
    for(int j = l; j < r; j++)
    {
        if(array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1], array[r]);
    return i + 1;
}

void SortSearchAlgorithm::bucketSort(float* array, int size)
{
    // Create empty bucket
    vector<float> b[size];

    // Put all element of array into bucket
    for(int i = 0; i < size; i++)
    {
        int bi = size * array[i];
        b[bi].push_back(array[i]);
    }

    // Sort indiviual buckets
    for(int i = 0; i < size; i++)
    {
        sort(b[i].begin(), b[i].end());
    }

    // Concatenate all buckets into array
    int index = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < b[i].size(); j++)
        {
            array[index++] = b[i][j];
        }
    }
}