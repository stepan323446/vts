#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>





int main(){


FILE *fptr;
char ime[30];
int ocena;
int i;
int n;



printf("unesite broj studenata ");
scanf("%d", &n);




fptr=fopen("ocene.txt", "w");
if (fptr==NULL){
printf("greska");
exit(1);
}

for(i=0; i<n; i++){
printf("unesi ime ");
scanf("%s", &ime);


printf("unesi ocenu ");
scanf("%d", &ocena);

fprintf(fptr, "ime:%s \nOcena:%d\n", ime,ocena);
}

fclose(fptr);


return 0;

}