#include<stdio.h>
int main(){
	int a,n;
	printf("请输入a的值：");
	scanf("%d",&a);
	printf("请输入n的值：");
	scanf("%d",&n);
	int sum=0,item=0;
	for(int i=1;i<=n;i++){
		item+=a;
		sum+=item;
		a=a*10;
		}
	printf("a+aa+aaa+aaaa+...=%d\n",sum);
	return 0;
}                                                
