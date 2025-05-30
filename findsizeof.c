#include<stdio.h>
int main(){
	int age=10;
	printf("%d",age);
	printf("size: %zu",sizeof(age));
	return 0;
}
output
10 size: 4//integer so 4bytes

#include<stdio.h>
int main(){
	double number=12.45;
	printf("%lf",number);
	printf("size: %zu",sizeof(number));
	return 0;
}
OUTPUT
12.450000size: 8

#include<stdio.h>
int main(){
	float numbera=12.45f;
	printf("%f",numbera);
	printf(".l%f",numbera);
	printf("size: %zu",sizeof(numbera));
	return 0;
}
output
12.450000.l12.450000size: 4

#include<stdio.h>
int main(){
	float numbera=12.4f;
	printf("%f",numbera);//12.400000
	printf(".l%f",numbera);//12.4
	printf("size: %zu",sizeof(numbera));
	return 0;
}
