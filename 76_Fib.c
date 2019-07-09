#include<stdio.h>
int Fib(int n){
	if (n==1||n==2) {
		return 1;
	}
	return Fib(n-1)+Fib(n-2);
}
int main(){
	int n=0,fib=0;
	while (1) {
		printf("请输入要求的斐波那契数的序号:");
		scanf("%d", &n);
		if (n<1) {
			printf("请输入正确的序号(大于0)!\n");
			continue;
		}
		break;
	}
	fib=Fib(n);
	printf("第%d个斐波那契数是%d\n",n,fib);
	return 0;
}
