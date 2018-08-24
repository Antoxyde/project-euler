#include <stdio.h>

/*
it's basically for a nxn grid, n*2!/(n!)^²
this works only for 10 firsts grids, and i dunno why.
i've solved it with python.
*/

unsigned long long factorial(unsigned long long x) {
	if (x == 0) {
		return 1;
	} else {
		return x*factorial(x-1);
	}
}

unsigned long long paths(unsigned long long i) {
	return (factorial(2*i) / (factorial(i)*factorial(i)));
}


int main() {
  for (unsigned long long i = 0; i <= 20 ; i++) 
	  printf("In a %llux%llu grid , there is %llu lattice paths.\n",i,i, paths(i));

	return 0;
}
