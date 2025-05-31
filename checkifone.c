#if else
if(condition){
	//body of if statement
}
else{
	//body of else statement
}
//Enter your age and verify your elligble or not for election voting
//using if else condition
#include<stdio.h>
int main(){
        int age;
        printf("Enter your age:");
        //printf("%d",age);
        scanf("%d",&age);

        if(age<0){
                printf("\nYour age must greater than zero.");
        }
        else{
                if(age>=18){
                        printf("You can able to vote.");
                }
                else{
                        printf("\nYou cann't vote!\n");
                }
        }
        return 0;
}


//output
/*
Enter your age:12
You cann't vote![2021ict100@fedora ~]$ ./cnone
Enter your age:24
You can vote in election.*/

