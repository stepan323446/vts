#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
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



void iznadGlavne (int m, int n, int matrica[][MAX]){

int row, col;
printf("\nmatrica: \n");
    for(row=0; row<m; row++){
        for(col=0; col<n; col++){
            if(row<col)
        printf("%d\t", matrica[row][col]);
    }
    printf("\n");
    }




}


int isPrime(int n){

    if(n==1 || n==0){
    return 0;
    
    }


else{
for(int i=2; i<=n/2; i++){
if (n % i == 0) {
    return 0;
      break;
    }



    }
}

return 1;
}


void ispisiProste(int m, int n, int matrica[][MAX]){
int row, col;

    printf("\nmatrica: \n");
    for(row=0; row<m; row++){
        for(col=0; col<n; col++){
            if(isPrime(matrica[row][col]))
        printf("%d\t", matrica[row][col]);
    }
    printf("\n");
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


    iznadGlavne(m, n, matrica);
    ispisiProste(m, n, matrica);






    return 0;
}