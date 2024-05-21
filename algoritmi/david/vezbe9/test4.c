#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,k;
    int n=5;
    int num=0;
    char alphabet[]={'A', 'B', 'C', 'D', 'E', 'F'};


    for(i=1; i<=n; i++){
        for(j=1; j<=n-i; j++)
        printf(" ");

        for(k=1; k<=i; k++){
        printf("%c ", alphabet[num]);
        }
        num++;
        printf("\n");
    }

num=n-2;
for(i=1; i<n; i++){
    for(j=1; j<=i; j++)
    printf(" ");


    for(k=1; k<=n-i; k++)
    printf("%c ", alphabet[num]);

    --num;
    printf("\n");



}
    return 0;
}