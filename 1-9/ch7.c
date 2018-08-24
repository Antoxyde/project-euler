#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(unsigned i) {
    for (int c=2; c<=(int)sqrt(i);c++) {
        if (i%c==0) {
            return false;
        }
    }
    return true;
}

int main() {
    bool found = false;
    unsigned primes = 1;
    unsigned long long k = 3;

    for (; primes < 10002; k +=2) {
        if (isPrime(k)) {
            primes++;
            printf("%u ème prime : %llu\n", primes, k);
        }
    }
    return 0;
}
