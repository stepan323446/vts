#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>





int main(){


FILE *fptr;
int broj;


fptr=fopen("program.txt", "w");
if(fptr==NULL){
    printf("greska");
    exit(1);
}

printf("unesi broj ");
scanf("%d", &broj);

fprintf(fptr, "%d", broj);
fclose(fptr);


return 0;

}