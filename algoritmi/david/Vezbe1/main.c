#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long int fact(int n); //prototip f-je
/*int prostBroj(int broj) {
int i;
for(i=2; i<=(broj/2); i++) {
    if(broj%i !=0)
        continue; //nastavlja se sa izvrsavanjem for petlje
    else
        return 1;

}
return 0;
}*/
int main()
{
    /*int n;
    int i;
    double suma;
    printf("koliko clanova reda zelite (n=)");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        if(i%2==0)
            suma=suma+1/pow(2,i);
        else
            suma=suma-1/pow(2,i);
        printf("Resenje je: %2f", suma);*/



    /*int n;
    unsigned long long fact=1;
    printf("n= ");
    scanf("%d", &n);
    if (n<0)
        printf("broj mora biti pozitivan");
    else{
        for(int i=1; i<=n; i++) //i je samo unutar for petlje
            fact=fact*i;
        }
    printf("Faktorijel broja %d je %llu", n, fact);*/




    int n; //f-ja
    printf("unesite poz ceo broj");
    scanf("%d", &n);


    long int fact (int n) {
    if (n>=1)
        return n*fact(n-1);
    else
        return 1;
    //uslov zaust je n=1
    }
    printf("Faktorijel od %d=%ld",n, fact(n));


    /*int n;
    int res;
    printf("n= ");
    scanf("%d", &n);
    res=prostBroj (n);
    if (res==0)
        printf("prost");
    else
        printf("nije prost");*/


//fibonaci

    /*int i, n;
    int f1=0, f2=1; //prva dva clana fibo niza
    int f3=f1+f2; //sledeci clan
    printf("Br clanova niza: "); //br clanova
    scanf("%d", &n);
    printf("Fibonacijev niz: %d, %d, ", f1,f2);
    for(i=3; i<=n; i++ ){
        printf("%d, ", f3);
        f1=f2;
        f2=f3;
        f3=f1+f2;
    }*/




    return 0;

}
