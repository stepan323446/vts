#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>



int main(){

    int n;

    printf("koliko redova: ");
    scanf("%d", &n);

    
    for(int i=2*n; i>0; i=i-2){
        if(i!=2){
        for(int j=0; j<i; j++)
        printf("%d ", i/2);
        }
        printf("\n");
        }

    



    return 0;
}