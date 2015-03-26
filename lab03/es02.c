#include <stdio.h>

int main (int argc, char *argv[]) {
	int n,k,i;
	if (argc<3) {
		return 0;
	}
	n = atoi(argv[1]);
	k = atoi(argv[2]);
	for (i=0;i<n;i++) {
		if (fork()) {
			if (fork()) {
				return 0;
			}
		}
	}
	sleep(k);
	printf ("Bye from %d\n",getpid());
	return 0;
}
