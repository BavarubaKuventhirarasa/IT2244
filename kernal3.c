//ex-03
#include<stdio.h>
#include<unistd.h>
int main(){
	int f= fork();

	
	if(f==0){
		printf("I am child\n");
	}
	else{
		printf("I am parent\n");
	}
	return 0;
}
/*
I am parent
I am child
*/