#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int);
double zadatak1(int, double *);
double zadatak2(int, double *);
double zadatak3(int, double *);
double zadatak4(int, double *);
double zadatak5(int, double *);

int main() 
{
    int numberInput;
    printf("Place number: ");
    scanf("%d", &numberInput);

    double stvarni_broj;
    double result = zadatak5(numberInput, &stvarni_broj);

    printf("Suma reda: %f\n", result);
    printf("Stvarni broj: %f\n", stvarni_broj);

    return 0;
}
int factorial(int n) {
    int res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}
double zadatak1(int n, double *stvarni_broj) {
    double e = 1;
    for(int i = 1; i <= n; i++) {
        e += pow(factorial(i), -1);
        printf("1/%d\n", factorial(i));

    }
    *stvarni_broj = M_E;
    return e;
}
double zadatak2(int n, double *stvarni_broj) {
    double e = 1;
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            printf("+1/%d\n", factorial(i));
            e += pow(factorial(i), -1);
        }
        else {
            printf("-1/%d\n", factorial(i));
            e -= pow(factorial(i), -1); 
        }
    }
    *stvarni_broj = 1/M_E;
    return e;
}
double zadatak3(int n, double *stvarni_broj) {
    double result = 0;
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            printf("-1/%d\n", i);
            result -= pow(i, -1);
        }
        else {
            printf("+1/%d\n", i);
            result += pow(i, -1); 
        }
    }

    *stvarni_broj = log(2);
    return result;
}
double zadatak4(int n, double *stvarni_broj) {
    double result = 0;
    
    int isPositive = 1;
    for(int i = 1; i <= n; i++) {
        int formula = 2*i - 1;
        if(isPositive) {
            printf("+1/%d\n", i);
            result += pow(formula, -1);

            isPositive = 0;
        }
        else {
            printf("-1/%d\n", i);
            result -= pow(formula, -1);

            isPositive = 1; 
        }
    }

    *stvarni_broj = M_PI / 4;
    return result;
}

double zadatak5(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 1; i <= n; i++) {
        int formula = (4*i - 1)*(4*i + 1);
        result += pow(formula, -1);
    }

    *stvarni_broj = (4 - M_PI) / 8;
    return result;
}