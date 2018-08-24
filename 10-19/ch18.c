#include <stdio.h>

/*
last row is 2*n - 2
i = lines
j = columns




   a
  b c
 d e f
g h i j

=>

(g.h)d (h.i)e (i.j)f
*/


int max(int a,int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int main() {

	int tab[15][15] = {	
		{75,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{95, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{17, 47, 82,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{18, 35, 87, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{20,  4, 82, 47, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{19,  1, 23, 75,  3, 34,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{88,  2, 77, 73,  7, 63, 67,  0,  0,  0,  0,  0,  0,  0,  0},
		{99, 65,  4, 28,  6, 16, 70, 92,  0,  0,  0,  0,  0,  0,  0},
		{41, 41, 26, 56, 83, 40, 80, 70, 33,  0,  0,  0,  0,  0,  0},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29,  0,  0,  0,  0,  0},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,  0,  0,  0,  0},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,  0,  0,  0},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,  0,  0},
		{63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,  0},
		{ 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
	};

	
	/*
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			printf("%d\n", tab[i][j]);
		}
	}
	*/
	
	int res[28][15] = {};
	
	


	int a,b;
	//build last row
	int i =13;
	for (int j = 0; j <= i; j++) { //foreach member of this line
		a = tab[i+1][j];
		b = tab[i+1][j+1];
		res[i][j] = tab[i][j] + max(a,b);
	}

	printf("Row %d built : \n",i);
	for (int k = 0; k <= i; k++) {
		printf(" %d ", res[i][k]);
	}
	printf("\n");

	for (int i = 12; i >= 0; i--) { //Start at the n-2 line
		for (int j = 0; j <= i; j++) { 
			a = res[i+1][j];
			b = res[i+1][j+1];
			res[i][j] = tab[i][j] + max(a,b);
			printf("%d + %d = %d\n",tab[i][j],max(a,b),res[i][j]);
		}

		printf("Row %d built : \n",i);
		for (int k = 0; k <= i; k++) {
			printf(" %d ", res[i][k]);
		}
		printf("\n");
	}
	return 0;
}
	//create last row
	/*
	int i = 14;
	for (int j = 0,  k = 0; j <= i; j++ , k += 2) {
		if (j == 0) {
				 	//printf("J - %d - I - %d\n", j, i);
			res[i][k] = tab[i][j] + tab[i][j-1]; //last on the left
			printf("[First]Lines %d - %d*%d == %d\n", i,tab[i][j], tab[i-1][j], res[i][k]);
	 	
		} else if (j == i) {
				 	//printf("J - %d - I - %d\n", j, i); 	
			res[i][k] = tab[i][j] + tab[i-1][j-1]; //last on the right
			printf("[Last]Lines %d - %d*%d == %d\n", i,tab[i][j], tab[i-1][j-1], res[i][k]);
					
		} else {
				 	//printf("J - %d - I - %d\n", j, i);	
			res[i][k+1] = tab[i][j] + tab[i-1][j-1];
			printf("Lines %d - %d*%d == %d\n", i,tab[i][j], tab[i-1][j-1], res[i][k+1]);
			res[i][k] = tab[i][j] * tab[i][j-1]; //middles
			printf("Lines %d - %d*%d == %d\n", i,tab[i][j], tab[i-1][j], res[i][k]);
					
		}

	}

	for (int i = 13; i > 0; i--) {

		for (int j = 0,  k = 0; j <= i; j++ , k += 2) {
			if (j == 0) {
					 	//printf("J - %d - I - %d\n", j, i);
				res[i][k] = tab[i][j] + tab[i][j-1]; //last on the left
				printf("[First]Lines %d - %d*%d == %d\n", i,tab[i][j], tab[i-1][j], res[i][k]);
		 	
			} else if (j == i) {
					 	//printf("J - %d - I - %d\n", j, i); 	
				res[i][k] = tab[i][j] + tab[i-1][j-1]; //last on the right
				printf("[Last]Lines %d - %d*%d == %d\n", i,tab[i][j], tab[i-1][j-1], res[i][k]);
						
			} else {
					 	//printf("J - %d - I - %d\n", j, i);	
				res[i][k+1] = tab[i][j] + tab[i-1][j-1];
				printf("Lines %d - %d*%d == %d\n", i,tab[i][j], tab[i-1][j-1], res[i][k+1]);
				res[i][k] = tab[i][j] + tab[i][j-1]; //middles
				printf("Lines %d - %d*%d == %d\n", i,tab[i][j], tab[i-1][j], res[i][k]);

			}

		}

	}

	/*
	for (int i = 14; i > 0; i--) {
		for (int j = 0,  k =0; j <= i; j++ , k += 2) {
			 if (j == 0) {
			 	//printf("J - %d - I - %d\n", j, i);
			 	
			 	res[k][i] = tab[j][i] * tab[j][i-1]; //last on the left
			 	printf("Lines %d - %d*%d == %d\n", i,tab[j][i], tab[j][i-1], res[k][i]);
			 	
			 } else if (j == i) {
			 	//printf("J - %d - I - %d\n", j, i);
			 	
			 	res[k][i] = tab[j][i]*tab[j-1][i-1]; //last on the right
			 	printf("Lines %d - %d*%d == %d\n", i,tab[j][i], tab[j-1][i-1], res[k][i]);
				
			 } else {
			 	//printf("J - %d - I - %d\n", j, i);
			 	
			 	res[k][i] = tab[j][i] * tab[j][i-1]; //middles
			 	printf("Lines %d - %d*%d == %d\n", i,tab[j][i], tab[j][i-1], res[k][i]);
			 	res[k+1][i] = tab[j][i]*tab[j-1][i-1];
			 	printf("Lines %d - %d*%d == %d\n", i,tab[j][i], tab[j-1][i-1], res[k+1][i]);
				
			 }
		}
	}
	


}
*/
