#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int trougao_size = 5;

    for (int row = trougao_size; row > 0; row--)
    {

        // Same as first example for figure
        for (int col = trougao_size - row; col >= 0; col--)
        {
            printf("%d ", col + 1);
        }
        printf("\n");
    }
    return 0;
}