#include <stdio.h>
#include <stdbool.h>

bool is_leap(int years) {
	return (years%4 == 0 || (years%100 == 0 && years%400 == 0));
}


int main() {
	int count = 6, years = 1900, months = 1, days = 1, sundayz_first = 0;
	//We are in january if months%12 == 0, etc
	//It's a leap years if (years%4 == 0 && (years%100 -! 0 || years%400 = 0))
	//february have 28 days, 29 on leazp years
	//april, june september and november have 30 days
	//others have 31 days

	while (years < 2000) { //While we are'nt at 2000
		
		

		if (years >= 1901 && days == 1  && count%7 == 0) {
			sundayz_first++;
			printf("New 1st sunday on %d/%d/%d\n", days, months, years);
		}

		//days treatment
		if (months == 2 && is_leap(years)) { //leap years february
			if (days == 29) {
				printf("New 29 feb (%d).\n", years);
				days = 0;
				months++;
			} 
		} else if (months == 2) { //february
			if (days >= 28) {
				days = 0;
				months++;
			}
		} else if (months == 4 || months == 6 || months == 9 || months == 11) { //april, june, september, november
			if (days >= 30) {
				days = 0;
				months++;
			}
		} else { //others months
			if (days >= 31) {
				days = 0;
				months++;
			}
		}

		if (months > 12) {
			months = 1;
			years++;
		}

		count++;
		days++;
	}
	printf("Result : %d\n", sundayz_first);

}
