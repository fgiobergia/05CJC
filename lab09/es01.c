#include <stdio.h>

void P(char ch) {
	printf("%c\n",ch);
}

int main () {
	char ch[3]="aaa";
	int a[2],bcd[2],ef[2],g[2],h[2],i[2];
	pipe(a); pipe(ef); pipe(g);
	pipe(bcd);pipe(h); pipe(i);

	write(a[1],ch,1);

	while (1) {
		read(a[0],ch,1);
		sleep(1);
		if (fork()) {
			if (fork()) {
				if (fork()) {
					if (fork()) {
						if (fork()) {
							if (fork()) {
								if (fork()) {
									if (fork()) {
										// A
										P('A');
										write(bcd[1],ch,3);
									}
									else {
										// H
										read(h[0],ch,1);
										P('H');
										write(i[1],ch,1);
										return 0;
									}
								}
								else {
									// I
									read(i[0],ch,1);
									read(i[0],ch,1);
									read(i[0],ch,1);
									P('I');
									write(a[1],ch,1);
									return 0;
								}
							}
							else {
								// G
								read(g[0],ch,1);
								read(g[0],ch,1);
								P('G');
								write(i[1],ch,1);
							}
						}
						else {
							// F
							read(ef[0],ch,1);
							P('F');
							write(g[1],ch,1);
						}
					}
					else {
						// E
						read(ef[0],ch,1);
						P('E');
						write(g[1],ch,1);
					}
				}
				else {
					// D
					read(bcd[0],ch,1);
					P('D');
					write(h[1],ch,1);
				}
			}	
			else {
				// C
				read(bcd[0],ch,1);
				P('C');
				write(ef[1],ch,2);
			}
		}
		else {
			// B
			read(bcd[0],ch,1);
			P('B');
			write(i[1],ch,1);
		}
	}

	return 0;
}

