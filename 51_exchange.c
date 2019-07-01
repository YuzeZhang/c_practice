#include<stdio.h>
void exchange(int* a,int* b){
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}
int main(){
	int a[5] = {7,56,432,41,9};
	int b[5] = {1,12,3,455,6};
	//输出交换前两数组内容
	printf("交换前:a[5] = {");
	for(int i=0;i<5;i++){
		if(i<4)
			printf("%d,",a[i]);
		else
			printf("%d}\n",a[i]);
	}
	printf("交换前:b[5] = {");
	for(int i=0;i<5;i++){
		if(i<4)
			printf("%d,",b[i]);
		else
			printf("%d}\n",b[i]);
	}
	//交换
	for(int i=0;i<5;i++){
		exchange(&a[i],&b[i]);
	}
	//输出交换后两数组内容
	printf("交换后:a[5] = {");
	for(int i=0;i<5;i++){
		if(i<4)
			printf("%d,",a[i]);
		else
			printf("%d}\n",a[i]);
	}
	printf("交换后:b[5] = {");
	for(int i=0;i<5;i++){
		if(i<4)
			printf("%d,",b[i]);
		else
			printf("%d}\n",b[i]);
	}
	return 0;
}                                                                                                                         
