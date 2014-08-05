#include <stdio.h> // Preprocessor directive that tells the compiler to put code from the header called stdio.h in our program before actually creating the executable.
// By including header files, you gain access to many different functions -- both printf and getchar functions are included in stdio.h
// The next important line is int main(). This tells the compiler that there is a function called main, and that the function returns an integer, hence in. \n is treat as a single character. 
// getchar() makes the program wait for the user to enter a single character. most programs will open a new window, run, then close the window before you can see the output. 
// A return value of 0 means success

int main()
{
    printf("Hello world!.\n");
    getchar();
    return 0;
}
