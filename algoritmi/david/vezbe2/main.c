#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void ucitajNiz (int a[], int n) {
   for(int i=0; i<n; i++) {
        printf("%d.element: ", i+1);
        scanf("%d", &a[i]);
    }
}


void ispisiNiz (int a[], int n) {
    printf("\nElementi niza su:\n");
    for(int i=0; i<n; i++){
        printf("%d\t", a[i]);
    }
}



int najveciBroj (int a[], int n){
    int max=a[0];
    for (int i=1; i<n; i++) {
        if(a[i]>max)
            max=a[i];

    }
    return max;
}


int drugiNajveci (int a[], int n) {
    int max1=a[0];
    int max2=a[1];
    if (max1<max2){
        int temp=max1;
        max1=max2;
        max2=temp;
    }

    for (int i=2; i<n; i++) {
        if (a[i]>max1) {
            max2=max1;
            max1=a[i];
        }
        else if (a[i]>max2 && a[i]!=max1){
            max2=a[i];
        }
    }
    return max2;
}


int main()
{
    int a [MAX_SIZE];
    int n;
    printf("Dimenzija niza je n= ");
    scanf("%d", &n);

    printf("Unesite %d elemenata niza\n", n);
    ucitajNiz(a,n);
 


    ispisiNiz(a,n);
    
    int najveci=najveciBroj(a,n);
    
    printf("\nnajveca vrednost niza je %d", najveci);
    printf("\n");
    printf("drugi najveci element u nizu:");

    int drugiMax=drugiNajveci(a,n);
    
   printf("\nnajveci je %d", najveci);
   printf("\ndrugi najveci je %d\n", drugiMax);
   
   
   
   
    return 0;
}



