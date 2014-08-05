#include <stdio.h>
int main()
{
    // malloc
    // calloc
    // realloc
    // free
   int a; // goes on the stack-frame of the method main()
   int *p;
   p = (int*)malloc(sizeof(int));
   // give me a block of memory which is 4 bytes - the typical size of an intenger - and return a pointer to the starting address of this block - in this particular case, a void pointer. Let us say the starting address of this lbock is 200, then malloc return 200.
   // It is type casted since it returns a void pointer
   // The only way to use memory on the heap is through reference.
   *p = 10;
   free(p);
   p = (int*)malloc(sizeof(int));
   *p = 20;
   // the old p is still holding up memory, so it needs to be cleared as it is an unncessary consumption of memory
   // Anything on the heap is not automatically allocated.
   // It does not live for the entire lifetime of the application. A global variable does.
   //
   free(p);
   p = (int*)malloc(20*sizeof(int));
   // one large contiguous block of memory for ints will be allocated.
   // it can then be referenced as p[0], p[1], p[2], till p[19]
   return 0;
}
