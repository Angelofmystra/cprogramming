#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * This .c file needs work. Check the comments. Also, it is untested. The algorithm is legit, however. :)
 *
 */
int choose_pivot(int A[], int left, int right)
{
    return left + (right-left)/2; // weak basic implementation
}
int swap(int A[], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
    return 0;
}

int partition(int A[], int left, int right)
{
    int pivot_index = choose_pivot(A, left, right);
    int pivot_value = A[pivot_index];
    swap(A, pivot_index, right);
    int store_index = left;
    for(int i=left; i <= right; i++)
    {
        if(A[i] <= pivot_value)
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
int quicksort(int A[], int i, int k)
{
    if(i < k)
    {
        int p = partition(A, i, k);
        quicksort(A, i, p-1);
        quicksort(A, p+1, k);
    }
    return 0;
}

int print_array(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {   
        printf("%d\n", A[i]);
    }
    printf("\n\n");
    return 0;
}

int main()
{
    int size = 20;
    int array[size];
    
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
    }
    
    print_array(array, size);   // print before
    quicksort(array, 0, size-1);
    print_array(array, size);   // print after
    
    return 0;
}

