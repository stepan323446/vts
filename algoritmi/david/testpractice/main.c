#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//NEMA 1. ZAD JER JE ISTI SKORO KAO 2.
//NEMA 14  I 15 JER NE ZNAM
//added
/*int main()
{
    int n, i;
    double suma=1;
    int fact=1;
    printf("Koliko clanova reda zelite: ");
    scanf("%d", &n);
    for(i=1; i<n; i++) {
        fact *= i;
        if (i%2==0)
            suma += 1.0/fact;
        else
            suma -= 1.0/fact;
    }
printf("\nSuma reda je: %lf", suma);
printf("\nRealna vrednost je: %lf", 1/M_E);

   return 0;
}*/

/*int main() {
    int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=1; i<n; i++) {
        if (i%2!=0)
            suma += 1.0/i;
        else
            suma -= 1.0/i;
    }
    double rez;
    rez = log(2);
    printf("Suma redova je %lf\n", suma);
    printf("pravi rez je %lf", rez);



return 0;
}*/



int main() {

    int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=1; i<n; i++) {
        if (i%2!=0)
            suma += 1.0/(2*i-1);
        else
            suma -= 1.0/(2*i-1);

    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = M_PI/4;
    printf("\n real rez je %lf", rez);

return 0;
}



/*int main() {

int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=1; i<n; i++) {
            suma += 1.0/((4*i-1)*(4*i+1));
    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = (4-M_PI)/8;
    printf("\n real rez je %lf", rez);

return 0;


return 0;
}*/

/*int main() {

 int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        if (i%2!=0)
            suma += 1.0/(i*i);
        else
            suma -= 1.0/(i*i);

    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = (pow(M_PI, 2))/12;
    printf("\n real rez je %lf", rez);



     return 0;
}*/



/*int main() {

int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    int temp;
    for(i=0; i<=n; i++) {
            temp=(2*i+1);
            suma += 1.0/(temp*temp);
    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = (pow(M_PI, 2))/8;
    printf("\n real rez je %lf", rez);


return 0;
}*/


/*int main() {

int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=1; i<n; i++) {
            suma += 1.0/(i*i*i*i);

    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = (pow(M_PI, 4))/90;
    printf("\n real rez je %lf", rez);




return 0;
}*/


/*int main() {
int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=1; i<n; i++) {
        if (i%2!=0)
            suma += 1.0/(i*i*i*i);
        else
            suma -= 1.0/(i*i*i*i);

    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = (7*(pow(M_PI, 4)))/720;
    printf("\n real rez je %lf", rez);



return 0;
}*/



/*int main() {
int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
            int t;
            t=(2*i+1);
            suma += 1.0/(t*t*t*t);
    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = (pow(M_PI, 4))/96;
    printf("\n real rez je %lf", rez);




return 0;
}*/




/*int main() {

int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=1; i<n; i++) {
            suma += 1.0/(i*i);

    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = (pow(M_PI, 2))/6;
    printf("\n real rez je %lf", rez);




return 0;
}*/



/*int main(){

int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=2; i<n; i++) {
            suma += 1.0/((i-1)*(i+1));

    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = 3.0/4;
    printf("\n real rez je %lf", rez);





return 0;
}*/



/*int main() {

int n, i;
    double suma=0;
    printf("Koliko redova: ");
    scanf("%d", &n);
    for(i=1; i<n; i++) {
            suma += 1.0/(i*(i+1)*(i+2));

    }

     printf("Suma redova je %lf\n", suma);
    double rez;
    rez = 1.0/4.0;
    printf("\n real rez je %lf", rez);




return 0;
}*/




/*int main()
{
    int n, i;
    double suma=1;
    long int fact=1;
    float x;
    printf("koliko da bude x: ");
    scanf("%f", &x);
    printf("Koliko clanova reda zelite: ");
    scanf("%d", &n);
    for(i=1; i<n; i++) {

        suma += pow(x,i)/fact;
        fact *= (i+1);
    }
printf("\nSuma reda je: %lf", suma);
printf("\nRealna vrednost je: %lf", pow(M_E,x));

   return 0;
}*/



