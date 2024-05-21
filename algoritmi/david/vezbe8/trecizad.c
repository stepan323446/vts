#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>



int main(){
int n;
int min=20;
int max=30;
    srand(time(0));
    n=rand()%(max-min+1)+min;

printf("random num from %d to %d: %d", min,max,n);




    return 0;
}