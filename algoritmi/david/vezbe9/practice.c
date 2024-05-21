#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, j, k;
    int n = 5;

    for (i = 1; i <= n; i++)
    {

        for (k = 1; k <= n - i; k++)
        {
            printf(" ");
        }

        for (j = 1; j <= i; j++)
        {

            printf("* ");
        }
        printf("\n");
    }

    for (i = 1; i <= n; i++){
       
         for (j = 1; j <= i; j++)
        {

            printf(" ");
        }
         for (k = 1; k <= n - i; k++){
            printf("* ");

        }

            printf("\n");

    }
    



    return 0;
}