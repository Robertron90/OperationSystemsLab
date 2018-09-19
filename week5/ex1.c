#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
#define NUM_THREADS 5

void *printHello(void *id) {
	long tid;
	tid = (long) id;
	printf("Hello! This is thread #%ld!\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t=0;t<NUM_THREADS; t++) {
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, printHello, (void *)t);
		pthread_join(threads[t], NULL);
		if(rc) {
			printf("ERROR return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

	pthread_exit(NULL);
}
