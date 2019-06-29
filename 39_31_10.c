#include<stdio.h>
int main(){
        int i;
        printf("请输入利润：");
        scanf("%d",&i);
        double bonus,bon1,bon2,bon4,bon6,bon10;
        bon1 = 100000*0.1;
        bon2 = bon1+100000*0.075;
        bon4 = bon2+200000*0.05;
        bon6 = bon4+200000*0.03;
        bon10= bon6+400000*0.015;
	int n;
	n = i/100000;
	if(n>10)
		n = 10;
	switch(n){
		case 10:bonus = bon10+(i-1000000)*0.01;break;
		case 9:   //在switch语句中，如果当前case后无语句，则执行下一条case语句
		case 8:
		case 7:
		case 6:bonus = bon6+(i-600000)*0.015;break;
		case 5:
		case 4:bonus = bon4+(i-400000)*0.03;break;
		case 3:
		case 2:bonus = bon2+(i-200000)*0.05;break;
		case 1:bonus = bon1+(i-100000)*0.1;break;
		case 0:bonus = i*0.1;break;
	}
	printf("奖金为：%10.2f\n",bonus);
	return 0;
}
