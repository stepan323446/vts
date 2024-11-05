/*
        E 
      E D 
    E D C 
  E D C B 
E D C B A
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    for(int row = 5; row > 0; row--) {
        int index = 4;
        for(int space = row - 1; space > 0; space--) {
            printf("  ");
        }
        for(int col = 0; col <= 5 - row; col++) {
            printf("%c ", letters[index--]);
        }
        printf("\n");

    }

    return 0;
}