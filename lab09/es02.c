#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t a,bcd,ef,g,h,i;

void P (char ch) {
	printf ("-> %c\n",ch);
}

void *A (void *p) {
	sem_wait(&a);
	P('A');
	sem_post(&bcd);
	sem_post(&bcd);
	sem_post(&bcd);
	pthread_exit(NULL);
}
void *B (void *p) {
	sem_wait(&bcd);
	P('B');
	sem_post(&i);
	pthread_exit(NULL);
}
void *C (void *p) {
	sem_wait(&bcd);
	P('C');
	sem_post(&ef);
	sem_post(&ef);
	pthread_exit(NULL);
}
void *D (void *p) {
	sem_wait(&bcd);
	P('D');
	sem_post(&h);
	pthread_exit(NULL);
}
void *E (void *p) {
	sem_wait(&ef);
	P('E');
	sem_post(&g);
	pthread_exit(NULL);
}
void *F (void *p) {
	sem_wait(&ef);
	P('F');
	sem_post(&g);
	pthread_exit(NULL);
}
void *G (void *p) {
	sem_wait(&g);
	sem_wait(&g);
	P('G');
	sem_post(&i);
	pthread_exit(NULL);
}
void *H (void *p) {
	sem_wait(&h);
	P('H');
	sem_post(&i);
	pthread_exit(NULL);
}
void *I (void *p) {
	sem_wait(&i);
	sem_wait(&i);
	sem_wait(&i);
	P('I');
	printf("\n");
	sem_post(&a);
	pthread_exit(NULL);
}

int main () {
	pthread_t p[9];
	int j,f;
	sem_init(&a,0,1);
	sem_init(&bcd,0,0);
	sem_init(&ef,0,0);
	sem_init(&g,0,0);
	sem_init(&h,0,0);
	sem_init(&i,0,0);
	while (1) {
		sleep(1);
		pthread_create(&p[0],NULL,I,NULL);
		pthread_create(&p[1],NULL,H,NULL);
		pthread_create(&p[2],NULL,G,NULL);
		pthread_create(&p[3],NULL,F,NULL);
		pthread_create(&p[4],NULL,E,NULL);
		pthread_create(&p[5],NULL,D,NULL);
		pthread_create(&p[6],NULL,C,NULL);
		pthread_create(&p[7],NULL,B,NULL);
		pthread_create(&p[8],NULL,A,NULL);
		pthread_join(p[0],NULL);
	}
	return 0;
}
