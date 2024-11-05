/*
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int trougao_size = 5;
    for(int row = 0; row  < trougao_size; row++) {
        // Spaces
        for(int space = 0; space < trougao_size - 1 - row; space++) {
            printf(" ");
        }
        // Left sire
        for(int col = 0; col <= row - 1; col++) {
            printf("*");
        }
        // Center
        printf("*");
        // Right side
        for(int col = 0; col <= row - 1; col++) {
            printf("*");
        }
        printf("\n");
    }
    // New trougao with 4 size
    trougao_size--;
    for(int row = 0; row  < trougao_size; row++) {
        printf(" ");
        // Spaces
        for (int space = 0; space < row; space++)
        {
            printf(" ");
        }
        // Left side
        for(int col = 0; col < trougao_size - row - 1; col++) {
            printf("*");
        }
        // Center
        printf("*");

        // Right side
        for(int col = 0; col < trougao_size - row - 1; col++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}