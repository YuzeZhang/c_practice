#include<stdio.h>
int main(){
	int a,b;
	printf("请输入两个整数，以空格间隔开");
	scanf("%d %d",&a,&b);
	int c;
	c = a%b;
	while(c!=0){
		a = b;    //最大公约数 = 小数与（大数%小数）的最大公约数
		b = c;  
		c = a%b;  //较小的数对较大的数取余仍为较小的数
	}
	printf("两数的最大公约数为：%d\n",b);
	return 0;
}
