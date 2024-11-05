/*
6.	Napisati funkciju kojom se računaju aritmetičke sredine kolona nekog 2D realnog niza od M x N članova. U glavnom programu treba učitati elemente 2D niza, pozvati funkciju, te ispisati dobijene rezultate.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randRange(int, int);
void setNumberRange(int *, char, int, int);
void printMedianColumnArray(int, int columns, int arr[][columns]);

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

    printMedianColumnArray(n, m, arr);

    return 0;
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
void printMedianColumnArray(int rows, int columns, int arr[][columns]) {
    for(int col = 0; col < columns; col++) {
        double median;
        if(rows % 2 == 0) {
            median = arr[rows / 2][col] + arr[rows / 2 - 1][col] / 2.0;
        }
        else {
            median = (double)arr[rows/2][col];
        }
        printf("Column %d: %.2f\n", col, median);
    }
    
}