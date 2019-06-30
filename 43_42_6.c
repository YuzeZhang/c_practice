#include<stdio.h>
int main(){
	int item=1,sum=0;
	for(int i=1;i<=20;i++){
		for(int j=1;j<=i;j++){
			item=j*item;
			sum+=item;
		}
	}
	printf("结果为%d\n",sum);
	return 0;
}
