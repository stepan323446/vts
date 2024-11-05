/*
1.	Korisnik treba da zada interval brojeva koji se posmatra i u datom intervalu naći sve one proste brojeve čija razlika je 2 (takvi prosti brojevi nazivaju se twin prime). 
Na primer: interval koji je zadat je od 25 do 80. Brojevi iz ovog intervala 29 i 31 zadovoljavaju uslov da su prosti brojevi i da je razlika između njih 2
*/
#include <stdio.h>
#include <stdlib.h>

int isPrime(int);

int main() {
    int from;
    int to;
    printf("Start number: ");
    scanf("%d", &from);
    printf("End number: ");
    scanf("%d", &to);
    
    for(int number = from; number <= to; number ++) {
        if(isPrime(number) && isPrime(number + 2)) {
            printf("(%d, %d)\n", number, number + 2);
        }
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