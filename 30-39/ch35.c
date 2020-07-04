#include <stdio.h>
#include <math.h>

int is_prime(int n) {

    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i < ((int)sqrt(n)) + 1; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int rotate(int n) {
    return n/10 + n%10 * pow(10, floor(log10(n)) );
}

int is_circle_prime(int n) {

    int nrotation = ceil(log10(n));

    for (int i = 0; i < nrotation ; i++) {

        if (!is_prime(n)) {
            return 0;
        }

        n = rotate(n);
    }

    return 1;
}


int main(void) {

    for (int i = 2; i < 1000000; i++) {
        if (is_circle_prime(i)) {
            printf("%d is circle-prime.\n", i);
        }
    }

    return 0;
}

