#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int trougao_size = 5;
for (int row = 0; row < trougao_size; row++)
{
    for (int space = 0; space < row; space++)
    {
        // one space instead of two
        printf(" ");
    }

    // Same
    for (int col = 0; col < trougao_size - row; col++)
    {
        // 2 symbols
        printf("* ");
    }
    printf("\n");
}

    return 0;
}