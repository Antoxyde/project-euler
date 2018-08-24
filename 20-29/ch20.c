#include <stdio.h>
#include <gmp.h>
#include <string.h>


int main() {

	mpz_t fac;
	mpz_init(fac);
	mpz_fac_ui(fac, 100); //100!


	char res[200];
	mpz_get_str(res, 10, fac);

	int count = 0;
	for (int i = 0; i < strlen(res); i++) {
		count += res[i] - 48;
	}

	printf("Result : %d\n", count);
	return 0;

}
