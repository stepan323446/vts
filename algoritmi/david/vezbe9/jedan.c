#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

struct Artikal{
    char naziv[20];
    int kolicina;
    float cena;
};


int brojArtikala(struct Artikal arr[]){

    FILE *fp;
    fp=fopen("cene.txt", "r");
    if(!fp){

        printf("greska");
        return 1;

    }

int broj=0;
char ime[20];
int k;
float c;

while(fscanf(fp, "%s %d %f", ime, &k, &c)!=EOF){

    strcpy(arr[broj].naziv, ime);
    arr[broj].kolicina, k;
    arr[broj].cena=c;
    broj++;

}
fclose(fp);
return broj;


}


void ispisiPodatke(struct Artikal arr[], int n){



for (int i=0; i<n; i++){

    printf("artikal: %s\t kolicina: %d\t cena: %.2f \n", arr[i].naziv, arr[i].kolicina, arr[i].cena);


}



}

void sortCena(struct Artikal ar[], int n){

    struct Artikal temp;
    int zamena=0;
    for (int i = 0; i < n-1; i++)
    {
        zamena=0;

        for (int j = 0; j < n-1; j++)
        {
            if(ar[j].cena>ar[j+1].cena){

                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
                zamena=1;


            }
        }
        if(!zamena)
        break;
    }
    



}

void sortName(struct Artikal a[], int n){


    struct Artikal temp;
    int zamena=0;
    for (int i = 0; i < n-1; i++)
    {
        zamena=0;

        for (int j = 0; j < n-1; j++)
        {

            if(strcmp(a[j].naziv,a[j+1].naziv)){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                zamena=1;

            }

        }
        if(!zamena)
        break;
    }

}

int main(){

int n=10;
struct Artikal a[n];
int br;
br=brojArtikala(a);

printf("br artikala je %d", br);

printf("\nsadrzaj: \n");
ispisiPodatke(a,br);


printf("sort po ceni\n");
sortCena(a,br);
ispisiPodatke(a,br);

printf("sort po name\n");
sortName(a,br);
ispisiPodatke(a,br);


    return 0;
}