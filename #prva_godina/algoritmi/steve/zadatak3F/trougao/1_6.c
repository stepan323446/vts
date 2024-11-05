/*
1 1 1 1 1 
  2 2 2 2 
    3 3 3 
      4 4 
        5 
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 1;

    for(int row = 5; row > 0; row--) {
        for(int space = 5 - row; space > 0; space--) {
            printf("  ");
        }
        for(int column = row; column > 0; column--) {
            printf("%d ", number);
        }
        printf("\n");
        number++;
    }
    return 0;
}