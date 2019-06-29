#include<stdio.h>
int main(){
	int m,n,a;
	printf("请输入第一个数的值:");
	scanf("%d",&m);
	printf("请输入第二个数的值:");
	scanf("%d",&n);
	a = m*n;
	while(m!=n){
		if(m>n)
			m = m-n;
		else
			n = n-m;
	}
	printf("最大公约数为：%d\n",m);
	printf("最小公倍数为：%d\n",a/m);
	return 0;
}                                              
