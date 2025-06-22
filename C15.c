#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


// A normal C function that is executed as a thread
//when its name is specified in pthread_create()

void *helloworld(void *vargp){
	sleep(1);
	printf("Hello World! \n");
	return NULL;
}
int main(){
	pthread_t thread_id;
	printf("Befoire thread \n");
	pthread_create(&thread_id,NULL,helloworld, NULL);
	pthread_join(thread_id, NULL);
	printf("After thread \n");
	exit(0);
}
/*
output
Befoire thread
Hello World!
After thread

*/