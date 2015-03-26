#include <stdio.h>

int main (int argc, char *argv[]) {
	FILE *src, *dst;
	char ch;
	if (argc<3) {
		return 0;
	}
	src = fopen (argv[1],"rb");
	dst = fopen (argv[2],"wb");
	while (fread(&ch,1,1,src)>0) {
		fwrite(&ch,1,1,dst);
	}
	fclose(src);
	fclose(dst);
	return 0;
}

