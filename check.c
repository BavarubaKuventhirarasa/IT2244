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
[2021ict100@fedora ~]$ vi cnthree.c
[2021ict100@fedora ~]$ gcc cnthree.c -o cnthree
[2021ict100@fedora ~]$ ./cnthree
Enter the number between 1 to 7:5
Today is Thursday.[2021ict100@fedora ~]$ ./cnthree
Enter the number between 1 to 7:9
Please enter the number between 1to 7.
/*Write a code for small astrolegy based on your life path number for that
get date of from user then calculate life path number.(use switch case)
example:-
Date: 23
calculation life path number :
a=date%10 
b=date/10
c=a+b
1.lucky,2.carefully do your work,3.Storger 4.Happy,5.Can get help*/

#include<stdio.h>
int main(){
        int bddate;
        printf("Enter your birth date.");
        scanf("%d",&bddate);
        int a=(bddate%10);
        int b=(bddate/10);
        int c=a+b;
        switch(c){
                case 1:
                printf("Lucky");
                break;

                case 2:
                printf("Carefully do the work.");
                break;

                case 3:
                printf("Stronger");
                break;

                case 4:
                printf("Strugle");
                break;

                case 5:
                printf("Can get help");
                break;

                case 6:
                printf("Attraction People");
                break;

                case 7:
                printf("Sad");
                break;

                case 8:
                printf("Kindness people");
                break;

                case 9:
                printf("Courage");
                break;

                default:
                printf("Please enter your birthdate with in 1 to 31.");
                break;
        }
        return 0;

}

/*
write a c program to generate and print the fibonacci series up to a specified number of terms
the program should take the number of terms as input from the user and then display thecorresponding 
fibonacci series
*/
#include<stdio.h>
int main(){
	int num;
	printf("Enter the Fibonnaci series number:\n");
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
	//not correct
	return 0;
}
/*
Write a cprogram to calculate the factorial of a given non negative integer
*/
#include <stdio.h>

long long factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %lld", num, factorial(num));
    return 0;
}
#include<stdio.h>
int main(){
	return 0;
}
/*
Accepts two strings as input from user.
Concatenates the two strings Displays the concatenated results.
*/
#include<stdio.h>
int main(){
	return 0;
}
/*
takes a binary number(as an integer) as input and converts it to its decimal equivalent.
*/
#include<stdio.h>
int main(){
	return 0;
}

/*
Accepts an array of integers from the user.
Finds and displays the maximum and minimum values in the array
*/

/*
to generate Pascal's Triangle.
Output:
no.of.rows =5
*/












