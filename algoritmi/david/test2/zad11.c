#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 50





void generisiMatricu (int min, int max, int matrica[][MAX], int m) {

    int row, col;
    printf("matrica (%dx%d) slucajnih brojeva u intervalu od %d do %d\n", m, m, min, max);

    for(row=0; row<m; row++){
        for(col=0; col<m; col++){
        matrica[row][col]=rand()%(max-min+1)+min;
        }
    }



}



void ispisiMatricu (int m, int matrica[][MAX]){
int row, col;
printf("\nmatrica: \n");
    for(row=0; row<m; row++){
        for(col=0; col<m; col++){
        printf("%d\t", matrica[row][col]);
    }
    printf("\n");
    }

}



void najveciGlavna (int m, int matrica[][MAX]){
int row, col;
int i=0;
int najveci=0;
    for(row=0; row<m; row++){
        for(col=0; col<m; col++){
            
            if (row<col && matrica[row][col]>najveci){
               
                    najveci=matrica[row][col];
                

            }


    }
    }
    
    printf("najveci element iznad gorenje diajgonale je %d", najveci);

}



int main(){

    int min, max, m;
    int matrica[MAX][MAX];
    srand(time(0));




 printf("donja granica: ");
    scanf("%d", &min);
    printf("gornja granica: ");
    scanf("%d", &max);
    printf("broj redova i kolona (maksimum 50, minimum 1): ");
    scanf("%d", &m);
   




    generisiMatricu(min, max, matrica, m);
    ispisiMatricu(m, matrica);


    najveciGlavna(m, matrica);

}