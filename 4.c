#include <stdio.h>
int main()
{
    int age;
    printf("Please give an age!");
    scanf("%d", &age);
    if(age < 100){
        printf("You are pretty young!\n");
    }
    else if (age == 100){
        printf ("You are old!\n");
    }
    else{
        printf("You must be a vampire!\n");
    }
    return 0;
}


