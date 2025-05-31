/*
Write a cprogram to calculate the factorial of a given non negative integer
*/
#include<stdio.h>

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
