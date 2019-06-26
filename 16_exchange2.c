#include<stdio.h>
int main(){
	int a = 2;
	int b = 3;
	printf("交换前:a=%d,b=%d\n",a,b);
	a = a+b;
	b = a-b;
	a = a-b;
	printf("交换后:a=%d,b=%d\n",a,b);
	return 0;
}
