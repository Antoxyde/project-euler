#include <stdio.h>
#include <stdlib.h>

#define max 1000
int main() {
    int sum = 0;
    for (int i = 0; i < max; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum = sum + i;
        }
    }
    printf("Res id : %d", sum);
}
