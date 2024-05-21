#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
 

int fact(int d){

    int rez;
    if(d>0)
    rez=d*fact(d-1);
    else
    return 1;

    return rez;
}

 double f(int n){

    double suma=1;
    for(int i=1; i<=n; i++){

        if(i%2!=0){
            suma=suma-(1.0/fact(i));
        }

        else{
            suma=suma+(1.0/fact(i));
        }



    }

 return suma;

 }

 int main(){
int n;

printf("koliko redova?");
scanf("%d", &n);
double sum;
sum=f(n);
printf("suma je %lf", sum);



    return 0;
 }