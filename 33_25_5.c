#include<stdio.h>
#include<math.h>
int main(){
	int a;
	int b;
	printf("请输入一个小于1000的整数：");
	scanf("%d",&a);
	while(a>=1000){
		printf("请重新输入一个小于1000的整数：");
		scanf("%d",&a);
	}
	b=sqrt(a);
	printf("整数的平方根为：%d\n",b);
	return 0;
}
