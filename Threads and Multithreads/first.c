#include <stdio.h>
#include <pthread.h>

void* printMessage(void* arg) {
    printf("Hello from the thread!\n");
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, printMessage, NULL);
    pthread_join(thread, NULL);

    return 0;
}
