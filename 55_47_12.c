#include<stdio.h>
int main(){
	int total;
	total = 1;//第十天剩的一个
	for(int i=1;i<10;i++){
		total=(total+1)*2;
	}
	printf("第一天共摘%d个\n",total);
	return 0;
}
