#include <stdio.h>

int main (int argc, char *argv[]) {
	FILE *src, *dst;
	char ch;
	if (argc<3) {
		return 0;
	}
	src = fopen (argv[1],"rb");
	dst = fopen (argv[2],"wb");
	while((ch=fgetc(src))!=EOF) {
		fputc(ch,dst);
	}
	fclose (src);
	fclose (dst);
	return 0;
}


