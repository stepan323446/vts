#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100

void generisiNiz (int min, int max, int niz[], int n) {

    int i;
    printf("niz slucajnih brojeva u intervalu od %d do %d\n", min, max);

    for(i=0; i<n; i++){

        niz[i]=rand()%(max-min+1)+min;
    }



}

void ispisiNiz (int n, int niz[]){

printf("niz: ");
    for(int i=0; i<n; i++){
        printf("%d ", niz[i]);
    }

}



double srednjaVrednost (int n, int niz[]){

    double suma=0;
    int i;

    for(i=0; i<n; i++)
    suma=suma+niz[i];

    return suma/n;
}



void bubbleSort (int n, int niz[]){

int i, j;
int temp;

for(i=0; i<n-1; i++){

    for(j=0; j<n-1-i; j++) {

        if(niz[j]>niz[j+1]) {
            
            temp=niz[j];
            niz[j]=niz[j+1];
            niz[j+1]=temp;

        }

    }
}

}


double medijana(int n,int niz[]){

    bubbleSort(n,niz);

    if (n%2==0){

        return (niz[n/2]+niz[n/2-1])/2.0;

    }

    else {

        return (niz[n/2])*1.0;
    }

}





/*int najseciBroj(int n, int niz[]){

int maxVrednost = niz[0];

for (int i=0; i<n; i++){

if (niz[i]>maxVrednost)
        maxVrednost=niz[i];

}


}*/


int pronadjiVrednost (int n,int niz[], int key){

    for(int i=0; i<n; i++){

        if(niz[i]==key)
            return 1;


    }

return 0;

}




    






int main(){

    int min, max, n;
    int niz[MAX];
    srand(time(0));


    printf("donja granica: ");
    scanf("%d", &min);
    printf("gornja granica: ");
    scanf("%d", &max);
    printf("broj clanova niza: ");
    scanf("%d", &n);

    generisiNiz (min, max, niz, n);

    ispisiNiz(n,niz);


    double prosek;
    prosek=srednjaVrednost(n,niz);

    printf("\nprosek je %lf\n", prosek);

    bubbleSort(n,niz);
    ispisiNiz(n,niz);



     double med=medijana(n,niz);

    printf("\nmedijana niza je %.2f\n", med);
    

    int key;
    printf("\nsta trazimo: \n");
    scanf("%d", &key);

    int nasao=pronadjiVrednost(n,niz,key);

    if (key==1)
        printf("ima");

    else 
     printf("nema");



    return 0;
}
