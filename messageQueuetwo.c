/*Excercise
IPC using message queue
read inputs from the parent process
Enter name:
Enter registration no:*/
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10

//structure for message queue 
struct mesg_buffer{
	long  mesg_type;
	char mesg_name[100];
	char mesg_regno[100];
	char mesg_age[100];
	
}
message;
int main(){
	int f= fork();
	
	if(f==0){
		printf("\n I am child\n");
		key_t key;
		int msgid;
		//ftok to generate unique key
		key = ftok("2021ict100",65);// we can put any number instead of 65
		//msgget creates a message queue and returns identifier
		msgid = msgget(key,0666 | IPC_CREAT);	
		//msgrcv to receive message
		msgrcv(msgid,&message,sizeof(message),1,0);
		//display the message
		printf("Data Received name is : %s \n",message.mesg_name);
		printf("Data Received Registration No  is : %s \n",message.mesg_regno);
		printf("Data Received Age  is : %s \n",message.mesg_age);
		//to destroy the message queue
		msgctl(msgid, IPC_RMID,NULL);
	}
	else{
		printf("\n I am parent\n");
		key_t key;
		int msgid;
		//ftok to generate unique key
		key = ftok("2021ict100", 65);// we can put any number instead of 65
		//msgget creates a message queue and return idntifier
		msgid = msgget(key,0666 | IPC_CREAT);
		message.mesg_type=1;
		printf("Write Name : \n");
		printf("Write Registration No : \n");
		printf("Write Age : \n");
		fgets(message.mesg_text,MAX,stdin);
		//msgsnd to send message
		msgsnd(msgid,&message,sizeof(message),0);
		//display the message
		printf("Data send is : %s \n",message.mesg_text);
	}
	
	
	return 0;
}
