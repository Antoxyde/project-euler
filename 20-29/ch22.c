#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int split(char *str, char delimiter, char ***tab) {
	int count = 1;
	int i = 0;
	int tok_len = 1;

	char *tok;
	char *str_temp;

	//while ((tok = strsep(&str, delimiter))) count++;

	str_temp = str;
	while(*str_temp != '\0') {
		if (*str_temp == delimiter)
				count ++;
		str_temp++;
	}


	*tab= (char**)malloc(sizeof(char*) * count); //Malloc tab

	if (*tab == NULL) {
		printf("Failed to malloc the tab.\n");
		exit(1);
	}


	str_temp = str;
	while (*str_temp != '\0') { //While we are'nt at the end of the long names string.
		if (*str_temp == delimiter) {
			(*tab)[i] = (char*) malloc(sizeof(char) * tok_len); //Mallocs in the tab

			if ((*tab)[i] == NULL) {
                printf("Failed to malloc in the tab.\n");
            	exit(1);
            }
            tok_len = 0;
            i++;
		}
		str_temp++;
		tok_len++;
	}

	(*tab)[i] = (char*) malloc(sizeof(char) *tok_len); //Malloc the last one cuz the while stop before doing it

	if ((*tab)[i] == NULL) {
        printf("Failed to malloc in the tab.\n");
        exit(1);
    }

    i = 0; //Starting again at the start of the tab
    str_temp = str;
    tok = ((*tab)[i]);

    while (*str_temp != '\0') {
    	if (*str_temp != delimiter && *str_temp != '\0') {
    		*tok = *str_temp;
    		tok++;
    	} else {
    		*tok = '\0';
    		i++;
    		tok = ((*tab)[i]);
    	}
    	str_temp++;
    }
    return count;
}


void chomp(char *str, char nope) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != nope) dst++;
    }
    *dst = '\0';
}

int compare (const void * a, const void * b) {
	return strcmp (*(const char **) a, *(const char **) b);
}


unsigned long sum_letters(char *s) {
	unsigned long count = 0;
	while(*s != '\0') {
		count += (char)*s - 64;
		s++;
	}
	return count;
}

int main() {
	FILE *fp;
	int count = 0;
	char **tab = NULL;

	fp = fopen("p022_names.txt", "r");

	if (fp == NULL) {
		printf("Impossible to open the file.\n");
		exit(1);
	}

	fseek(fp, 0, SEEK_END); //Reach then end of the file
	int size = ftell(fp); //get current position in the stream
	rewind(fp); //replace fp at the start of the file

	unsigned char *content = (unsigned char*) malloc(sizeof(char) * size);
	fread(content, 1, size, fp);
	content[size] = '\0';
	fclose(fp);
	chomp(content, '"');
	//printf("Chomped : %s", content);


	int c = split(content, ',', &tab);
	//char *test = "une string de test.";
	//int c = split(test, ' ', &tab);
	printf("Found %d tokens.\n", c);

	qsort (tab, c, sizeof (const char *), compare); //To implement

	unsigned long total = 0;
	for (int i = 0; i < c; i++) {
		total += sum_letters(tab[i]) * (i+1);
	}

	printf("Result : %lu", total);


	free(content);
	return 0;
}
