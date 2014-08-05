#include <stdio.h>
int main(int argc, char **argv)
{
    int status = 0;
    if(argc < 2){
        printf("No arguments given.\n");
        status = -1;
    } else {
        // do something
    }
    return status;
}
