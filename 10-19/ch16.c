#include <stdio.h>
#include <gmp.h>
#include <string.h>



int main() {
	char *big_num_str ;
	int count = 0;
	unsigned int base = 2;
	unsigned int expo = 1000;

	mpz_t big_num;
	mpz_init(big_num);

	mpz_ui_pow_ui(big_num, base, expo);
	big_num_str = mpz_get_str(big_num_str, 10, big_num);
	printf("Big num is %s !\n", big_num_str);

	
	for (size_t i = 0; big_num_str[i] ; i++) {
		count += big_num_str[i] - 48;
	}
	
	printf("Result : %d\n", count);
	return 0;
}
