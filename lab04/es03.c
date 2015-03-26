#include <stdio.h>
#include <unistd.h>

void task(int n) {
	sleep(rand()%3);
	printf("P%d\n",n);
}

int main () {
	srand(time(NULL));
	task(1);
	pid_t p1,p2;
	if (p1=fork()) {
		task(2);
		if (p2=fork()) {
			task(4);
			waitpid(p2,NULL,0);
			task(7);
			waitpid(p1,NULL,0);
			task(9);
		}
		else {
			task(5);
			return 0;
		}
	}
	else {
		task(3);
		if (fork()) {
			wait();
			task(8);
			return 0;
		}
		else {
			task(6);
		}
	}
	return 0;
}

