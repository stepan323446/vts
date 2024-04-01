/*
7.	Napisati funkciju kojom se pronalaze indeksi najmanjih članova u pojedinim kolonama nekog 2D realnog niza od M x N članova. U glavnom programu treba učitati vrednosti 2D niza, pozvati funkciju, te ispisati dobijeni rezultat.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randRange(int, int);
void setNumberRange(int *, char, int, int);
void printMinIndexNumsForColumn(int, int columns, int arr[][columns]);

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
    printMinIndexNumsForColumn(n, m, arr);

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

void printMinIndexNumsForColumn(int rows, int columns, int arr[][columns]) {
    for(int col = 0; col < columns; col++) {
        int indexRow = 0;
        int minNum = arr[indexRow][col];

        for(int row = 0; row < rows; row++) {
            if(minNum > arr[row][col]) {
                indexRow = row;
                minNum = arr[row][col];
            }    
        }
        printf("In column %d, min number in row index %d. Full address [%d, %d]\n", col, indexRow, indexRow, col);
    }
}