/*Write a code for small astrolegy based on your life path number for that
get date of from user then calculate life path number.(use switch case)
*/

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