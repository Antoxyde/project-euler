#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 2000000

bool isPrime(int i) {
    for (int c = 2; c <= (int)sqrt(i) ; c++) {
        if (i%c == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    unsigned long long  sum = 2;
    for (int i = 3; i < MAX; i+=2) {
        if (isPrime(i))
            sum += i;
    }

    printf("Total : %llu" , sum);

    return 0;
}
