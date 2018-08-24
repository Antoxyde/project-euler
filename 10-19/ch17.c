#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_to_hundred(int s) {
	switch (s) {
		case 100:
			return "onehundred";
			break;
		case 200:
			return "twohundred";
			break;
		case 300:
			return "threehundred";
			break;
		case 400:
			return "fourhundred";
			break;
		case 500:
			return "fivehundred";
			break;
		case 600:
			return "sixhundred";
			break;
		case 700:
			return "sevenhundred";
			break;
		case 800:
			return "eighthundred";
			break;
		case 900:
			return "ninehundred";
			break;
		default:
			return "";
			break;
	}
}

char *string_to_tenth(int s) {
	switch (s) {
		case 10:
			return "ten";
			break;
		case 11:
			return "eleven";
			break;
		case 12:
			return "twelve";
			break;
		case 13:
			return "thirteen";
			break;
		case 14:
			return "fourteen";
			break;
		case 15:
			return "fifteen";
			break;
		case 16:
			return "sixteen";
			break;
		case 17:
			return "seventeen";
			break;
		case 18:
			return "eighteen";
			break;
		case 19:
			return "nineteen";
			break;
		default:
			return "";
			break;
	}
}

char *string_to_dozen(int s) {
	switch (s) {
		case 10:
			return string_to_tenth(s);
			break;
		case 20:
			return "twenty";
			break;
		case 30:
			return "thirty";
			break;
		case 40:
			return "forty";
			break;
		case 50:
			return "fifty";
			break;
		case 60:
			return "sixty";
			break;
		case 70:
			return "seventy";
			break;
		case 80:
			return "eighty";
			break;
		case 90:
			return "ninety";
			break;
		default:
			return "";
			break;
	}
}

char *string_to_digit(int s) {
	switch (s) {
		case 1:
			return "one";
			break;
		case 2:
			return "two";
			break;
		case 3:
			return "three";
			break;
		case 4:
			return "four";
			break;
		case 5:
			return "five";
			break;
		case 6:
			return "six";
			break;
		case 7:
			return "seven";
			break;
		case 8:
			return "eight";
			break;
		case 9:
			return "nine";
			break;
		default:
			return "";
			break;
	}
}

char *string_to_keyword(int i) {
	char *res = malloc(50);
	if (i < 10) {
		res = string_to_digit(i);
	} else if (i < 20) {
		res = string_to_tenth(i);
	} else if (i < 100) {
		strcat(res,string_to_dozen(i - (i%10)));
		strcat(res,string_to_digit(i%10));
	} else {
		strcat(res, string_to_hundred(i - (i%100)));
		if (i%100 != 0) {
			strcat(res, "and");
		}
		if ((i%100) >= 10 && (i%100) < 20) {
			strcat(res, string_to_tenth(i%100));
		} else if (i < 1000){
			strcat(res,string_to_dozen((i%100) - i%10));
			strcat(res,string_to_digit(i%10));
		} else {
			res = "onethousand";
		}

	}
	return res;
}


int main() {
	int count = 0;
	for (int i = 1; i <= 1000; i++) {
		char s[50];
		strcpy(s, string_to_keyword(i));

		printf("[+] %d - %s\n", i, s);
		count += strlen(s);
	}
	printf("Result : %d", count);


}
