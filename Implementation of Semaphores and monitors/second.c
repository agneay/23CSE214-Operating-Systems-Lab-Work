#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];

pthread_mutex_t mutex;
pthread_cond_t condition[N];

int LEFT(int i)
{
    return (i + N - 1) % N;
}

int RIGHT(int i)
{
    return (i + 1) % N;
}

void test(int i)
{
    if (state[i] == HUNGRY &&
        state[LEFT(i)] != EATING &&
        state[RIGHT(i)] != EATING)
    {
        state[i] = EATING;
        printf("Philosopher %d takes forks %d and %d and is Eating\n",
               i, LEFT(i), i);
        pthread_cond_signal(&condition[i]);
    }
}

void take_forks(int i)
{
    pthread_mutex_lock(&mutex);

    state[i] = HUNGRY;
    printf("Philosopher %d is Hungry\n", i);

    test(i);

    while (state[i] != EATING)
        pthread_cond_wait(&condition[i], &mutex);

    pthread_mutex_unlock(&mutex);
}

void put_forks(int i)
{
    pthread_mutex_lock(&mutex);

    state[i] = THINKING;
    printf("Philosopher %d putting forks %d and %d down\n",
           i, LEFT(i), i);
    printf("Philosopher %d is Thinking\n", i);

    test(LEFT(i));
    test(RIGHT(i));

    pthread_mutex_unlock(&mutex);
}

void *philosopher(void *num)
{
    int i = *(int *)num;

    while (1)
    {
        printf("Philosopher %d is Thinking\n", i);
        sleep(1);

        take_forks(i);

        sleep(2);

        put_forks(i);
    }
}

int main()
{
    pthread_t thread[N];
    int phil[N];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < N; i++)
        pthread_cond_init(&condition[i], NULL);

    for (int i = 0; i < N; i++)
    {
        phil[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &phil[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(thread[i], NULL);

    return 0;
}