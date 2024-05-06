/*
        1 
      2 2 
    3 3 3 
  4 4 4 4 
5 5 5 5 5
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    for(int row = 1; row <= 5; row++) {
        for(int space = 5 - row; space > 0; space--) {
            printf("  ");
        }
        for(int column = 1; column <= row; column++) {
            printf("%d ", row);
        }
        printf("\n");
    }
    return 0;
}