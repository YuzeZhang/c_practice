#include<stdio.h>
//初始化数组
void init(int arr[],int size){
	printf("数组初始化为:\t");
	for (int i = 0; i < size; i++) {
		arr[i]=i;
	}
}
//清空数组
int empty(int arr[],int size){
	printf("数组清空为:\t");
	for (int i = 0; i < size; i++) {
		arr[i]=0;
	}
}
//数组元素逆置
int reverse(int arr[],int size){
	printf("数组逆置为:\t");
	int rev[10]={0};
	for (int i = 0; i < size; i++) {
		rev[i]=arr[i];
	}
	for (int i = 0; i < size; i++) {
		arr[i]=rev[size-1-i];
	}
}
int main(){
	int size;
	int arr[10]={0};
	size = sizeof(arr)/sizeof(arr[0]);
	init(arr,size);
	for (int i = 0; i < size; i++) {
		printf("%d\t",arr[i]);
		if (i==size-1) {
			printf("\n");
		}
	}
	reverse(arr,size);
	for (int i = 0; i < size; i++) {
		printf("%d\t",arr[i]);
		if (i==size-1) {
			printf("\n");
		}
	}
	empty(arr,size);
	for (int i = 0; i < size; i++) {
		printf("%d\t",arr[i]);
		if (i==size-1) {
			printf("\n");
		}
	}
	return 0;
}
