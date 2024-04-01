#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 50





void generisiMatricu (int min, int max, int matrica[][MAX], int m, int n) {

    int row, col;
    printf("matrica (%dx%d) slucajnih brojeva u intervalu od %d do %d\n", m, n, min, max);

    for(row=0; row<m; row++){
        for(col=0; col<n; col++){
        matrica[row][col]=rand()%(max-min+1)+min;
        }
    }



}



void ispisiMatricu (int m, int n, int matrica[][MAX]){
int row, col;
printf("\nmatrica: \n");
    for(row=0; row<m; row++){
        for(col=0; col<n; col++){
        printf("%d\t", matrica[row][col]);
    }
    printf("\n");
    }

}


void indeksNajmanjegKolona (int m, int n, int matrica[][MAX]){
int row, col;
int x=0, y=0;
int najmanji=999;
    for(col=0; col<n; col++){
        
        for(row=0; row<m; row++){
           if(matrica[row][col]<najmanji || matrica[row][col]==najmanji){
            najmanji=matrica[row][col];
           
            x=row;
            y=col;
           
           }
        }
        printf("najmanji u %d. koloni je %d\n", col+1, najmanji);
        printf("indeks najveceg u %d. koloni je %d,%d\n", col+1, x, y);
        najmanji=matrica[0][col+1];


    }


    


}



int main(){

    int min, max, m, n;
    int matrica[MAX][MAX];
    srand(time(0));




 printf("donja granica: ");
    scanf("%d", &min);
    printf("gornja granica: ");
    scanf("%d", &max);
    printf("broj redova (maksimum 50, minimum 1): ");
    scanf("%d", &m);
    printf("broj kolona (maksimum 50, minimum 1): ");
    scanf("%d", &n);




    generisiMatricu(min, max, matrica, m, n);
    ispisiMatricu(m, n, matrica);

    
    indeksNajmanjegKolona(m, n, matrica);

    return 0;
}