#include <stdio.h>
#include <string.h>

unsigned long long fac(unsigned long long n){
    if (n <= 1)
           return 1;
    return (n * fac(n-1));
}

int main() {
        char str_num[30];
        long total = 0;
        for (unsigned long long i=10; i<=2000000; ++i){
            sprintf(str_num, "%llu", i);
            //printf("Str num  : %s\n", str_num);
            unsigned long long sum = 0;
            for (unsigned long long j = 0; j < strlen(str_num); j++) {
                unsigned long long  f = fac(str_num[j] - '0');
                //printf("fac(%c) = %lu\n", str_num[j], f);
                sum += f;
            }
            
            if (i == sum) {
                printf("%llu - %llu\n", i,sum);
                total += sum;
            }
        }

        printf("Result is %lu", total);

       return 0;
}
