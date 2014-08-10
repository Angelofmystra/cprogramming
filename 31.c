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

/* maps a function with a parameter to an array */ 
void map(int A[], int n, int (*func)(), int param)
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
{
    int *array = (int *)malloc(size * sizeof(int));
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0 ; i < size ; i++ )
        array[i] = rand() % range;
    return array;
}

int main()
{
    int size = 10, range = 50;
    int *p;
    p = generate(size,range);
    print(p, size);
    map(p, size, product, 3);
    print(p, size);
    map2(p, size, positive);
    map2(p, size, negative);
    print(p, size);
    free(p);
}
