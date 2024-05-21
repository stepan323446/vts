#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void prvizad(int n)
{
    float zbir = 0;

    for (int i = 1; i <= n + 1; i++)
    {
        if (i % 2 != 0)
            zbir = zbir + (1.0 / (i * i));

        else
            zbir = zbir - (1.0 / (i * i));
    }
    printf("zbir je %.2f: \n", zbir);
}

void drugizad()
{
    int i, j, k;
    int num = 4;
    int br1 = 1;
    int br2 = br1;
    for (i = 1; i <= num; i++)
    {

        for (j = 1; j <= num - i; j++)
            printf("  ");

        for (k = 1; k <= i; k++)
            printf("%d ", br1--);

        printf("\n");
        br2++;
        br1 = br2;
    }
}

int trecizad(int a, int b){

int r=rand()%(b-a+1)+a;
return r;

}

int main()
{
    srand(time(0));
    int n;
    printf("koliko redova? ");
    scanf("%d", &n);

    prvizad(n);

    drugizad();

    int randomBR=trecizad(10,20);
    printf("\n %d", randomBR);

    return 0;
}