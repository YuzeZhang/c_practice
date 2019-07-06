#include<stdio.h>
int gua(int n){
	int sum;
	if (n>2) {
		sum = gua(n-1)+gua(n-2);
	}else if(n>0){
		return n;
	}else if(n<=0){
		printf("请输入正确的台阶总数!\n");
		return 0;
	}
	return sum;
}
int main(){
	int n,sum;
	printf("请输入青蛙跳的台阶总数:");
	scanf("%d", &n);
	sum=gua(n);
	if (sum!=0) {
		printf("跳法总数为:  %d\n",sum);
	}
	return 0;
}
