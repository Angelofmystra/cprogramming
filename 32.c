#include <stdio.h>
int main()
{
    int a = 1, b = 1, c = 1;
    a += b += c;

    printf("%d", a < b ? a++ : b++);
    printf("%d", c += a < b ? a++ : b++);
    printf("%d", (c <= b <= a) ? c : a);

    printf("\n");
    return 0;
}
