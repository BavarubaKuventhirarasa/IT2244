//multi thread process
#include<stdio.h>
#include<pthread.h>

//Function to be executed by the thread
void* print_message(void* arg){
	char* message=(char*)arg;
	printf("%s\n", message);
	return NULL;
}
int main(){
	pthread_t thread[3];
	char* message[]={
		"Thread1 says hi!"
		"Thread2 says hello!"
		"Thread3 says hey!"
	};
	
	//create  thread
	for(int i=0; i<3;i++){
		pthread_create(&thread[i], NULL, print_message, message[i]);
	}
	//wait for both threads to finish
	for(int i=0; i<3;i++){
		pthread_join(thread[i], NULL);
	}
	
	
	printf("All threads completed. \n");
	return 0;
	
	
}
/*
output

Thread1 says hi!Thread2 says hello!Thread3 says hey!
@▒1p
@Ʊo
All threads completed.

*/