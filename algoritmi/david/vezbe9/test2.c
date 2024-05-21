#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k;
    int n = 5;
    int num = 1;
    for (i = 1; i <= n; i++)
    {

        for (k = 1; k <= n - i; k++)
            printf(" ");

        for (j = 1; j <= i; j++)
            printf("%d ", num);

        printf("\n");
        num++;
    }
    num = 4;
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= i; j++)
            printf(" ");

        for (k = 1; k <= n - i; k++)
            printf("%d ", num);

        num--;
        printf("\n");
    }

    return 0;
}
