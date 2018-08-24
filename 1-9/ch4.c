#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN 0

bool isPalindrome(int num){
    int j = 0, tmp, n = num;
    while (n > 0) {
        tmp = n % 10;
        j = j * 10 + tmp;
        n = n / 10;
    }
    return (num == j);
}


int main() {
    int higher = 0;
    for (int y = 999; y > MIN; y--) {
        for (int x = 999; x > MIN; x--) {
            if (isPalindrome(x*y)){
                if (x*y > higher)
                    higher = x*y;
                printf("%d : %d * %d\n", x*y, x, y);
            }
        }
    }
    printf("Higher is : %d", higher);
}
