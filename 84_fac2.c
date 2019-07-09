#include<stdio.h>
int Fac(int n){
	int ret=1;
	for (int i = 1; i <=n; i++) {
		ret*=i;
	}
	return ret;
}
int main(){
	int n,ret;
	printf("请输入一个数:");
	scanf("%d", &n);
	ret = Fac(n);
	printf("%d的阶乘是%d\n",n,ret);
	return 0;
}
