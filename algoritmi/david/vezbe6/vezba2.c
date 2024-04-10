#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>





int main(){


FILE *fptr;
int broj;

fptr=fopen("program.txt", "r");
if (fptr==NULL){
printf("greska");
exit(1);
}

fscanf(fptr, "%d", &broj);
printf("broj je %d", broj);
fclose(fptr);


return 0;

}