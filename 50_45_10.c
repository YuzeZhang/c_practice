#include<stdio.h>
int main(){
	double a,b,s,t;
	a = 2;
	b = 1;
	for(int i=1;i<=20;i++){
		s+=a/b;
		t = b;
		b = a;
		a = a+t;
	}
	printf("前20项和为：%16.10f\n",s);
	return 0;
}
