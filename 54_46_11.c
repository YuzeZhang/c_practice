#include<stdio.h>
int main(){
	double s=100,h=100;
	for(int i=1;i<=10;i++){
		h/=2;
		s+=2*h;
	}
	printf("共经过%6.4f米,第10次反弹%6.4f米\n",s,h);
	return 0;
}
