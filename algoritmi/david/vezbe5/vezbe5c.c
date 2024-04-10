#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100




int main(){

int m, n;
int x=5;


for ( m = 1; m <= x; m++)
{
    for ( n = 1; n <= m; n++)
    printf("%d ", x-m+1);


    printf("\n");

}



return 0;
}