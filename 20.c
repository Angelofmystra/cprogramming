/*  
    Insertion Sort
    Copyright (C) 2014  Bertrand Brompton 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/><stdio.h>
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* The official name of this program (e.g., no `g' prefix). */
#define PROGRAM_NAME "insertion_sort"

#define AUTHORS \
    proper_name ("Bertrand Brompton")

static void 
swap(int A[], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}
/* Algorithm for insertion sort where arrays are zero-based */
static void
insertion_sort(int A[], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        j = i;
        while((j>0) && (A[j-1] > A[j]))
        {
            swap(A, j, j-1);
            j = j-1;
        }
    }
}

int 
main(int argc, char **argv)
{
    int size = 20;
    int array[size];
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0; i < size; i++){
        array[i] = rand() % 50;
    }
    insertion_sort(array, size);
    for(int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }
    return 0;
}
