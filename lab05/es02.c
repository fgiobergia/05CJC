#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main () {
	int n=10,i,r,j,v[2],tmp;
	srand(time(NULL));
	int fd=open("input",O_RDWR|O_CREAT);
	for (i=0;i<n;i++) {
		r=rand()%100;
		write(fd,&r,sizeof(r));
	}

	for (i=0;i<n-1;i++) {
		for (j=0;j<n-i-1;j++) {
			if (fork()) {
				wait();
				continue;
			}
			lseek (fd,j*sizeof(int),SEEK_SET);
			read(fd,v,sizeof(v));
			if(v[0]>v[1]) {
				tmp=*v;
				*v=*(v+1);
				*(v+1)=tmp;
				lseek(fd,-2*sizeof(int),SEEK_CUR);
				write(fd,v,sizeof(v));
			}
			return 0;
		}
	}

	lseek(fd,0,SEEK_SET);
	for(i=0;i<n;i++) {
		read(fd,&j,sizeof(int));
		printf ("%d\n",j);
	}

	close(fd);
	return 0;

}
