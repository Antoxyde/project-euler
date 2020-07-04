#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int is_prime(int n) {

    if (n == 0 || n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i < ceil(sqrt(n)) + 1; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int is_truncatable_prime(int n) {
    //printf("call avec n=%d\n", n);

    if (n < 10) {
        return is_prime(n);
    }

    int log = floor(log10(n));
    int na = n, nb = n;

    for (int i = 0; i < log + 1; i++) {

        if (!is_prime(na) || !is_prime(nb)) {
            return 0;
        }


        na /= 10;
        nb = n % ((int)pow(10,i + 1));
    }
    return 1;

}

int main(void) {
    int sum = 0;
    for (int i = 11; i < 1000000; i += 2) {
        if (is_truncatable_prime(i)) {
            sum += i;
            printf("%d is truncatable prime.\n", i);
        }
    }
    printf("Result : %d\n", sum);
    return 0;
}
