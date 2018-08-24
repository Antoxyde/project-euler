#include <stdio.h>




unsigned long count_collatz(int count, unsigned long n) {
	//printf("Collatz called with args count = %d , n = %lu\n", count, n);
	if (n==1) {
		//printf("n equal to one.\n");
		return count;
	} else if (n%2==0) {
		//printf("n is even.\n");
		count_collatz(count+1,n/2);
	} else {
		//printf("n is'nt even.\n");
		count_collatz(count+1, 3*n+1);
	}
}


int main() {
	//printf("Collatz for 13 got %lu members.\n", count_collatz(1,13));
	
	unsigned long max = 0;
	for (unsigned long i = 1000000; i > 0; i--) {
		unsigned long temp = count_collatz(1,i);
		if (temp > max) {
			max = temp;
			printf("New max : %lu members starting with %lu\n", max, i);
		}
	}
	return 0;
	
}
