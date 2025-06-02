//1)touch 2021ict100
//2)chmod 644 2021ict100
//send
//3)vi ipcone.c
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10

//structure for message queue 
struct mesg_buffer{
	long  mesg_type;
	char mesg_text[100];
}
message;
int main(){
	key_t key;
	int msgid;
	//ftok to generate unique key
	key = ftok("2021ict100", 65);// we can put any number instead of 65
	//msgget creates a message queue and return idntifier
	msgid = msgget(key,0666 | IPC_CREAT);
	message.mesg_type=1;
	printf("Write Data : ");
	fgets(message.mesg_text,MAX,stdin);
	//msgsnd to send message
	msgsnd(msgid,&message,sizeof(message),0);
	//display the message
	printf("Data send is : %s \n",message.mesg_text);
	
	return 0;
}
//sender and receiver has a separe files then only run,mfirst compile both
//receive

//vi ipctwo.c
#include <stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
//structure for message queue
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}message;
int main(){
	key_t key;
	int msgid;
	//ftok to generate unique key
	key = ftok("2021ict100",65);// we can put any number instead of 65
	//msgget creates a message queue and returns identifier
	msgid = msgget(key,0666 | IPC_CREAT);	
	//msgrcv to receive message
	msgrcv(msgid,&message,sizeof(message),1,0);
	//display the message
	printf("Data Received is : %s \n",message.mesg_text);
	//to destroy the message queue
	msgctl(msgid, IPC_RMID,NULL);
	
	return 0;

}

/*
[2021ict100@fedora ~]$ vi ipctwo.c
[2021ict100@fedora ~]$ gcc ipctwo.c -o ipctwo
[2021ict100@fedora ~]$ ./ipcone
Write Data : Hello Ruba
Data send is : Hello Rub
[2021ict100@fedora ~]$ ./ipctwo
Data Received is :
[2021ict100@fedora ~]$ ./ipcone
Write Data : hwlloworld
Data send is : hwlloworl
[2021ict100@fedora ~]$ ./ipctwo
Data Received is :
*/