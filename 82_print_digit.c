#include<stdio.h>
void print_digit(int num){
	if (num>9) {
		print_digit(num/10);
	}
	printf("%d\t",num%10);
}
int main(){
	int num;
	printf("请输入一个整数:");
	scanf("%d", &num);
	print_digit(num);
	return 0;
}
