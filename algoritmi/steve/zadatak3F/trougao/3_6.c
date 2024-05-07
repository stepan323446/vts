/*
A B C D E 
A B C D 
A B C 
A B 
A 
A B 
A B C 
A B C D 
A B C D E 
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char letters[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    int trougao_size = 5;

    for(int row = 0; row < trougao_size; row++) {
        int index = 0;
        for(int col = 0; col < trougao_size - row; col++) 
        {
            printf("%c ", letters[index++]);
        }
        // New line
        printf("\n");
    }
    for (int row = 0; row < trougao_size; row++)
    {
        int index = 0;
        if(row == 0)
            continue;

        for (int col = 0; col <= row; col++)
        {
            printf("%c ", letters[index++]);
        }
        // New line
        printf("\n");
    }
    return 0;
}