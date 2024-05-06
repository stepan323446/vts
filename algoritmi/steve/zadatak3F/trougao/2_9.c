/*
        A 
      B B 
    C C C 
  D D D D 
E E E E E
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int index = 0;
    for(int row = 5; row > 0; row--) {
        for(int space = row - 1; space > 0; space--) {
            printf("  ");
        }
        for(int col = 0; col <= 5 - row; col++) {
            printf("%c ", letters[index]);
        }
        index++;
        printf("\n");
    }
    return 0;
}