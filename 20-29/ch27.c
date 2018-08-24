#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
    int i = 3;
    if (n <= 1 || (n%2 == 0 && n > 2)) return false;
    for (; i < floor(sqrt(n)); i++)
        if (n%i == 0) 
            return false;

    return true;
}

int get_prime_list_length(int a, int b) {
    int n = 0;
    while (is_prime(n*n+a*n+b))
        n++;
    return n+1;
}

int main(){
    int max_prime = 0,max_a = 0, max_b = 0;

    for (int a = -1000 ;a < 1000;a++) {
        for (int b = -1000 ;b <= 1000; b++) {
            int p = get_prime_list_length(a,b);
            if (p > max_prime) {
                max_prime = p;
                max_a = a;
                max_b = b;
                printf("New max prime list : a=%d, b=%d, length=%d\n", a,b,p);
            }
        }
    }
    printf("Result is %d", max_a * max_b);
    return 0;
}

