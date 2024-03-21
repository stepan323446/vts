#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int checkArrayVal(int arr[], int, int);

int main() {
    int array1[5] = {1, 3, 7, 10, 12};

    int n;
    printf("Enter your value: ");
    scanf("%d", &n);
    int res = checkArrayVal(array1, 5, n);

    printf("Result is %d\n", res);

    return 0;
}

int checkArrayVal(int arr[], int size, int value) {

    for (int i = 0; i < size; i++) {
        
        if(arr[i] == value)
            return 1;
    }
    return 0;
    
}
