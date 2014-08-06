#include <stdio.h>

/* The official name of this program (e.g., no `g' prefix). */
#define PROGRAM_NAME "helloworld"

#define AUTHORS \
    proper_name ("Bertrand Brompton")

int
hello_world()
{
    printf("Hello world\n");
    return 0;
}
int 
main(int argc, char **argv)
{
    hello_world();
    return 0;
}
