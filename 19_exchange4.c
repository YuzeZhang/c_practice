#include<stdio.h>
int main(){
	int a[3] = {1,2,3};
	int *b;
	b = &a[1];
	int *c;
	c = &a[1];
	printf("b=%d,c=%d\n",&b,&c);
	b = b^c;
	c = b^c;
	b = b^c;
	printf("b=%d,c=%d\n",&b,&c);
	return 0;
}
