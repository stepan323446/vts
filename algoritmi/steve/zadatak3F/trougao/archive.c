#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int trougao_size = 5;
    int numberRow = 1;
    for (int row = 0; row < trougao_size; row++)
    {
        // variable for numbers, every new row we start from trougao_size
        int number = numberRow;

        // Same as first example for figure
        for (int col = 0; col <= row; col++)
        {
            printf("%d ", number--);
        }
        printf("\n");
        numberRow++;
    }

    return 0;
}