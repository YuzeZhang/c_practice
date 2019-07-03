#include<stdio.h>
#include <stdlib.h>
#include <time.h>
extern int guess(int num);
int begin(int num){
	int choice;
	printf("--------------------\n");
	printf("-----1.开始游戏-----\n");
	printf("-----2.退出游戏-----\n");
	printf("--------------------\n");
	printf("请输入您的选择:");
	scanf("%d", &choice);
	while (1) {
		if (choice == 1) {
			guess(num);
			break;
		}else if (choice==2) {
			break;
		}
		printf("请重新输入:\n");
	}
}
int guess(int num){
	int guess_num;
	while (1) {
		printf("输入你的猜测(1-100):");
		scanf("%d",&guess_num);
		if (guess_num<num&&guess_num>=1&&guess_num<=100) {
			printf("再往大猜猜\n");
			continue;
		}else if (guess_num>num&&guess_num>=1&&guess_num<=100) {
			printf("再往小猜猜\n");
			continue;
		}else if (guess_num<1||guess_num>100) {
			printf("在1-100以内猜哦\n");
			continue;
		}
		printf("猜对了!\n");
		break;
	}
}
int main()
{
	srand(time(NULL));//设置随机种子
	int num = rand()%101;//设置随机数
	begin(num);
	return 0;
}
