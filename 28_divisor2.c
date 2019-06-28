#include<stdio.h>
int main(){
	int a,b;
	printf("请输入两个整数，以空格间隔开：");
	scanf("%d %d",&a,&b);
	while(a!=b){
		if(a<b)
			b = b-a;
		else
			a = a-b;
	}
	printf("最大公约数为%d\n",a);
	return 0;
}
