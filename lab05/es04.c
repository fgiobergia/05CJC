#include <stdio.h>
#include <string.h>
#include <unistd.h>

pid_t mask, bro;
int c;

void *handle(int s) {
	if (s==10) {
		mask = 0;
	}
	else if(s==12) {
		mask = 1;
	}
	else if (s==1) {
		bro |= (mask<<c);
		c++;
	}
	return NULL;
}

void *wake(int s) {
	return NULL;
}

int main () {
	pid_t pid,p;
	int i;
	char line[128];
	FILE *fp;
	if (pid=fork()) {
		if (fork()) {
			pause(); // padre, abbandona
		}
		p = getpid();
		usleep(50);
		signal(10,wake);
		for (i=0;i<32;i++) {
			kill (pid,p&(1<<i)?12:10);
			kill (pid,1);
			usleep(50);
		}
		// pid comunicato!
		while(fgets(line,sizeof(line),stdin)) {
			fp=fopen("pipe","w");
			fputs(line,fp);
			fclose(fp);
			kill(pid,10);
			if (!strncmp(line,"end",3)) {
				kill(getppid(),9); // dadslayer
				return 0;
			}
			pause();
		}
	}
	else {
		// figlio 1, aspetta pid
		signal(10,handle);
		signal(12,handle);
		signal(1,handle);
		while (c!=32) {
			pause();
		}
		signal(10,wake);
		while (1) {
			pause();
			fp=fopen("pipe","r");
			fgets(line,sizeof(line),fp);
			if(!strncmp(line,"end",3)) {
				return 0;
			}
			for(i=0;i<strlen(line);i++) {
				printf("%c",toupper(line[i]));
			}
			kill(bro,10);
		}
		// pid ricevuto(bro)
	}
	return 0;
}
