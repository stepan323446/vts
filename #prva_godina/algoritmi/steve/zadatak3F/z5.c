
/*
5.	Odredite prvih 5 prostih brojeva koji se dobijaju pomoć formule 2^p-1, gde je p takođe prost broj. Ovi brojevi poznati su pod imenom Mersenovi (Mersenne) brojevi. 
Na primer, 2^2-1=3, p=2 je prost broj, broj koji se dobija po formuli 2^p-1 je takođe prost broj.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);

int main() {
    int numLength = 0;
    int p = 0;
    while(1) {
        if(!isPrime(p)) {
            p++;
            continue;
        }
        int formula = pow(2, p) - 1;
        if(isPrime(formula)) {
            printf("%d\n", formula);
            numLength++;
        }
        if(numLength >= 5)
            break;
        
        p++;
    }
    return 0;
}
int isPrime(int num) {
    if(num == 0 || num == 1)
        return 0;
        
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}