#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 8
#define ACTUAL_TIME time(NULL)

int counter;
int buffer[BUFFER_SIZE];

time_t timer;

void *producerOne(void *argp) {
	while (1) {
		if (counter >= BUFFER_SIZE) {
			sleep(1);
			continue;
		}

		buffer[counter - 1] = counter;
		counter++;
	}
}

void *consumer(void *argp) {
	while (1) {
		if (counter <= 0) {
			sleep(1);
			continue;
		}

		if (ACTUAL_TIME - timer > 1) {
			fflush(stdout);
			printf("%d\n", buffer[count - 1]);
			timer = ACTUAL_TIME;
		}
		buffer[counter - 1] = 0;
		counter--;
	}
}

int main() {
	counter = 0;
	timer = ACTUAL_TIME;

	pthread_t producerOneThread, consumerThread;
	pthread_create(&producerOneThread, NULL, producerOne, NULL);
	pthread_create(&consumerThread, NULL, consumer, NULL);

	pthread_join(producerOneThread, NULL);
	pthread_join(consumerThread, NULL);

	return 0;
}