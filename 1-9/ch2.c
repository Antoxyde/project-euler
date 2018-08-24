#include <stdio.h>
#include <stdlib.h>

#define MAX 4000000

int main() {
    unsigned long first = 0;
    unsigned long second = 1;
    unsigned long next;
    unsigned long sum = 0;

    for (unsigned long i = 0; i < 100; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }

        if (next >= MAX)
            break;
        if  (next%2 ==0) {
            printf("%llu\n", next);
            sum = sum + next;
        }
    }
    printf("%lu ", sum );
}
