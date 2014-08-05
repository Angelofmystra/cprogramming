#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node *next;
};

int main()
{
   struct node *root;
   struct node *curr;
   root = NULL;
   for(int i = 1;i<=10;i++) {
        curr = (struct node *)malloc(sizeof(struct node));
        curr->x = i;
        curr->next = root;
        root = curr;
   }
   curr = root;
   while(curr)
   {
       printf("%d\n", curr->x);
       curr = curr->next;
   }

   return 0;
}
