#include<stdio.h>
int main(){
	int a,b;
	printf("请输入两个整数,以空格间隔开:");
	scanf("%d %d",&a,&b);
	int i;
	i =(a>b)?a:b; //(a>b)为真则i取a,为假则i取b
	while(a%i!=0||b%i!=0){
		i--;
	}
	printf("两数的最大公约数为%d\n",i);
	return 0;
} 
