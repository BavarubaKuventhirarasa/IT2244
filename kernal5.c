#include<stdio.h>
#include<unistd.h>
int main(){
	
	int f=fork();
	if(f==0){
		printf("I am child\n.");
		printf("My parent Id %d\n",getppid());
	}
	else{
		int f1=fork();
		if(f1==0){
			printf("I am sibling\n");
			printf("My parent Id %d\n",getppid());
		}
		else{
			printf("I am parent\n");
			printf("My Id %d\n",getpid());
			printf("My parent Id %d \n",getppid());
			
		}
	}
	return 0;
}