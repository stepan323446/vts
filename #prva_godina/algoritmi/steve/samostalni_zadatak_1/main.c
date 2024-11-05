/*
1. Napisati program koji će učitati brojeve iz data1.txt fajla. Taj program koristi sledeće funkcije:
-	readFile učitava brojeve iz fajla u niz,
-	printNums ispisuje brojeve na ekran, na sledeći način: brojevi su razdvojeni zarezom (znakom “, ”), u jednom redu se ispisuje samo 5 brojeva i cifre brojeva su razdvojene “_” znakom. Na primer, brojevi 12, 15, 13, 19 se ispisuju na sledeći način: 1_2,  1_5,  1_3,  1_9, 
-	countNums ispisuje za svaki broj posebno koliko pute se pojavio u nizu
-	sortNums: bubble-sort metodom sortirati u opadajućem redosledu brojeve)
-	deleteNums: učitava broj n sa tastature iz opsega [0, N-1], gde je N broj elemenata u nizu (onoliko koliko ste učitali iz fajla data1.txt). Funkcija briše element na n-toj lokaciji, a ostale elemente pomera.
-	readFile: učitava brojeve iz fajla u matricu dimenzije 5x5 
-	rotateNums: zamenjuje redove sa kolonama u matrici. Prvi red postaje prva kolona, drugi red druga kolona itd. )
-	calcNums ispisuje :
o	zbir elemenata ispod sporedne dijagonale
o	proizvod elemenata iznad glavne dijagonale
-	minDiff: ova funkcija ispisuje ona dva broja čija je razlika najmanja 
-	U main funkciji testirajte vaše podprograme : 
o	readFile(…)
o	printNums(…) 
o	countNums(…)
o	printNums(…) 

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readFile(int *arr, int *length) {
    FILE *fp = fopen("data1.txt", "r");
    char ch;

    if(fp) {
        char *num;
        for(int i = 0; fscanf(fp, "%d", &arr[i]) != EOF; i++) {
            (*length)++;
        }
    }

    fclose(fp);
}
int getDecimalCounts(int num) {
    int res = 0;
    int otherDecimalResults = 0;

    int checkDecimal = num / 10;
    if(checkDecimal > 0)
        res++;

    if(checkDecimal > 9) {
        otherDecimalResults = getDecimalCounts(checkDecimal);
    }
    res = res + otherDecimalResults;

    return res;
}
void printNums(int *arr, int length) {
    const int rowMax = 5;
    int rowCurrent = rowMax;
    for(int i = 0; i < length; i++) {
        int decimalCounts = getDecimalCounts(arr[i]);
        if(decimalCounts == 0) {
            printf("%d", arr[i]);
        } else {
            int currentNumber = arr[i];
            for(int dec = decimalCounts; dec >= 0; dec--) {
                // get 1000, 100, 10
                int decimalCheck = pow(10, dec);
                // Ako to je cifra 0 <= dec <= 9
                if(dec == 0) {
                    printf("%d", currentNumber);
                } else
                {
                    // Dobimo broj u decimala
                    // 212
                    // numberDecimal = 212 / 100 = 2
                    int numberDecimal = currentNumber / decimalCheck;
                    printf("%d", numberDecimal);
                    // Stavimo u current number 12 i dalece proveravamo 12
                    currentNumber -= decimalCheck * numberDecimal;
                }

                // na kraju ne treba dodati _
                if(dec != 0)
                    printf("_");
            }
        }

        // Divided on ", ", but last element don't use it and last element in row same
        if(i != length - 1 && rowCurrent != 1) {
            printf(", ");
        }
        rowCurrent--;
        if(rowCurrent < 1) {
            printf("\n");
            rowCurrent = rowMax;
        }
    }
}
void countNums(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        if(arr[i] == -1)
            continue;
        
        int counter = 0;
        // Gledamo svaki broj od pocetka novog brojeva
        for(int j = i; j < length; j++) {
            if(arr[i] != arr[j])
                continue;
            
            counter++;
            // Dabi ne ponavljati isti broj
            if(counter > 1)
                arr[j] = -1;
        }
        printf("Number %d: %d\n", arr[i], counter);
    }   
}
int main() {
    int arr[100];
    int length = 0;
    readFile(arr, &length);
    printNums(arr, length);
    printf("\n");
    countNums(arr, length);
    printf("\n");

    return 0;
}