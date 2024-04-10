#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>





int main(){


FILE *fptr;
int ukupno=0;
int velika=0;
int mala=0;
int cifre=0;
int misc=0;


fptr=fopen("podaci.data", "r");
if(fptr==NULL){
    printf("greska");
    exit(1);
}

char c;
while( ( c=fgetc(fptr))=!EOF){
    if(c>='A' && c<='Z')
        velika++;

    else if(c>='a' && c<='a')
        mala++;

    else if(c>='A' && c<='Z')
        cifre++;

    else
        misc++;


}





fclose(fptr);

printf("velika %d, mala %d, cifre %d, ostalo", velika,mala,cifre, misc);


return 0;

}