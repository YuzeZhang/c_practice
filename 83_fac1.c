#include<stdio.h>
int Fac(int num){
	if (num==1) {
		return num;
	}
	return num*Fac(num-1);
}
int main(){
	int n,ret;
	printf("请输入一个数:");
	scanf("%d",&n);
	ret = Fac(n);
	printf("%d的阶乘为%d\n",n,ret);
	return 0;
}
