#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int n,i,*v;
	if (argc<2) {
		return 0;
	}
	n = atoi(argv[1]);
	v = malloc(n*sizeof(int));
	for(i=0;i<n;i++) {
		scanf ("%d",&v[i]);
	}
	for (i=0;i<n-1;i++) {
		if (fork()) {
			wait ();
			printf ("%d\n",v[i]);
			return 0;
		}
	}
	printf("%d\n",v[i]);
	return 0;
}

