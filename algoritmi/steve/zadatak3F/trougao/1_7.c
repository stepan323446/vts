/*
5 5 5 5 5 
4 4 4 4 
3 3 3 
2 2 
1 
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 5;
    for(int row = 5; row > 0; row--) {
        for(int column = row; column > 0; column--) {
            printf("%d ", number);
        }
        printf("\n");
        number--;
    }
    return 0;
}