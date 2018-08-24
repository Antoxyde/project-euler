#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int main() {
    unsigned squaresum=0, sumsquare=0,k;

    for (k=1; k <= MAX; k++){
        squaresum += k*k;
        sumsquare += k;
    }

    printf("Squaresum : %u, Sumsquare : %u\n", squaresum, sumsquare);
    printf("%u", (sumsquare*sumsquare)-squaresum);
    return 0;
}
