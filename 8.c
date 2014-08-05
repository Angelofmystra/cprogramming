#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int *A = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
    {
        A[i] = i+1;
    }
    free(A);
    // A = NULL; // After free, adjust pointer to NULL. It is a macro for address 0, and cannot be dreferenced. This statement will now cause the program to crash.
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    // Even if the memory is freed, you can still read it if we know the address.
    // It depends on the compiler and the machine. It seems fine with gcc on a macosx.
    // In some it may cause the program to crash
    return 0;
}
