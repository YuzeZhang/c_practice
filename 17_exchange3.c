#include<stdio.h>
int main(){
	int a = 3;	//0 0 1 1 
	int b = 2;	//0 0 1 0
	a = a^b;	//0 0 0 1(差异值，0表示两数相同，1表示两数不同)
	b = a^b;	//0 0 1 1(两数中的任何一个与差异值异或的结果为另一个数)
	a = a^b;	//0 0 1 0
	printf("交换后：a=%d,b=%d\n",a,b);
	return 0;
}
