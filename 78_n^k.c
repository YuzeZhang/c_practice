#include<stdio.h>
int power(int n,int k,int ret){
	if (k==0) {
		return 1;
	}
	if (k==1) {
		ret*=n;
		return ret;
	}
	ret*=n;
	power(n,k-1,ret);
}
int main(){
	int n,k,ret=1;
	printf("请输入底数:");
	scanf("%d", &n);
	printf("请输入指数:");
	scanf("%d", &k);
	ret = power(n,k,ret);
	printf("%d^%d=%d\n",n,k,ret);
	return 0;
}
