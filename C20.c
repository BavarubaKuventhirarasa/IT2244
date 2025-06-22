/*
Q2).Write a program to create 5 threads.Each thread should print its thread
ID and then exit.The main thread should join all threads and print a completion message.
*/
#include <stdio.h>
#include <pthread.h>

void* printThreadID(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, printThreadID, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Main thread: All threads have completed.\n");
    return 0;
}
/*
output
Thread ID: 139729448441408
Thread ID: 139729440048704
Thread ID: 139729431656000
Thread ID: 139729423263296
Thread ID: 139729414870592
Main thread: All threads have completed.

*/