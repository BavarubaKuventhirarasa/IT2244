//multi thread process
#include<stdio.h>
#include<pthread.h>
#define SIZE 6

int arr[SIZE] = {1,2,3,4,5,6};
int sum1 =0, sum2 =0;

//Function to be executed by the thread
void* sum_part1(void* arg){
	for(int i=0;i<SIZE/2; i++){
		sum1+=arr[i];
	}
	return NULL;
}
void* sum_part2(void* arg){
	for(int i=SIZE/2; i<SIZE; i++){
		sum2+=arr[i];
	}
	return NULL;
}
int main(){
	pthread_t thread1,thread2;
	pthread_create(&thread[i], NULL, print_message, message[i]);
	
	
	
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