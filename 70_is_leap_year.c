#include<stdio.h>
void is_leap_year(int year){
	if (year%4==0&&year%100!=0||year%400==0) {
		printf("%d是闰年\n",year);
	}else printf("%d不是闰年\n",year);
}
int main(){
	int year;
	printf("请输入一个年份:");
	scanf("%d", &year);
	is_leap_year(year);
	return 0;
}
