/*
        * 
      * * 
    * * * 
  * * * * 
* * * * * 
  * * * * 
    * * * 
      * * 
        * 
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int trougao_size = 5;

    for (int row = 0; row < trougao_size; row++)
    {
        for(int space = 0; space < trougao_size - row - 1; space++) {
            printf("  ");
        }
        for (int col = 0; col <= row; col++)
        {
            printf("* ");
        }
        // New line
        printf("\n");
    }
    trougao_size--;

    for(int row = 0; row < trougao_size; row++) {
        for(int space = 0; space <= row; space++) {
            printf("  ");
        }
        for(int col = 0; col < trougao_size - row; col++) 
        {
            printf("* ");
        }
        // New line
        printf("\n");
    }
    return 0;
}