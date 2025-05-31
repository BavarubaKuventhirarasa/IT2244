//Ternary Operator
//testcondition ? expression1:expression2;
#include<stdio.h>
int main(){
        int age;
        printf("Enter your age:");
        //printf("%d",age);
        scanf("%d",&age);
		(age>=18) ?printf("You are eligble for vote"):printf("You are not eligble for vote");
		
     
        return 0;
}
/*
output
Enter your age:25
You are eligble for vote[
*/