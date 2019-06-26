#include<stdio.h>
int main(){
	int a = 3;	//0 0 1 1
	int b = 3;	//0 0 1 1
	a = a^b;	//0 0 0 0
	b = a^b;	//0 0 1 1
	a = a^b;	//0 0 1 1
	printf("交换后:a=%d,b=%d\n",a,b);
	return 0;
}
