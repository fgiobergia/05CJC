#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	FILE *fp;
	char cmd[128],line[128],**ptr,*p;
	int i;
	if (argc<2) {
		return 0;
	}
	fp = fopen(argv[1],"r");
	ptr=malloc(8*sizeof(char*)); // assuming 7 is the max # of args
	while (fgets(line,sizeof(line),fp)) {
		p=line;
		i=0;
		ptr[i++]=line;
		while (p=strchr(p,' ')) {
			ptr[i++]=p+1;
			*p++=0;
		}
		ptr[i-1][strlen(ptr[i-1])-1]=0;
		ptr[i]=NULL;
		if (!fork()) {
			execvp(ptr[0],ptr);
		}
		else {
			sleep(3);
		}
	}
	fclose(fp);
	return 0;
}
