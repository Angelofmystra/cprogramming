#include <stdio.h>
int multiply(int x){
    return x*x;
}

/*
 * Apply the function to each element in the array. Make sure the types line up. Requires an int array and int function. 
 */
void forLoop(int A[], int n, int (*func)())
{
    for(int i = 0; i < n; i++)
        A[i] = func(i);        
}

void forLoop2(int A[], int n, int (*func)(int))
{
    for(int i = 0; i < n; i++)
        A[i] = func();
}

void forLoop3(int A[], int n, int (*func)(), int param)
{
    for(int i = 0; i < n; i++)
        A[i] = func(param);
}
/*
 * Apply the function to each element in the array. Make sure the types line up.
 */
void GenericForLoop(void A[], int n, void (*func)())
{
    for(int i = 0; i < n; i++)
        A[i] = func(i);  
}

void GenericDatastructureForLoop(void *A, int n, void (*func)())
{
    for(int i = 0; i < n; i++)
        A[i] = func(i); 
}

int main()
{
    int size = 10;
    int array[size];
    forLoop(array, size, multiply);
    forLoop2(array, size, multiply(size));
    forLoop3(array, size, multiply, 3);
    GenericForLoop(array, size, multiply);
    GenericDatastructureForLoop(array, size, multiply); // yes function should work on arrays
    // create datastructure
    // GenericDatastructureForLoop(&datastructure, size, multiply);
    return 0;
}

