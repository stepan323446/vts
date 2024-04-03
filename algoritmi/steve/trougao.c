#include <stdio.h>
#include <stdlib.h>

void printTrougao(int);
void printPraviTrougao(int);
void printTrougaoBySide(int);

int main() 
{
    int size;
    printf("Enter size trougao: ");
    scanf("%d", &size);

    
    printPraviTrougao(size);
    printTrougao(size);
    printTrougaoBySide(size);
}
/*
 ===========
     *
    * *
   * * *
  * * * *
 * * * * *
 ===========
    */
void printTrougao(int size) {
    printf("\n======== Trougao ========\n");
    for(int lineWidth = size; lineWidth > 0; lineWidth--) {
        // Place empty width
        printf("%*s", lineWidth - 1, "");

        // Trougao with
        for(int width = 1; width <= (size - lineWidth + 1); width++) {
            printf("%*c", 2, '*');
        }
        // New line
        printf("\n");
    }
    /*
    Za više informacije šta je *:
    https://www.quora.com/In-the-printf-statement-what-is-the-meaning-of-an-asterisk-before-the-s-format-specifier
    */
}
/*
 ===========
 *
 * *
 * * *
 * * * *
 * * * * *
 ===========
 */
void printPraviTrougao(int size) {
    printf("\n======== Pravi trougao ========\n");

    for(int lineWidth = size; lineWidth > 0; lineWidth--) {

        // Trougao with
        for(int width = 1; width <= (size - lineWidth + 1); width++) {
            printf("%*c", 2, '*');
        }
        // New line
        printf("\n");
    }
}
/*
 ===========
 *
 * *
 * * *
 * * * *
 * * * * *
 * * * *
 * * *
 * *
 * 
 ===========
 */
void printTrougaoBySide(int size) {
    printf("\n======== Trougao by side ========\n");\

    for(int lineWidth = size; lineWidth > 0; lineWidth--) {

        // Trougao with
        for(int width = 1; width <= (size - lineWidth + 1); width++) {
            printf("%*c", 2, '*');
        }
        // New line
        printf("\n");
    }
    for(int lineWidth = size; lineWidth > 0; lineWidth--) {

        // Trougao with
        for(int width = (lineWidth - 1); width >= 1; width--) {
            printf("%*c", 2, '*');
        }
        // New line
        printf("\n");
    }
}