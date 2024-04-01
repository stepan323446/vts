#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 50


void generisiNiz (int min, int max, int niz[], int n) {

    int i;
    printf("niz slucajnih brojeva u intervalu od %d do %d\n", min, max);

    for(i=0; i<n; i++){

        niz[i]=rand()%(max-min+1)+min;
    }



}


void ispisiNiz (int n, int niz[]){

printf("\nniz: ");
    for(int i=0; i<n; i++){
        printf("%d ", niz[i]);
    }

}


int najmanjiPocetak (int n, int niz[]){

int i, j;
int min=niz[0];
int minIndex=0;

for(i=0; i<n; i++){ 

        if(niz[i]<min) {
            
            min=niz[i];

        }

    
}

return min;

}



int main(){

    int min, max, n;
    int niz[MAX];
    int najmanji;
   
    srand(time(0));


    printf("donja granica: ");
    scanf("%d", &min);
    printf("gornja granica: ");
    scanf("%d", &max);
    printf("broj clanova niza(maksimum 50, minimum 1): ");
    scanf("%d", &n);

    generisiNiz (min, max, niz, n);
    ispisiNiz(n,niz);


    najmanji=najmanjiPocetak(n,niz);


    for ( int i = n; i >= 0; i--)
    {
    
        niz[i+1]=niz[i];

    }

    niz[0]=najmanji;
    n=n+1;
    ispisiNiz(n,niz);

      return 0;  
}