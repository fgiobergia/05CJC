#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int n,*v,i;
	n=atoi(argv[1]);
	v=malloc(n*sizeof(int));
	for (i=0;i<n;i++) {
		if (fork()) {
			v[i]=0;
		}
		else {
			v[i]=1;
		}
	}
	wait();
	for(i=0;i<n;i++) {
		printf("%d",v[i]);
	}
	printf("\n");
	return 0;
}

