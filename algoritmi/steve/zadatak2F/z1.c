/*
1. Napisati program koji za uneti broj n (1 ≤ n ≤ 50) učitava niz od n realnih brojeva. Naći minimalni element niza i upisati ga kao novi član na početak niza.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void displayArray(float arr[], int);
void placeNumberToArr(float arr[], int, float, int);
float getMinNumber(float arr[], int);

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
    
    float minNumber = getMinNumber(arr, n);
    placeNumberToArr(arr, n++, minNumber, 0);

    displayArray(arr, n);

    return 0;
}
float getMinNumber(float arr[], int n) {
    float min = arr[0];
    for(int i = 0; i < n; i++) {
        if(min > arr[i])
            min = arr[i];
    }
    return min;
}


void displayArray(float arr[], int n) {
    printf("Display array: \n");
    for(int i = 0; i < n; i++) {
        printf("array[%d]: %.2f\n", i, arr[i]);
    }
    printf("END\n\n"); 
}
void placeNumberToArr(float arr[], int n, float newNumber, int position) {
    for(int i = n; i >= position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = newNumber;
}