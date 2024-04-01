/*
5.	Napisati funkciju kojom se izračunavaju aritmetičke sredine redova nekog 2D realnog niza od M x N članova. U glavnom programu treba učitati elemente 2D niza, pozvati funkciju (ulazni parametar je matrica), te ispisati dobijene rezultate.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randRange(int, int);
double medianArray(int arr[], int);
void printMedianArrayMatrix(int, int columns, int arr[][columns]);
void setNumberRange(int *, char, int, int);


int main() {

    srand(time(0));

    int n, m;
    setNumberRange(&n, 'n', 1, 50);
    setNumberRange(&m, 'm', 1, 50);

    int arr[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = randRange(0, 100);
        }
    }

    printMedianArrayMatrix(n, m, arr);
    
    return 0;
}
void printMedianArrayMatrix(int rows, int columns, int arr[][columns]) {
    for(int i = 0; i < rows; i++) {
        double mediam = medianArray(arr[i], columns);
        printf("Medium for row %d: %.2f\n", i + 1, mediam);
    }
}

int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void setNumberRange(int *num, char letter, int min, int max) {
    do {
        printf("Enter %c number (%d <= %c <= %d): ", letter, min, letter, max);
        scanf("%d", num);

        if(*num > max || *num < min)
            printf("Your number is invalid\n", *num);
        else
            break;
    }
    while (1);
}
double medianArray(int arr[], int n) {
    if(n % 2 == 0) {
        return arr[n / 2] + arr[n / 2 - 1] / 2.0;
    }
    else {
        return (double)arr[n/2];
    }
}