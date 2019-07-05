#include <stdio.h>
int swap(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int a,b;
	printf("请输入第一个数:");
	scanf("%d",&a);
	printf("请输入第二个数:");
	scanf("%d",&b);
	swap(&a,&b);
	printf("交换后第一个数为:%d\n",a);
	printf("交换后第二个数为:%d\n",b);
	return 0;
}
