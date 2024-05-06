/*
A B C D E 
  A B C D 
    A B C 
      A B 
        A
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char letters[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F'};

    for(int row = 5; row > 0; row--) {
        for(int space = 5 - row; space > 0; space--) {
            printf("  ");
        }
        for(int column = 1; column <= row; column++) {
            printf("%c ", letters[column]);
        }
        printf("\n");
    }
    return 0;
    return 0;
}