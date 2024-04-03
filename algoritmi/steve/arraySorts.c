#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

// For example
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void displayArray(int arr[], int n) {
    printf("\n==== Output =====\n");
    printf("Elementi niza:\n");

    for (int i = 0; i < n; i++)
    {        
        printf("| %d |", arr[i]);
    }
}

// Sorts
void selectionSort(int arr[], int, int);
void bubbleSort(int arr[], int, int);

int main() {
    // Enter array
    srand(time(0));

    int arr[MAX];
    for(int i = 0; i < MAX; i++) {
        arr[i] = randRange(0, 100);
    }
    // Enter array END

    selectionSort(arr, MAX, 1);
    displayArray(arr, MAX);

    bubbleSort(arr, MAX, 0);
    displayArray(arr, MAX);

    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(int arr[], int n, int isAcsending) {
    for(int i = 0; i < n - 1; i++) {   
        int minNumberIndex = i;
        int minNumber = arr[i];

        for(int j = i; j < n; j++) {
            int isIndex = 0;

            if(minNumber > arr[j] && isAcsending)
                isIndex = 1;
            else if (minNumber < arr[j] && !isAcsending)
                isIndex = 1;
            

            if(isIndex) {
                minNumber = arr[j];
                minNumberIndex = j;
            }
        }
        swap(&arr[i], &arr[minNumberIndex]);
    }
}
void bubbleSort(int arr[], int n, int isAcsending) {
    int isReady;

    do {
        isReady = 1;
        for(int i = 0; i < n; i++) {
            // Last index
            if(i == n - 1)
                continue;

            if(arr[i] > arr[i + 1] && isAcsending == 1) {
                swap(&arr[i], &arr[i + 1]);
                isReady = 0;
            }
            else if (arr[i] < arr[i + 1] && isAcsending == 0) {
                swap(&arr[i], &arr[i + 1]);
                isReady = 0;
            }
        }
    }
    while(!isReady);
}