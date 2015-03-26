#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t a,b,c,d,e,f,g,h,i;

void P (char ch) {
	printf ("~> %c\n",ch);
}

void *A (void *p) {
	while(1) {
		sem_wait(&a);
		P('A');
		sem_post(&b);
		sem_post(&c);
		sem_post(&d);
	}
	return NULL;
}
	
void *B (void *p) {
	while (1) {
		sem_wait(&b);
		P('B');
		sem_post(&i);
	}
	return NULL;
}

void *C (void *p) {
	while (1) {
		sem_wait(&c);
		P('C');
		sem_post(&e);
		sem_post(&f);
	}
	return NULL;
}

void *D (void *p) {
	while (1) {
		sem_wait(&d);
		P('D');
		sem_post(&h);
	}
	return NULL;
}

void *E (void *p) {
	while (1) {
		sem_wait(&e);
		P('E');
		sem_post(&g);
	}
	return NULL;
}

void *F (void *p) {
	while (1) {
		sem_wait(&f);
		P('F');
		sem_post(&g);
	}
	return NULL;
}

void *G (void *p) {
	while (1) {
		sem_wait(&g);
		sem_wait(&g);
		P('G');
		sem_post(&i);
	}
	return NULL;
}

void *H (void *p) {
	while (1) {
		sem_wait(&h);
		P('H');
		sem_post(&i);
	}
	return NULL;
}

void *I (void *p) {
	while (1) {
		sem_wait(&i);
		sem_wait(&i);
		sem_wait(&i);
		P('I');
		printf("\n");
		sleep(1);
		sem_post(&a);
	}
	return NULL;
}

int main () {
	pthread_t p;
	sem_init(&a,0,1);
	sem_init(&b,0,0);
	sem_init(&c,0,0);
	sem_init(&d,0,0);
	sem_init(&e,0,0);
	sem_init(&f,0,0);
	sem_init(&g,0,0);
	sem_init(&h,0,0);
	sem_init(&i,0,0);
	pthread_create(&p,NULL,I,NULL);
	pthread_create(&p,NULL,H,NULL);
	pthread_create(&p,NULL,G,NULL);
	pthread_create(&p,NULL,F,NULL);
	pthread_create(&p,NULL,E,NULL);
	pthread_create(&p,NULL,D,NULL);
	pthread_create(&p,NULL,C,NULL);
	pthread_create(&p,NULL,B,NULL);
	pthread_create(&p,NULL,A,NULL);
	while(1);
	return 0;
}
