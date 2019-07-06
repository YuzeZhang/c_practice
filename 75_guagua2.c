#include<stdio.h>
int gua(int n){
	int sum;
	if (n>2) {
		sum=2*gua(n-1);
	}else if(n<=2&&n>0){
		return n;
	}else if (n<=0) {
		printf("请输入正确的台阶总数!\n");
		return 0;
	}
	return sum;
}
int main(){
	int n,sum;
	printf("请输入台阶总数:");
	scanf("%d",&n);
	sum=gua(n);
	if (sum!=0) {
		printf("青蛙的跳法总数为:  %d\n",sum);
	}
	return 0;
}
