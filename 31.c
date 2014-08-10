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
int multiply(int x)
{
    return x*x;
}

/* maps a function with a parameter to an array */ 
void map(int A[], int n, int (*func)(const int *), int *param)
{
    for(int i = 0; i < n; i++)
        A[i] = func(param);
}

/* maps a function to an array */
void map2(int A[], int n, int (*func)())
{
    for(int i = 0; i < n; i++)
        A[i] = func(A[i]);
}

void print(int A[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d\n", A[i]);
}

int * generate(int size, int range)
    int array[size];
    time_t t;
    srand((unsigned) time(&t));
    for( i = 0 ; i < n ; i++ )
        array[i] = rand % range;
    return array;
}

int main()
{
    int size = 10, range = 50;
    int *array;
    array = generate(size,range);
    map(array, size, multiply, 3);
    map2(array, size, positive);
    map2(array, size, negative);
}
