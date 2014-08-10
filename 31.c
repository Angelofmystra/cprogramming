#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Converts x into a positive number */
int positive(int x)
{
    return abs(x);
}

/* Converts x to a negative number */
int negative(int x)
{
    return -x;
}

/* Multiply the number with itself */
int product(const int x)
{
    return x*x;
}

int multiply(const int x, const int y)
{
    return x*y;
}

/* maps a function with a parameter to an array */ 
void map(int A[], int n, int (*func)(), int param)
{
    for(int i = 0; i < n; i++)
        A[i] = func(A[i], param);
}

/* maps a function to an array */
void map2(int A[], int n, int (*func)())
{
    for(int i = 0; i < n; i++)
        A[i] = func(A[i]);
}

/* assigns to each element of an array a function that does not depend on the existing value in the array */
void assign(int A[], int n, int (*func)(), int param)
{
    for(int i = 0; i < n; i++)
        A[i] = func(param);
}

void print(int A[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d\n", A[i]);
}

int * generate(int size, int range)
{
    int *array = (int *)malloc(size * sizeof(int));
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0 ; i < size ; i++ )
        array[i] = rand() % range;
    return array;
}

int odd(int x)
{
    if(x % 2)
        return 1; // x is odd
    else
        return 0;
}

int even(int x)
{
    return !odd(x);
    /*if(!(x % 2))
        return 1; // x is even
    else
        return 0;*/
}

void filter(int A[], int n, int (*func)(), int *param)
{
    for(int i = 0; i < n; i++)
        if(!func(param)){
            int j = i;
            for ( j = j - 1 ; j < n - 1 ; j++ )
                A[j] = A[j+1];
        }
}

void filter2(int A[], int n, int (*func)())
{
    for(int i = 0; i < n; i++)
        if(!func(A[i])){
            int j = i;
            for ( j = j - 1 ; j < n - 1 ; j++ )
                A[j] = A[j+1];
        }
}

int main()
{
    int size = 10, range = 50;
    int *arr;
    arr = generate(size,range);
    print(arr, size);
    //map2(arr, size, positive);
    map2(arr, size, negative);
    print(arr, size);
    filter2(arr, size, odd);
    print(arr, size);
    map2(arr, size, product);
    print(arr, size);
    map(arr, size, multiply, 2);
    print(arr, size);
    free(arr);
}
