#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
	FILE *fp;
	char line[128];
	if (argc<2) {
		return 0;
	}
	fp=fopen(argv[1],"r");
	while (fgets(line,sizeof(line),fp)) {
		line[strlen(line)-1] = 0;
		system(line);
	}
	fclose(fp);
	return 0;
}

