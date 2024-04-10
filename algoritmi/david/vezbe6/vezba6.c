#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>





int main(){


FILE *fptr;
double cena;
double zbir;
double brojac;

fptr=fopen("brojevi.txt", "r");
if(fptr==NULL){
    printf("greska");
    exit(1);
}


while(    fscanf(fptr, "%lf", &cena) != EOF){

    zbir+=cena;
    brojac++;
    printf("cena %d. artikla je %.2lf\n", brojac, cena);
}




printf("zbir cena %d artikala je %.2lf", brojac, zbir);







fclose(fptr);


return 0;

}