#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>





int main(){


FILE *fptr;
char ch;
int w=0;
int c=0;





fptr=fopen("ocene.txt", "r");
if (fptr==NULL){
printf("greska");
exit(1);
}


ch=fgetc(fptr);


printf("sadrzaj datoteke: ");
while(ch!=EOF){

    printf("%c", ch);
    if(ch==' ' || ch=='\n')
    w++;
    else
    c++;

    ch=fgetc(fptr);
}


printf("broj reci je %d\n", w);
printf("broj karaktera je %d", c);





fclose(fptr);


return 0;

}