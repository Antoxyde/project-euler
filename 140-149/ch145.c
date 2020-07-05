#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#   define XOR_SWAP(a,b) do\
    {\
      a ^= b;\
      b ^= a;\
      a ^= b;\
    } while (0)


void inplace_reverse(char * str) {

    if (str) {
        char * end = str + strlen(str) - 1;

        while (str < end) {
            XOR_SWAP(*str, *end);
            str++;
            end--;
        }
    }

}

int is_reversible(int n) {

    if (n % 10 == 0) return 0;

    char nstr[10];
    sprintf(nstr, "%d", n);
    inplace_reverse(nstr);

    int sum = n + atoi(nstr);
    int sumsave = sum;

    for (int i = 0; sum; i++) {

        if (sum % 2 == 0) {
            return 0;
        }

        sum /= 10;
    }

    //printf("%d + %d = %d\n", n, atoi(nstr) ,sumsave);

    return 1;
}

int main(void) {
    int count = 0;
    for (int i = 1; i < 1000000000; i++) {
        if (is_reversible(i)) {
            count++;
        }

        if (i % 10000000 == 0) {
            printf("%d%%\n", i /10000000);
        }
    }

    printf("count : %d\n", count);
    return 0;
}

