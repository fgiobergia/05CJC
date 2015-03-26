#include <stdio.h>
#include <string.h>

int main () {
	int fd[2],len,i;
	char line[128];
	pipe(fd);
	if (fork()) {
		// scrive in pipe
		close(fd[0]);
		while(fgets(line,sizeof(line),stdin)) {
			len=strlen(line);
			write(fd[1],&len,sizeof(int));
			write(fd[1],line,len);
			if (!strncmp(line,"end",3)) {
				close(fd[1]);
				return 0;
			}
		}
	}
	else {
		close(fd[1]);
		while (1) {
			read(fd[0],&len,sizeof(int));
			read(fd[0],line,len);
			if(!strncmp(line,"end",3)) {
				close(fd[0]);
				return 0;
			}
			for(i=0;i<len;i++) {
				printf("%c",toupper(line[i]));
			}
		}

	}
	return 0;
}
