/*
        E 
      D D 
    C C C 
  B B B B 
A A A A A
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int index = 4;
    for(int row = 5; row > 0; row--) {
        for(int space = row - 1; space > 0; space--) {
            printf("  ");
        }
        for(int col = 0; col <= 5 - row; col++) {
            printf("%c ", letters[index]);
        }
        index--;
        printf("\n");
    }
    return 0;
}