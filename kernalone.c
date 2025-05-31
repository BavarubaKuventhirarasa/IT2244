//kernal
//ex 01-
#include<stdio.h>
#include<unistd.h>
int main(){
	printf("\nHello World!");
	int f=fork();
	int p=getpid();
	printf("\n the pid is %d",p);
	printf("\n the pid is %d",f);
	return 0;
}
/*output
Hello World!
 the pid is 11853
 the pid is 11854Hello World!
 the pid is 11854
 the pid is 0[
*/