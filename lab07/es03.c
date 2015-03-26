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
	v=malloc((n+1)*sizeof(int));
	for(i=0;i<n;i++) {
		fgets(line,sizeof(line),fin);
		v[i]=atoi(line);
	}
	v[n]=-1;
	sort(v,n);
	fclose(fin);
	free(in);
	pthread_exit((void*)v);
}

int main (int argc, char *argv[]) {
	int n,m,i,*v,**ptr,len=4,min,mj,j;
	FILE *fp;
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
	ptr=malloc(n*sizeof(int*));
	while(m>0) {
		for(i=0;i<n;i++) {
			if(!pthread_tryjoin_np(list[i],(void*)&ptr[i])) {
				m--;
			}
		}
	}
	fp=fopen(argv[3],"w");
	for(i=0;i<n*len;i++) {
		min=-1;
		mj=-1;
		for(j=0;j<n;j++) {
			if (*(ptr[j])!=-1) {
				if(*(ptr[j])<min || min<0) {
					min=*(ptr[j]);
					mj=j;
				}
			}
		}
		fprintf (fp,"%d\n",min);
		ptr[mj]++;
	}
	fclose(fp);
				
	return 0;
}	
