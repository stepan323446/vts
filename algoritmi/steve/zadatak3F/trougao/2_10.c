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
    const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    for(int row = 5; row > 0; row--) {
        for(int col = 0; col < row; col++) {
            printf("%c ", letters[col]);
        }
        printf("\n");
    }
    return 0;
}