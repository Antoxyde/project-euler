#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUM 1000

int square(int i) {
    return i*i;
}

bool isPythago(int a, int b, int c) {
    if (square(a)+square(b) == square(c)) {
        return true;
    }
    return false;
}

int main() {
    for (int a = 1; a < SUM/2; a++ ) {
        for (int b = 1; b < SUM/2; b++) {
            for (int c = 1; c < SUM/2; c++) {
                if (a+b+c == SUM && isPythago(a,b,c)) {
                    printf("Found one : %d, %d, %d : %d\n", a,b,c, a*b*c);
                }
            }
        }
    }
    return 0;
}
