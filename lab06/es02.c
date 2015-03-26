#include <stdio.h>

int main () {
	char ch;
	int fd[2][2],i;
	pipe(fd[0]);
	pipe(fd[1]);


	if (fork()) {
		close(fd[0][0]); // scrive sulla 0
		close(fd[1][1]); // legge sulla 1
		ch='x';
		i=0;
		while (1) {
			write(fd[0][1],&ch,1);
			if(ch=='*') {
				close(fd[1][0]);
				close(fd[0][1]);
				return 0;
			}

			read(fd[1][0],&ch,1);
			printf("I'm the father (PID=%d)\n",getpid());
			i++;
			if(i==-1) ch='*'; // replace -1 w/ # of reps wished
		}
	}
	else {
		close(fd[0][1]); // 0 in lettura
		close(fd[1][0]); // 1 in scrittura
		while (1) {
			read(fd[0][0],&ch,1);
			if(ch=='*') {
				close(fd[0][0]);
				close(fd[1][1]);
				return 0;
			}
			printf ("I'm the child (PID=%d)\n",getpid());
			write(fd[1][1],&ch,1);
		}
	}
	return 0;
}
