/*
Q5).Implement a thread function that takes an integer argument,squares it,
and returns the results to the main thread using pthread_exit and pthread_join.
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = num * num;
    return result;
}

int main() {
    pthread_t t;
    int num = 6;

    pthread_create(&t, NULL, square, &num);

    void* res;
    pthread_join(t, &res);

    int* squareResult = (int*)res;
    printf("Square of %d is %d\n", num, *squareResult);
    free(res);

    return 0;
}
