//ex-04

#include<stdio.h>
#include<unistd.h>
int main(){
	int f=fork();
	
	if(f==0){
		printf("I am child \n");
		int f1=fork();
		if(f1==0){
			
		}
	}
	
	if(getpid()>0){
		printf("I am parent A\n");
	}
	return 0;
}
