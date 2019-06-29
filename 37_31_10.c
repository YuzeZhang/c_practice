#include<stdio.h>
int main(){
	int I;
	int reward;
	printf("请输入利润:");
	scanf("%d",I);
	if(I<=100000){
		reward = I*0.1;
	}
	if(I>100000&&I<=200000){
		reward = (100000*0.1)+(I-100000)*0.075;
	}
	if(I>200000&&I<=400000){
		reward = (100000*0.1)+(I-100000)*0.075+;
	}
}
