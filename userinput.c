//input from user
#include<stdio.h>
int main(){
	int age;
	printf("Enter your age:");
	//printf("%d",age);
	scanf("%d",&age);
	printf("Age=%d",age);
	
	
	double number;
	char alpha;
	printf("Enter double input:");
	scanf("%lf",&number);
	printf("\nYour double input is:%lf",number);
	
	printf("Enter character input:");
	scanf("%c",&alpha);
	printf("\nYour char input is:%c",alpha);
	
	// take multiple input together
	printf("Enter input:")
	scanf("%lf %c",&number,&alpha);
	return 0;
}