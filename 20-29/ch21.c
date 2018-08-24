#include <stdio.h>
#include <math.h>


int get_sum_of_divisors(int a) {
	int count = 0;
	for (int i = 1; i < a; i++) {
		if (a%i == 0) {
			//printf("New divisor for %d : %d\n", a, i);
			count += i;
		}
	}
	return count;
}

int main() {
	int a,b,count = 0;
	for (int i = 1; i < 10000; i++) {
		a = get_sum_of_divisors(i);

		//printf("%i - %d got %d and %d got %d\n", i,a,b,b,a);

		if (i == get_sum_of_divisors(a) && a != i) {
			printf("New amicale nb : %d with %d\n", i, a);
			count += i;
		}
	}
	printf("Result : %d", count);
}

