//switch case
//Enter the number between 1 to 7:
//1. Today is sunday!

#include<stdio.h>
int main(){
	int num;
	printf("Enter the number between 1 to 7:");
	scanf("%d",&num);
	
	switch(num){
		case 1:
		printf("Today is Sunday.");
		break;
		
		case 2:
		printf("Today is Monday.");
		break;
		
		case 3:
		printf("Today is Tuesday.");
		break;
		
		case 4:
		printf("Today is Wednesday.");
		break;
		
		case 5:
		printf("Today is Thursday.");
		break;
		
		case 6:
		printf("Today is Friday.");
		break;
		
		case 7:
		printf("Today is Saturday.");
		break;
		
		default:
		printf("Please enter the number between 1to 7.");
		break;
	}
	return 0;
}
//output
/*
Enter the number between 1 to 7:5
Today is Thursday.[2021ict100@fedora ~]$ ./cnthree
Enter the number between 1 to 7:9
Please enter the number between 1to 7.*/