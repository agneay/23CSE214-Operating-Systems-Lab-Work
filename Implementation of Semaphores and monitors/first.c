#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
sem_t mutex;

void* producer(void* arg)
{
    int item;

    for(int i = 0; i < 10; i++)
    {
        item = rand() % 100;

        sem_wait(&empty);   // wait if buffer is full
        sem_wait(&mutex);   // enter critical section

        buffer[in] = item;
        printf("Produced: %d\n", item);

        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);   // leave critical section
        sem_post(&full);    // increase number of full slots

        sleep(1);
    }

    pthread_exit(NULL);
}

void* consumer(void* arg)
{
    int item;

    for(int i = 0; i < 10; i++)
    {
        sem_wait(&full);    // wait if buffer is empty
        sem_wait(&mutex);   // enter critical section

        item = buffer[out];
        printf("Consumed: %d\n", item);

        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);   // leave critical section
        sem_post(&empty);   // increase empty slots

        sleep(2);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t p, c;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}