#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int count_divisor(unsigned long a) {
	int count = 0;
	for (int i = 1; i < sqrt(a) ; i++) {
		if (a%i==0)
			count++;
	}
	return count;
}

int main() {
	unsigned long triangle = 0;
	for (int i = 1;;i++) {
		triangle += i;
		int divisors = count_divisor(triangle) * 2;
		printf("%d - Triangle number %lu as %d divisors.\n",i,triangle, divisors);
		if (divisors > 500) 
			exit(0);
		
	}
	return 0;
}
