#include<stdio.h>
#include<math.h>
int is_prime(int num){
	int i;
	for ( i = 2; i < sqrt(num); i++) {
		if (num%i==0) {
			break;
		}
	}
	if (i<=sqrt(num)) {
		printf("%d不是素数\n",num);
	}else printf("%d是素数\n",num);
}
int main(){
	int num;
	printf("请输入一个数:");
	scanf("%d", &num);
	is_prime(num);
	return 0;
}
