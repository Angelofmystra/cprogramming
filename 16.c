#include <stdio.h>
#include <stdlib.h>
int choose_pivot(int A[], int left, int right)
{
    return left; // weak basic implementation
}
int swap(int A[], int a, int b)
{
    int temp = A[a];
    array[a] = array[b];
    array[b] = temp;
    return 0;
}

int partition(int A[], int left, int right)
{
    int pivot_index = choose_pivot(A, left, right);
    int pivot_value = array[pivot_index];
    swap(A, pivot_index, right);
    int store_index = left;
    for(int i=left; i <= right; i++)
    {
        if(array[i] <= pivot_value)
        {
            swap(A, i, store_index);
            store_index = store_index + 1;
        }
    }
    swap(A, store_index, right); // move pivot to its final place
    return store_index; 
}

/*
 *    A[] is the array to be sorted. i is the starting value, usually 1. k is the length of the array to be sorted.
 */
int quicksort(int A[], i, k)
{
    if(i < k)
    {
        int p = partition(A, i, k);
        quicksort(A, i, p-1);
        quicksort(A, p+1, k);
    }
}

int main()
{
    int size = 20;
    int array[size];
    // assign stuff to the array
    quicksort(array, 0, size-1);
    // print array to see if sorted
    return 0;
}

