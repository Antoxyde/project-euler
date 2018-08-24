#include <stdio.h>
#include <gmp.h>


int main () {
	mpz_t arr[100];
	mpz_t sum;
	FILE *fp;
	fp = fopen("numbers.txt", "r");
	size_t len = 0;
	ssize_t read;
	char *line = NULL;

	mpz_init_set(sum,0);

	if (fp == NULL)
        fprintf(stderr, "Problem occured while opening file.\n");
    int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
    	mpz_init_set_str(arr[i], line, 10);
    	i++;
    }


    for (int i = 0; i < 100; i++) 
    	mpz_mul(sum, sum, arr[i]);

    mpz_out_str(stdout, sum, 10);

    fclose(fp);

}
