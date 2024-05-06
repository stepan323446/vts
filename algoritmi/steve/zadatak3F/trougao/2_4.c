/*
E E E E E 
  D D D D 
    C C C 
      B B 
        A
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char letters[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F'};
    
    int number = 5;

    for(int row = 5; row > 0; row--) {
        for(int space = 5 - row; space > 0; space--) {
            printf("  ");
        }
        for(int column = row; column > 0; column--) {
            printf("%c ", letters[number]);
        }
        printf("\n");
        number--;
    }
    return 0;
}