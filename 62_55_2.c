#include<stdio.h>
int main(){
	int min,temp,a[11];
	printf("enter data:\n");
	for(int i=1;i<=10;i++){
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	printf("\n");
	printf("The orginal numbers:\n");
	for (int i = 0; i < 10; i++) {
		printf("%5d\n",a[i]);
	}
	printf("\n");
	for (int i = 0; i <=9; i++) {
		for (int j=i+1; j< 10; j++) {
			if (a[min]>a[j]) {
				temp = a[i];
				a[i]=a[min];
				a[min]=temp;
				}
			}
			}
	printf("\nThe sortd numbers:\n");
	for (int i=1;i<=10 ;i++ ){
		printf("%5d\n",a[i]);
			}	
	printf("\n");
	return 0; }
