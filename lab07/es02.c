#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **args;

void sort (int *v, int len) {
	int i;
	// Uhm, yeah, our engineers are working on that
	for(i=0;i<len;i++) {
		v[i]++;
	}
}


void *handle (void *num) {
	FILE *fin,*fout;
	char *in,*out;
	int *v,n,i;
	char line[128];
	in=malloc(strlen(args[2])+5); // 5->floor(log((int)num))
	sprintf(in,"%s%d",args[2],*((int*)num));
	fin=fopen(in,"r");
	fgets(line,sizeof(line),fin);
	n=atoi(line);
	v=malloc(n*sizeof(int));
	for(i=0;i<n;i++) {
		fgets(line,sizeof(line),fin);
		v[i]=atoi(line);
	}
	sort(v,n);
	out=malloc(strlen(args[3])+5);
	sprintf(out,"%s%d",args[3],*((int*)num));
	fout=fopen(out,"w");
	for(i=0;i<n;i++) {
		fprintf(fout,"%d\n",v[i]);
	}
	fclose(fout);
	free(out);
	fclose(fin);
	free(in);
	pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
	int n,m,i,*v;
	pthread_t *list;
	if (argc<4) {
		return 0;
	}
	args=argv;
	n=atoi(argv[1]);
	v=malloc(n*sizeof(int));
	list=malloc(n*sizeof(pthread_t));
	for (i=0;i<n;i++) {
		v[i]=i+1;
		pthread_create(&list[i],NULL,handle,(void*)&v[i]);
	}
	m=n;
	while(m>0) {
		for(i=0;i<n;i++) {
			if(!pthread_tryjoin_np(list[i],NULL)) {
				m--;
			}
		}
	}
	return 0;
}
		
