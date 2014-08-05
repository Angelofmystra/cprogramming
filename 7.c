#include <stdio.h>
int main()
{
    // size_t means it stores only stores positive integer values
    p = (int*)malloc(10*sizeof(int)); // returns the size of the data type in bytes
    print(p); // integer is a primitive data type
    free(p);
    return 0;
    // *p = 2 is wrong. you cant dereference a void pointer
    int *p = (int*)malloc(3*sizeof(int));
    p[0] = 2;
    p[1] = 4;
    p[2] = 6;
    // calloc returns a void pointer. It takes two elements, not 1.
    // malloc returns 3*sizeof(int)o
     
    int *c = (int*) calloc(3, sizeof(int)); // initialises everything to 0
    int *p = (int*) malloc(3*sizeof(int)); // everything in the p is garbage
    int *r = (int*) realloc(
{
