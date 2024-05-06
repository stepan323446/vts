/*
        1 
      1 2 
    1 2 3 
  1 2 3 4 
1 2 3 4 5
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    for(int row = 1; row <= 5; row++) {
        for(int space = 5 - row; space > 0; space--) {
            printf("  ");
        }
        for(int column = 1; column <= row; column++) {
            printf("%d ", column);
        }
        printf("\n");
    }
    return 0;
}