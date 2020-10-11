#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wgrep(const char * str, char * line) {
	int strLength = strlen(str);
	int pos = 0, state = 0;
	int currPos, prevPos;
	while (line[pos] != '\0') {
		if(line[pos] == str[state]){
			if(state == strLength-1)
				return 0;
			else if(state == 0) {
				currPos = pos;
				prevPos = pos-1;
				state++;
			} else if(currPos == prevPos + 1) {
				state++;
				currPos++;
				prevPos++;
			}
		} else {
			state = 0;
			currPos = -1;
			prevPos = -1;
		}
		pos++;
	}

	return 1;
}

int main(int argc, char const *argv[]) {
	
	FILE *fp;

	if(argc < 2) {
		printf("wgrep: searchterm [file ...]\n");
		return(1);
	}
	int i = 2;
	while(argv[i] != NULL) {
		if((fp = fopen(argv[i], "r")) == NULL) {
			printf("wgrep: cannot open file\n");
			return 1;
		}

		char *line = NULL;
		ssize_t nread;
		size_t len = 0;
		while ((nread = getline(&line, &len, fp)) != -1){
			if (wgrep(argv[1], line) == 0) {
				printf("%s", line);
			}
		}
		free(line);
		fclose(fp);
		i++;
	}

	return 0;
}