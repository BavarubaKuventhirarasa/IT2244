#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void printPrimes(int n) {
    printf("Prime numbers up to %d: ", n);
    for (int i = 2; i <= n; i++) {
        int isPrime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    pid_t q = fork();
    if (q == 0) {
        // Inside Q
        printf("[Q] My PID = %d, My Parent PID = %d\n", getpid(), getppid());

        pid_t s = fork();
        if (s == 0) {
            // Inside S
            printf("[S] Factorial of %d = %d\n", num, factorial(num));
            printf("[S] My PID = %d, My Parent PID = %d\n", getpid(), getppid());
        }
        exit(0);
    } else {
        pid_t r = fork();
        if (r == 0) {
            // Inside R
            printf("[R] My PID = %d, My Parent PID = %d\n", getpid(), getppid());

            pid_t t = fork();
            if (t == 0) {
                // Inside T
                printf("[T] Fibonacci series for %d:\n", num);
                fibonacci(num);
                printf("[T] My PID = %d, My Parent PID = %d\n", getpid(), getppid());
            } else {
                pid_t u = fork();
                if (u == 0) {
                    // Inside U
                    printf("[U] Prime numbers up to %d:\n", num);
                    printPrimes(num);
                    printf("[U] My PID = %d, My Parent PID = %d\n", getpid(), getppid());
                }
            }
            exit(0);
        }
    }

    printf("[P] I am Parent, My PID = %d\n", getpid());
    sleep(3); // Let all child processes finish
    return 0;
}
