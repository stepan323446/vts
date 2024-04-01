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


void indeksNajvecegRed (int m, int n, int matrica[][MAX]){
int row, col;
int x, y;
int najveci=0;
    for(row=0; row<m; row++){
        
        for(col=0; col<n; col++){
           if(matrica[row][col]>najveci || matrica[row][col]==najveci){
            najveci=matrica[row][col];
            x=row;
            y=col;
           }
        }
        printf("najveci u %d. redu je %d\n", row+1, najveci);
        printf("indeks najveceg u %d. redu je %d,%d\n", row+1, x, y);


        najveci=matrica[row+1][0];

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

    
    indeksNajvecegRed(m, n, matrica);

    return 0;
}