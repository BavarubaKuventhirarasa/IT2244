#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

long long factorial(int num) {
    long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int shmid;
    key_t key = 1234;
    int *shared_data;

    // Create shared memory segment of size to hold 4 integers
    shmid = shmget(key, 4 * sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }

    // Attach shared memory
    shared_data = (int *) shmat(shmid, NULL, 0);
    if (shared_data == (int *) -1) {
        perror("shmat failed");
        return 1;
    }

    int n, r;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Enter value of r: ");
    scanf("%d", &r);

    // Store n and r in shared memory
    shared_data[0] = n;
    shared_data[1] = r;

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child Process
        int n = shared_data[0];
        int r = shared_data[1];

        printf("\n[Child Process]\n");
        printf("Factorial of %d = %lld\n", n, factorial(n));
        printf("Factorial of %d = %lld\n", r, factorial(r));
    } else {
        // Parent Process
        wait(NULL); // Wait for child to finish

        int n = shared_data[0];
        int r = shared_data[1];

        long long fact_n = factorial(n);
        long long fact_r = factorial(r);
        long long fact_n_r = factorial(n - r);

        long long nPr = fact_n / fact_n_r;
        long long nCr = fact_n / (fact_r * fact_n_r);

        printf("\n[Parent Process]\n");
        printf("nPr (%dP%d) = %lld\n", n, r, nPr);
        printf("nCr (%dC%d) = %lld\n", n, r, nCr);

        // Detach and remove shared memory
        shmdt(shared_data);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
