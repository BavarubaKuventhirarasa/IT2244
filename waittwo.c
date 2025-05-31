#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	printf("Parent process stared.PID:%d\n ",getpid());
	pid=fork();
	
	if(pid<0){
		perror("fork failed");
		exit(1);
	}
	
	if(pid==0){
		
		printf("Child process. PID: $d,sleeping for 2 seconds...\n");
		sleep(2);
		printf("Child process exiting. \n");
		exit(0);
	}
	else{
		
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);
		if(WIFEXITED(status)){
			printf("Child exited with status: %d\n",WEXITSTATUS(status));
			
		}
		else{
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending.\n");
	}
	return 0;
}
/*
OUTPUT 
Parent process stared.PID:10297
 Parent waiting for child to finish...
 Child process. PID: $d,sleeping for 2 seconds...
Child process exiting.
Child exited with status: 0
Parent process ending.
*/

