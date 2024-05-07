/*
        A 
      B A B 
    C B A B C 
  D C B A B C D 
E D C B A B C D E 
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char letters[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    int trougao_size = 5;

    for(int row = 0; row  < trougao_size; row++) {
        for(int space = trougao_size - row - 1; space > 0; space--) {
            printf("  ");
        }
        for(int col = row; col > 0; col--) {
            printf("%c ", letters[col]);
        }
        printf("%c ", letters[0]);
        for(int col = 0; col < row; col++) {
            printf("%c ", letters[col + 1]);
        }
        printf("\n");
    }
    return 0;
}