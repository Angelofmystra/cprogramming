#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* default_world_filename = "default-world.csv";
char* default_world_open_mode = "r";
int line_size_of_csv_file = 1024;

/*
 * Helper functions
 */

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

/*
 * Main Functions
 */

int initialise_array(int size, int A[size][size])
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            A[i][j] = 0;
    return 0;
}

int print_array(int size, int A[size][size])
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            printf("%d", A[i][j]);
        printf("\n");
    }
    return 0;
}

int read_csv_to_array()
{
    FILE* stream = fopen(default_world_filename, default_world_open_mode);
    char line[line_size_of_csv_file];
    while(fgets(line, line_size_of_csv_file, stream))
    {
        char* tmp = strdup(line);
        // Dont parse commented lines
        if(*getfield(tmp, 1) != '#'){
            printf("Field 3 would be %s\n", getfield(tmp, 3));
        }
        free(tmp);
    }
    return 0;
}

/*
 * Main Loop wrapper
 */
int main()
{
    int size = 100;
    int intArray[size][size];
    initialise_array(size, intArray);
    print_array(size, intArray);
    read_csv_to_array();

}
