/*Excersise 01:
First Child: slept for 1 second.
Second Child: slept for 3 seconds.
Parent: Both children have finished.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t pid1 = fork();
	
	pid=fork();//create a new child process
	//
	if(pid1==0){
		//First Child process
		
		sleep(1);
		printf("Second Child process. PID: $d,sleeping for 3seconds...\n");
		sleep(3);
		printf("Child process exiting. \n");
		exit(0);
	}
	else{
		//parent process
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);//wait for child to finsh
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

