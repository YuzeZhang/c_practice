#include<stdio.h>
int main(){
	double sign=1;
	double sum=0,item=0;
	for(double i=1;i<101;i++){
		item = sign/i;
		sum+=item;
		sign = -sign;
	}
	printf("结果为:%5.8f\n",sum);
	return 0;
}                                          
