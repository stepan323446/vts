#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct proizvodi{

    char naziv[20];
    int kolicina;
    float cena;

};


int citanje (struct proizvodi p[]){
        FILE *fp;

        fp=fopen("cene.txt", "r");

        if(!fp){
        printf("greska");
        return 1;
        }

int brojac=0;
char str[20];

while(fgets(str,sizeof(str),fp)!=0){
    int len=strlen(str);
    if(len>0 && str[len-1]=='\n'){
        str[len-1]='\0';

        strcpy(p[brojac].naziv, str);
        fgets(str, sizeof(str), fp);
        p[brojac].kolicina=atoi(str);
        fgets(str, sizeof(str), fp);
        p[brojac].cena=atof(str);
        brojac++;

    }
}


fclose(fp);
return brojac;
}



void ispis(struct proizvodi p[], int n){


for (int i = 0; i < n; i++)
{
    printf("proizvod %s kolicina %d cena %.2f\n", p[i].naziv, p[i].kolicina, p[i].cena);
}




}


int main() {
    
    struct proizvodi pro[10];
    int brojProizvoda=citanje(pro);
    ispis(pro, brojProizvoda);


    return 0;
}