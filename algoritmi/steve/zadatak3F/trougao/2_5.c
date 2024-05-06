/*
E D C B A 
  E D C B 
    E D C 
      E D 
        E
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char letters[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F'};

    for(int row = 5; row > 0; row--) {
        int number = 5;
        for(int space = 5 - row; space > 0; space--) {
            printf("  ");
        }
        for(int column = row; column > 0; column--) {
            printf("%c ", letters[number--]);
        }
        printf("\n");
    }
    return 0;
    return 0;
}