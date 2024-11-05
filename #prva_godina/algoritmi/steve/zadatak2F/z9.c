/*
9.	Napisati program koji će sabrati dve matrice dimenzije MxN. U glavnom programu treba učitati vrednosti oba 2D niza, pozvati funkciju i ispisati elemente .
*/
#include <stdio.h>
#include <stdlib.h>

int randRange(int, int);
void setNumberRange(int *, char, int, int);
int additionMatrix(int, int columns, int arr1[][columns], int arr2[][columns], int arrResult[][columns]);

int main() {
    srand(time(0));

    int n, m;
    setNumberRange(&n, 'n', 1, 50);
    setNumberRange(&m, 'm', 1, 50);

    int arrOne[n][m];
    int arrTwo[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arrOne[i][j] = randRange(0, 100);
            arrTwo[i][j] = randRange(0, 100);
        }
    }

    int arrResult[n][m];

    additionMatrix(n, m, arrOne, arrTwo, arrResult);

    return 0;
}

int additionMatrix(int rows, int columns, int arr1[][columns], int arr2[][columns], int arrResult[][columns]) {
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++) {
            arrResult[row][col] = arr1[row][col] + arr2[row][col];
        }
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