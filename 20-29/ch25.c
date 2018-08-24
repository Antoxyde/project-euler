#include <stdio.h>
#include <gmp.h>
#include <string.h>


int main() {

	mpz_t fibo;
	mpz_init_set_ui(fibo,0);
	char tab[1001];
	char *res = &tab;
	int i = 1;

	while (strlen(res) < 1000) {
		i++;
		mpz_fib_ui(fibo, i);
		res = mpz_get_str(res, 10,fibo);
		printf("%s\n", res);
	}

	printf("Result : fibo(%d) == %s\n",i,res);
	return 0;
}
