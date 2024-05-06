/*
5 4 3 2 1 
  4 3 2 1 
    3 2 1 
      2 1 
        1
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    for(int row = 5; row > 0; row--) {
        for(int space = 5 - row; space > 0; space--) {
            printf("  ");
        }
        for(int column = row; column > 0; column--) {
            printf("%d ", column);
        }
        printf("\n");
    }
    return 0;
}