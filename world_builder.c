#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Helper functions
 */

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
    int size = 100;
    int intArray[size][size];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            intArray[i][j] = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            printf("%d", intArray[i][j]);
        printf("\n");
    }
    FILE* stream = fopen("default-world.csv", "r");
    int line_size = 1024;
    char line[line_size];
    while(fgets(line, line_size, stream))
    {
        char* tmp = strdup(line);
        // Dont parse commented lines
        if(*getfield(tmp, 1) != '#'){
            printf("Field 3 would be %s\n", getfield(tmp, 3));
        }
        free(tmp);
    }
}
