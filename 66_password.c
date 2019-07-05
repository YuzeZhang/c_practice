#include<stdio.h>
int main()
{
	int password = 123456;
	int try;
	for (int i = 0; i < 3; i++) {
		printf("请输入密码:");
		scanf("%d", &try);
		if (try==password) {
			printf("登陆成功\n");
			break;
		}
		printf("输入错误!\n");
		if (i==2) {
			printf("密码错误次数过多!\n");
		}
	}
	return 0;
}
