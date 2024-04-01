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






void saberiMatrice (int m, int n, int matricaA[][MAX], int matricaB[][MAX], int matricaC[][MAX]){
int row, col;

    for(row=0; row<m; row++){
        for(col=0; col<n; col++){
        matricaC[row][col]=matricaA[row][col]+matricaB[row][col];
    }
    }



    
}


int main(){

    int min, max, m, n;
    int matricaA[MAX][MAX];
    int matricaB[MAX][MAX];
    int matricaC[MAX][MAX];
    srand(time(0));




 printf("donja granica: ");
    scanf("%d", &min);
    printf("gornja granica: ");
    scanf("%d", &max);
    printf("broj redova (maksimum 50, minimum 1): ");
    scanf("%d", &m);
    printf("broj kolona (maksimum 50, minimum 1): ");
    scanf("%d", &n);



    printf("\nMatrica A: \n");
    generisiMatricu(min, max, matricaA, m, n);
    ispisiMatricu(m, n, matricaA);






    printf("\nMatrica B: \n");
    generisiMatricu(min, max, matricaB, m, n);
    ispisiMatricu(m, n, matricaB);



    printf("\nMatrica A+B: \n");
    saberiMatrice (m, n, matricaA, matricaB, matricaC);
    ispisiMatricu(m, n, matricaC);
    
}
