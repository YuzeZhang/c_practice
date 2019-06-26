#include<stdio.h>
int main(){
	printf("1000-2000年之间的闰年有：\n");
	for(int i=1000;i<=2000;i++){
		if(i%4==0&&i%100!=0||i%400==0){
			printf("%d\t",i);
		}
	}
	return 0;
}
