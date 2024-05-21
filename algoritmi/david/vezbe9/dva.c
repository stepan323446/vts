#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){


int i,j;
int n=5;

for(i=1; i<=n; i++){
    for(j=1; j<=i; j++){

        if (i%2){
            printf("%d " , 1);
        }

        else
        printf("%d ", 0);


    }

    printf("\n");
}




    return 0;
}