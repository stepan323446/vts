/*
5 
4 4 
3 3 3 
2 2 2 2 
1 1 1 1 1
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 5;
    for(int row = 1; row <= 5; row++) {
        for(int column = 1; column <= row; column++) {
            printf("%d ", number);
        }
        number--;
        printf("\n");
    }

    return 0;
}