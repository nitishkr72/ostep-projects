#include <stdio.h>

#define BUFF_MAXLEN 100

int main(int argc, char const *argv[]) {
	
	if(argc < 1)
		return 0;
	else {
		int i=1;
		while (argv[i] != NULL) {
			FILE * fp;
			if((fp = fopen(argv[i], "r")) == NULL){
				printf("wcat: cannot open file\n");
				return 1;
			}

			char buff[BUFF_MAXLEN];
			while(fgets(buff, BUFF_MAXLEN, fp) != NULL){
				printf("%s", buff);
			}
			fclose(fp);
			i++;
		}
	}
	return 0;
}