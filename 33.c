#include <stdio.h>
int main()
{
    int a = 1, b = 2, c = 3;
    /*
     * a = 0000...001
     * b = 0000...010
     * c = 0000...011
     * b & c = 0000...010
     * a | b = 0000...011
     * ~a = 1111...10
     * b & a~ 0000...010
     * c ^ b = 0000...001 // XOR
     * b | ~b = 0000...010 | 1111...101 = 11111111 = -1
     * a ^ a = 0 (all numbers XOR with itself is 0)
     */
    printf("%d", a | (b & c)); // added bracket to avoid warning
    printf("%d", c ^ b & ~a);
    printf("%d", b | ~b);
    printf("%d", a ^ a);

    printf("\n");
    return 0;
}
