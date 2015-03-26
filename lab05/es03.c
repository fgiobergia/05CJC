#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void *wake(int s) {
	return NULL;
}

int main () {
	pid_t pid,sig;
	signal(SIGUSR1,(__sighandler_t)wake);
	sig=pid=fork();
	if (!sig) {
		sig=getppid();
	}
	else {
		sleep(1);
		kill(sig,SIGUSR1);
	}
	while (1) {
		pause();
		printf("%s Woke-up\n",(pid)?"Father":"Child");
		sleep(1);
		kill(sig,SIGUSR1);

	}
	return 0;
}

