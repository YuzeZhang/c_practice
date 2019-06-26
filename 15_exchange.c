#include<stdio.h>
int main(){
	int a = 0;
	int b = 1;
	int t;
	printf("交换前:a=%d,b=%d\n",a,b);
	t=a;
	a=b;
	b=t;
	printf("交换后:a=%d,b=%d\n",a,b);
	return 0;
}
