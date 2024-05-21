#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){


int i,j;
int n=5;
int z=n;
int k=n;
for(i=n; i>0; i--){
    for(j=1; j<=i; j++){

        printf("%d ", z);
        z--;

    }
    k++;
  z= k;
    printf("\n");
}




    return 0;
}