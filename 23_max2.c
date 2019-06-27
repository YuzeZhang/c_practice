#include<stdio.h>
int main(){
	int a[10];
	for(int i=0;i<=9;i++){
		int b;
		printf("请输入第%d个整数",i+1);
		scanf("%d",&b);
		a[i] = b;
	}
	int max = 0;
	for(int i=0;i<=9;i++){
		if(a[i]>=max){
			max = a[i];
		}
	}
	printf("这10个整数中的最大值为：%d\n",max);
	return 0;
}
