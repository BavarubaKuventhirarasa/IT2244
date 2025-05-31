#include<stdio.h>
#include<unistd.h>
int main(){
	int f=fork();
	if(f==0){
		printf("\nI am a child process.\n");
		int f1=fork();
		if(f1==0){
			printf("\nI am a child process.\n");
			int f2=fork();
			if(f2==0){
				int num;
				printf("\n Enter the Fibonnaci series number:\n");
				scanf("%d",&num);
				int fibonnaci;
				int a,b;
				for(int c=1;c<=num;c++)
				{
					if(c<1)
					{
						a=0;
						b=1;
						fibonnaci=a+b;
					}
					a=b;
					b=c;
					fibonnaci=a+b;
				}
				printf("%d",&fibonnaci);
			}
			int f3= fork();
			if(f3==0){
				printf("\nI am a child process.\n");
				int num;
				printf("\nPlease enter the factorial number:\n");
				scanf("%d",&num);
				int fact=1;
				if(num==0 && num==1){
					fact=1;
				}
				else{
					printf("\nI am a child process.\n");
					for(int i=2;i=num;i++){
						fact=fact*1;
					}
				}
				printf("\nFactorial of given number:\n",fact);
			}
		}
		else{
			printf("\nI am a parent.\n");
		}
	}
	else{
		printf("I am a parent.",getpid());
	}
	return 0;
}