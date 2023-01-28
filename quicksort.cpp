// Jonathan Stock
// COEN 179
// Implementation of the Quick Sort Algorithm from GeeksforGeeks.
// https://www.geeksforgeeks.org/cpp-program-for-quicksort/

#include <iostream>
using namespace std;

int partition(int arr[], string str[], int const start, int const end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    swap(str[pivotIndex], str[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
            swap(str[i++], str[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], string str[], int const start, int const end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, str, start, end);

    // Sorting the left part
    quickSort(arr, str, start, p - 1);

    // Sorting the right part
    quickSort(arr, str, p + 1, end);
}