#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

void cpfile (char *src, char *dst) {
	int sd, dd;
	char ch;
	sd = open(src,O_RDONLY);
	dd = open(dst,O_WRONLY|O_CREAT);
	while (read(sd,&ch,1)>0) {
		write(dd,&ch,1);
	}
	close(dd);
	close(sd);
}

void cp (char *name, char *src, char *dst) {
	char *sdir,*ddir,*rdir,*wdir;
	DIR *dp;
	struct dirent *dir;
	struct stat buf;
	ddir = malloc(strlen(name)+strlen(dst)+2);
	sdir = malloc(strlen(name)+strlen(src)+2);
	sprintf(ddir,"%s/%s",dst,name);
	sprintf(sdir,"%s/%s",src,name);
	mkdir(ddir,0755);
	dp=opendir(sdir);
	printf ("%s %s\n",sdir,ddir);
	while (dir=readdir(dp)) {
		if (!strcmp(dir->d_name,".")||!strcmp(dir->d_name,"..")) continue;
		rdir=malloc(strlen(sdir)+strlen(dir->d_name)+2);
		sprintf(rdir,"%s/%s",sdir,dir->d_name);
		stat(rdir,&buf);
		if (S_ISDIR(buf.st_mode)) {
			cp(dir->d_name,sdir,ddir);
		}
		else {
			wdir=malloc(strlen(ddir)+strlen(dir->d_name)+2);
			sprintf(wdir,"%s/%s",ddir,dir->d_name);
			cpfile(rdir,wdir);
			free(wdir);
		}
		free(rdir);
	}
	free(sdir);
	free(ddir);
}
		


int main (int argc, char *argv[]) {
	if (argc<3) {
		return 0;
	}
	cp(argv[1],".",argv[2]);
	return 0;
}
