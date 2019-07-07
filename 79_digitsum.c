#include<stdio.h>
int DigitSum(int n){
	if (n==0) {
		return 0;
	}
	return n%10+DigitSum(n/10);
}
int main(){
	int n,sum=0;
	printf("请输入一个数:");
	scanf("%d", &n);
	sum = DigitSum(n);
	printf("该数各位数字之和是%d\n",sum);
	return 0;
}
