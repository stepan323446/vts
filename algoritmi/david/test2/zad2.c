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





int najveciBroj (int n, int niz[]){

int i, j;
int max=niz[0];

for(i=0; i<n; i++){ 

        if(niz[i]>max) {
            
            max=niz[i];

        }

    
}

return max;

}


int main(){

    int min, max, n;
    int niz[MAX];
    int najmanji;
    int k;
    srand(time(0));


    printf("donja granica: ");
    scanf("%d", &min);
    printf("gornja granica: ");
    scanf("%d", &max);
    printf("broj clanova niza(maksimum 50, minimum 1): ");
    scanf("%d", &n);

    generisiNiz (min, max, niz, n);
    ispisiNiz(n,niz);


    int najveci=najveciBroj ( n,  niz);
    
    printf("\nsa kojim mnozimo? \n");
    scanf("%d", &k);

    for ( int i = 0; i < n; i++) {
        if (niz[i]==najveci)
        {
            niz[i]=niz[i]*k;
        }
        
    }

    ispisiNiz(n,niz);


}