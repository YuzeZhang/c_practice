#include<stdio.h>
//交换函数
void swap(int* t1,int* t2){
	int t;
	t = *t1;
	*t1 = *t2;
	*t2 = t;
}
//选择排序函数
void sort(int num[]){
	for(int i=0;i<5;i++){
		int index = i;
		for(int j=i+1;j<5;j++){
			if(num[j]>num[index]){
				index=j;
			}
			if(index==i){
				continue;
			}else{
			swap(&num[i],&num[index]);
			}
		}
	}
}
int main(){
	int num[5];
	int b;
	//提示输入第几个整数
	for(int i=0;i<5;i++){
		printf("请输入第%d个整数：",i+1);
		scanf("%d",&b);
		num[i]=b;
	}
	sort(num);
	printf("由大到小排序为：");
	//降序输出整数
	for(int i=0;i<5;i++){
		printf("%d\t",num[i]);
	}
	return 0;
}
