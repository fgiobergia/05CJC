#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {
	int src, dst;
	char ch;
	if (argc<3) {
		return 0;
	}
	src = open (argv[1],O_RDONLY);
	dst = open (argv[2],O_WRONLY|O_CREAT);
	while(read(src,&ch,1)>0) {
		write(dst,&ch,1);
	}
	close(src);
	close(dst);
	return 0;
}

