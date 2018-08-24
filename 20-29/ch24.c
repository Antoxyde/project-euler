#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//0 is useless and will always be at the start of the string
//So i start at (0)123456789 and count every time i got each numbers of "0123456789" in the string;



bool is_ok(unsigned long n) {

	char charset[11] = "0123456789";
	char num[11];
	char cat [11] = "0";
	
	snprintf(num, 12,"%lu", n);
	bool found = false;
	bool found_zero = false;

	for (int k = 0; k < 11; k++) {
		if ((char) num[k] == '0') { 
			found_zero = true;
			break;
		}
	}

	if (!found_zero) {
		strcat(cat, num);
	} else {
		strcpy(cat, num);
	}

	for (int i = 0; i < 11; i++ ) { //For every charset char
		found = false;
		for (int j = 0; j < 11; j++) {
			if ((char) charset[i] == (char) cat[j])
				found = true;
		}

		if (!found) 
			return false;
	}

	printf("New ok num : %s\n",cat);
	return true;
}

int main() {

	unsigned long num = 123456789;
	unsigned long count = 0;
	
	while (count < 1000000) {
		if (is_ok(num)) {
			count++;
			printf("%lu - ", count);
		}
		num++;
		
	}

	 printf("Result : %lu\n", num-1);

	return 0;
}
