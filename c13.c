/*
ex 01:
1.read two input from user(//parenr process)
name:
regno:
age:

2.print the output from the child(//child process)
name:abc
regno:2021/ict/01
age:25
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MSGSIZE 16
char* msg_name;
char* msg_regno;
char* msg_age;
 
int main() {
   int pipefd[2]; // pipefd[0] for reading, pipefd[1] for writing
    pid_t pid;
	
    
    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Create child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        // Parent Process
        close(pipefd[0]); // Close read end

        // Input data using pointer
        printf("Enter name: ");
        fgets(ptr->name, sizeof(ptr->name), stdin);
        ptr->name[strcspn(ptr->name, "\n")] = '\0'; // Remove newline

        printf("Enter regno: ");
        fgets(ptr->regno, sizeof(ptr->regno), stdin);
        ptr->regno[strcspn(ptr->regno, "\n")] = '\0';

        printf("Enter age: ");
        scanf("%d", &ptr->age);

        // Write struct data to pipe
        write(pipefd[1], ptr, sizeof(struct Student));
        close(pipefd[1]); // Close write end
    } else {
        // Child Process
        close(pipefd[1]); // Close write end

        // Read from pipe into struct via pointer
        read(pipefd[0], ptr, sizeof(struct Student));

        // Print the values
        printf("\n--- Child Process Output ---\n");
        printf("name: %s\n", ptr->name);
        printf("regno: %s\n", ptr->regno);
        printf("age: %d\n", ptr->age);

        close(pipefd[0]); // Close read end
    }

    return 0;
}
