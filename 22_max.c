#include<stdio.h>
int main(){
	int a[10] = {23,432,532,43,425,11,1,2,5,66};
	int max = 0;
	for(int i=0;i<=9;i++){
		if(a[i]>max)
			max = a[i];
	}
	printf("最大值为:%d\n",max);
	return 0;
}
