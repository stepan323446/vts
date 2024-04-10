#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100




int main(){

int m, n;
int x=MAX;
int k;

for ( m = 1; m <= x; m++)
{
    for ( n = x-1; n >= m; n--)
    printf(" ");

    for(k=1; k<=m; k++)
    printf("* ");

    printf("\n");

}



return 0;
}