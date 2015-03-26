#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void tabs (int t) {
	int i;
	for(i=0;i<t;i++) printf("\t");
}

void visit (char *dname, char *sub, int tab) {
	DIR *dp;
	struct dirent *dir;
	struct stat buf;
	char *str,*s;
	str = malloc(strlen(sub)+strlen(dname)+2);
	sprintf(str,"%s/%s",sub,dname);
	dp = opendir(str);
	while (dir=readdir(dp)) {
		if (strcmp(dir->d_name,".")&&strcmp(dir->d_name,"..")) {
			s = malloc(strlen(str)+strlen(dir->d_name)+2);
			sprintf(s,"%s/%s",str,dir->d_name);
			tabs(tab);
			printf("%s\n",dir->d_name);
			stat (s,&buf);
			if (S_ISDIR(buf.st_mode)) {
				visit(dir->d_name,str,tab+1);
			}
			free (s);
		}
	}
	free (str);
}
		
int main (int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dir;
	if (argc<2) {
		return 0;
	}
	visit(argv[1],".",0);
	/*
	dp = opendir(argv[1]);
	while (dir=readdir(dp)) {
		printf ("%s\n",dir->d_name);
	}
	closedir(dp);*/
	return 0;
}

