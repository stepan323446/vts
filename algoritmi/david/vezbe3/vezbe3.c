#include <stdlib.h>
#include <stdio.h>
#include <math.h>





/*int main(){

    int arr[100]={0};
    int i, x, poz, n=10;


    for (i=0; i<n; i++) {
        arr[i]=4*i-1; //bilo sta

    }
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nkoji broj ");
    scanf("%d", &x);

   printf("koja pozicija ");
    scanf("%d", &poz); 

    n++; //dim povecamo za 1
    //pomeranje za jedno mesto udesno
    for(i=n-1; i>=poz; i--) {
        arr[i]=arr[i-1];
    }

    arr[poz-1]=x; //dodavanje na zadatu poziciju

    printf("\nIspisivanje niza sa ubacenim elementom %d na poziciji %d \n", x, poz);
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}*/



/*void unija(int arr1[], int arr2[], int m, int n) {

    int i=0, j=0;
    while (i<m && j<n) {

        if (arr1[i]<arr2[j]){
            printf("%d ", arr1[i]);
        i++;
        }
        else if (arr2[j]<arr1[i]) {

            printf("%d ", arr2[j]);
        j++;
        }
        else {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }

    }//radi dok ne dodjemo do kraja jednog od dva niza


    //ispis elemenata duzeg niza
    while(i<m) {
        printf("%d ", arr1[i]);
        i++;
    }


    while(j<n) {
        printf("%d ", arr2[j]);
        j++;
    }
}


int main() {


    int niz1[]={1,3,7,10,12};
    int niz2[]={2,4,8,12,13,145,200};
    int m=sizeof(niz1)/sizeof(niz1[0]);
    int n=sizeof(niz2)/sizeof(niz2[0]);

    unija(niz1, niz2, m, n);


    return 0;
}*/




/*void presek(int arr1[], int arr2[], int m, int n) {

    int arr3[100];
    int i,j,k;

    k=0;

    for (i=0; i<m; i++){
        for (j=0; j<n; j++) {
            if(arr1[i]==arr2[j]) {
                arr3[k]=arr1[i];

                k++;
            }
        }
    }
    printf("\nPresek dva niza: ");
    for ( i = 0; i < k; i++)
    {
        printf("%d ", arr3[i]);
    }
    

}


int main(){


    int niz1[]={1,3,7,10,12};
    int niz2[]={2,4,8,12,13,145,200};
    int m=sizeof(niz1)/sizeof(niz1[0]);
    int n=sizeof(niz2)/sizeof(niz2[0]);

    presek(niz1, niz2, m, n);



    return 0;
}*/




/*int postoji(int arr[], int m, int key) {

    int i;
    int nasao=0;

    for (i=0; i<m; i++) {
        
        if (arr[i]==key)
            nasao=1;

    }



}



int main(){


    int niz1[]={1,3,7,10,12};
    
    int m=sizeof(niz1)/sizeof(niz1[0]);


    int find;
    int broj=10;
    find=postoji(niz1, m, broj);
    if (find==1) {
        printf("u nizu je ");
    }
    else {
        printf("u nizu nije ");

    }


    return 0;
}*/


#define MAX_R 3
#define MAX_K 3
void unos(int a[MAX_R][MAX_K]){

    int i,j;

    for(i=0; i<MAX_R; i++) {

        for (j=0; j<MAX_R; j++) {
            printf("unesite element [%d][%d] ", i,j);
            scanf("%d", &a[i][j]);

        }

    }

}



void ispis(int a[MAX_R][MAX_K]){

    int i,j;
    for(i=0; i<MAX_R; i++){
            for(j=0; j<MAX_K; j++){
                printf("%d\t", a); //here
            }

    }

}


int main() {

int m[MAX_R][MAX_K];
unos(m);
printf("\nuneli ste\n");
ispis(m);




    return 0;
}
