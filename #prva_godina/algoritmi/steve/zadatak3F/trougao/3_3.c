/*
    A 
   A B 
  A B C 
 A B C D 
A B C D E 
 A B C D 
  A B C 
   A B 
    A 
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char letters[] = { 'A', 'B', 'C', 'D', 'E', 'F' };

    int trougao_size = 5;
    for(int row = 0; row  < trougao_size; row++) {
        int number = 0;
        for(int space = trougao_size - row - 1; space > 0; space--) {
            printf(" ");
        }
        for(int col = 0; col <= row; col++) {
            printf("%c ", letters[number++]);
        }
        printf("\n");
    }

    trougao_size--;
    for(int row = 0; row  < trougao_size; row++) {
        int number = 0;
        for (int space = 0; space <= row; space++)
        {
            printf(" ");
        }
        for(int col = 0; col < trougao_size - row; col++) {
            printf("%c ", letters[number++]);
        }
        printf("\n");
    }
    return 0;
}