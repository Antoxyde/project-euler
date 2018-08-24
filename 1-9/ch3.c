#include <stdio.h>
#include <stdlib.h>

int main() {
	long n = 600851475143;
	int f = 3;
	while (n > 1) {
		if (n % f == 0) {
		  n /= f;
		} else {
		  f += 2;
		}
	}
	printf("%d", f);
	return 0;
}
