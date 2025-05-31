/*
The parents creates a child process.
The child creates a grandchild process.
the grand child sleeps 2 seconds and exits with status 2.
The child waits for the grandchild, prints its exit status, then exitwith status 55.
*/
#include <stdio.h>
#include <stdlib.h>//for exit()
#include <unistd.h>//for fork(), sleep()
#include <sys/wait.h> //for wait()

int main(){
	pid_t pid;
	printf("Parent process stared.PID:%d\n ",getpid());
	pid=fork();//create a new child process
	
	if(pid<0){
		perror("fork failed");
		exit(1);
	}
	
	if(pid==0){
		//Child process
		printf("Child process. PID: $d,sleeping for 2 seconds...\n");
		sleep(2);
		printf("Child process exiting. \n");
		exit(0);
	}
	else{
		//parent process
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);//wait for child to finsh
		if(WIFEXITED(status)){//WIFEXITED(status) returns true if child terminated sucessfully.
			printf("Child exited with status: %d\n",WEXITSTATUS(status));
			//WEXITSTATUS(status) gets the actual exit code (0 here)
		}
		else{
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending.\n");
	}
	return 0;
}