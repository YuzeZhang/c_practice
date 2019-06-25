#include<stdio.h>
#include<stdlib.h>
int main(){
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	if(a<=b){
		if(b<c)
			printf("最大值为：%d",c);
		else 
			printf("最大值为：%d",b);
	}
	else{
		if(a<c)
			printf("最大值为：%d",c);
		else
			printf("最大值为：%d",a);
	return EXIT_SUCCESS;
	}
	
}
