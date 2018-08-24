#include <stdio.h>
#include <stdlib.h>

int main() {
	int i = 20;
	while (1) {
		if (i%11==0 && i%12==0 && i%13==0 && i%14==0 && i%15==0 && i%16==0 && i%17==0 && i%18==0 && i%19==0 ) {
			printf("%d", i);
			break;
		} else {
			i += 20;
		}
	}
}
