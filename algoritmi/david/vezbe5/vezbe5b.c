#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100
//selection sort isto treba znati kao binary search

void selectionSort (int niz[], int n){

    int i, j, min_idx;
    for ( i = 0; i < n-1; i++)
    {
        min_idx=1;

        for ( j = i+1; j < n; j++)
        {
            if(niz[i]<niz[min_idx])
            min_idx=j;
        }


        int temp=niz[min_idx];
        niz[min_idx]=niz[i];
        niz[i]=temp;


        
    }
    
    

}


void ispisiNiz (int n, int niz[]){

printf("niz: ");
    for(int i=0; i<n; i++){
        printf("%d ", niz[i]);
    }

}








int main(){


    int niz[]={5,2,8,4,3,12};
    int n=sizeof(niz)/sizeof(niz[0]);
    
    ispisiNiz(n, niz);


    selectionSort(niz, n);
    ispisiNiz(n, niz);



return 0;
}