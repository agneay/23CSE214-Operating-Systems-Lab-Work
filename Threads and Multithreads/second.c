#include <stdio.h>
#include <pthread.h>

int sum;

void* addNumbers(void* arg) {
    int a = 10, b = 20;
    sum = a + b;
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, addNumbers, NULL);
    pthread_join(thread, NULL);

    printf("Sum = %d\n", sum);
    return 0;
}
