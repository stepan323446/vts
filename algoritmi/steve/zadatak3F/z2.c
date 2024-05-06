/*
2.	Odredite prvih 10 prostih brojeva koji se dobijaju pomoću formule p+10, gde je p takođe prost broj. 
Na primer: p=3 je prost broj, p+10=13 je prost broj koji zadovoljava uslov. p=7 je prost broj, p+10=17 je prost broj koji zadovoljava uslov.
*/

#include <stdio.h>
#include <stdlib.h>

int isPrime(int);

int main() {
    int numLength = 0;
    int p = 0;
    while(1) {
        if(isPrime(p) && isPrime(p + 10)) {
            printf("%d\n", p + 10);
            numLength++;
        }
        if(numLength >= 10)
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