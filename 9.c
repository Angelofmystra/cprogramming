#include <stdio.h>
#include <stdlib.h>
int main() // it must have the return value int, as it is returned as a status to the OS
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int *A = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
    {
        A[i] = i+1;
    }
    int *B = (int*)realloc(A, 2*n*sizeof(int));
    printf("Prev block address = %p, new address = %p\n", A,B);

    for(int i = 0; i < 2*n; i++)
    {
        printf("%d\n", B[i]);
    }
    // Even if the memory is freed, you can still read it if we know the address.
    // It depends on the compiler and the machine. It seems fine with gcc on a macosx.
    // In some it may cause the program to crash
}
