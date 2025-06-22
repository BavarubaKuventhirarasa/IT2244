//touch sharedmem
// vi writeshm.c
//writter process1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024 //size of shared memory segment

int main(){
	key_t key = ftok("shmfile",100);// generate unique key
	int shmid= shmget(key,SHM_SIZE, IPC_CREAT | 0666);//create shared memory segment
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr =(char*) shmat(shmid, NULL , 0);//attach to shared memory
	if(shmaddr == (char*)-1){
		perror("shmat");
		exit(1);
	}
	printf("Write data :");
	fgets(shmaddr, SHM_SIZE,stdin);//write data to shared memory
	printf("Data written in memory: %s \n",shmaddr);
	shmdt(shmaddr);//Detech from shared memory
	return 0;
}
//gcc writeshm.c -o writeshm


//reader
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
	key_t key = ftok("shmfile",100);
	int shmid = shmget(key,SHM_SIZE,0666);
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	char *shmaddr =(char*) shmat(shmid, NULL , 0);//attach to shared memory
	if(shmaddr == (char*)-1){
		perror("shmat");
		exit(1);
	}
	printf("Data Read in memory: %s \n",shmaddr);
	shmdt(shmaddr);
	shmctl(shmid,IPC_RMID,NULL);//Remove shared memory segment
	)
	return 0;
}