#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

int is_abundant(int n) {
	int count = 0;
	for (int i = 1; i <= n/2; i++) {
		if (n%i == 0) {
			count += i;
		}
	}
	return count > n;
}

bool is_sum_of_abundant(int n) {
	int i = 0;
	bool found = false;
	do {
		if (is_abundant(i) && is_abundant(n-i)) {
			printf("%d is a sum of abundant !\n", n);
			found = true;
		}
		i++;
	} while (i <= n/2 && !found);
	
	return found;
}	


int main() {
	
	unsigned long count = 0;
	
	for (int i = 0; i < 28123; i++) {
		if (!is_sum_of_abundant(i)) {
			count += i;
			printf("New non abundant found : %d\n", i);
		}
			
	}

	printf("Result : %lu\n", count);
	return 0;
}
