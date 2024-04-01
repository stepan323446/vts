/*
2.  Napisati program koji učitava niz od n realnih brojeva (1 ≤ n ≤ 50). Naći najveći element niza, a onda svako njegovo pojavljivanje u nizu zameniti k puta većim brojem, gde je k vrednost koju korisnik zadaje.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void displayArray(float arr[], int);
void replaceNumber(float arr[], int, float, float);
float getMaxNumber(float arr[], int);

int main() {
    
    float arr[MAX];
    
    // Enter and check n number
    int n;
    do {
        printf("Enter n number (1 <= n <= 50): ");
        scanf("%d", &n);

        if(n > 50 || n < 1)
            printf("Your number is invalid\n");
        else
            break;
    }
    while (1);
    
    // Enter n numbers to arr
    for(int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%f", &arr[i]);
    }
    
    float maxNumber = getMaxNumber(arr, n);
    
    // Replace max number on max*k
    float k;
    printf("Enter k number: ");
    scanf("%f", &k);

    replaceNumber(arr, n, maxNumber, maxNumber * k);

    displayArray(arr, n);

    return 0;
}
float getMaxNumber(float arr[], int n) {
    float max = arr[0];
    for(int i = 0; i < n; i++) {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}


void displayArray(float arr[], int n) {
    printf("Display array: \n");
    for(int i = 0; i < n; i++) {
        printf("array[%d]: %.2f\n", i, arr[i]);
    }
    printf("END\n\n"); 
}
void replaceNumber(float arr[], int n, float oldNumber, float newNumber) {
    for(int i = 0; i < n; i++) {
        if(oldNumber == arr[i])
            arr[i] = newNumber;
    }
}