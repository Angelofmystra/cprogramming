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
/*
 * It requires as a parameter a function that takes an int and returns an int.
 */
/*void forLoop2(int A[], int n, int (*func)(int x))
{
    for(int i = 0; i < n; i++)
        A[i] = func(x);
}*/

void forLoop3(int A[], int n, int (*func)(), int param)
{
    for(int i = 0; i < n; i++)
        A[i] = func(param);
}

void forLoop5(void *datastructure, int (*func)(const int *), const int *x)
{
    while(*datastructure->next != NULL)
        *datastructure = func(x);
        *datastructure
}    
/*void forLoop4(int A[], int n, int (*func)(), ...)
{
    va_list args;
    va_start(args, A[], n, func);
    for(int i = 0; i < n; i++)
        
    va_end(args);

    //
}*/

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
//    forLoop2(array, size, multiply(size));
    forLoop3(array, size, multiply, 3);
    GenericForLoop((int)array, size, multiply);
    GenericDatastructureForLoop(array, size, multiply); // yes function should work on arrays
    // create datastructure
    // GenericDatastructureForLoop(&datastructure, size, multiply);
    return 0;
}

