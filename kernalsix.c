//excercise
/*Print numbers from 1 to 10 and 
1 to 5 should be print by child process
from 6 to 10 should be print by parent process
calculate summation of those numbers*/
#include<stdio.h>
#include<unistd.h>
int main(){
	int f= fork();
	int sumc=0;
	int sump=0;
	int sumf=0;
	if(f==0){
		printf("I am a child process.");
		for(int i=6;i<=10;i++){
			printf("%d",i);
			sumc=sumc+i;
		}
		
	}
	else{
		printf("I am a parent process.");
		for(int j=1;j<=5;j++){
			printf("%d",j);
			sump=sump+j;
		}
		
	}
	sumf=sumc+sump;
	printf("Sumation of 10 numbers:%d",sumf);
	return 0;
}
/*
I am a parent process.
12345
Sumation of 10 numbers:15I am a child process.
678910
Sumation of 10 numbers:40
*/