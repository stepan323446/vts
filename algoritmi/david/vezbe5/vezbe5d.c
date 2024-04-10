#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100




int main(){

int m, n;
int x=5;


for ( m = x; m >= 1; m--)
{
    for ( n = m; n >= 1; n--)
    printf("%d ", (x+1)-(m-n+1));


    printf("\n");

}



return 0;
}