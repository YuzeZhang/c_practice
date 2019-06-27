#include<stdio.h>
int main(){
	int a[5];
	for(int i=0;i<5;i++){
		int b;
		printf("请输入第%d个数：",i+1);
		scanf("%d",&b);
		a[i] = b;
	}
	printf("%d %d\n",a[1],a[4]);
	printf("5个整数由大到小的顺序为：");
	for(int i=1;i<5;i++){
		int t=0;
		for(int j=1;j<5-i;j++){
			if(a[j]<a[j-1]){
				t = a[j];	  //调换a[i]和a[j]的值
				a[j] = a[j-1];
				a[j-1] = t;
			}
		}
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
