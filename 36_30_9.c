#include<stdio.h>
#include<math.h>
int main(){
	int num,indiv,ten,hundred,thousand,ten_thousand,place;
	printf("请输入一个整数（0-99999）：");
	scanf("%d",&num);
	while(num<0||num>99999){
		printf("请重新输入(0-99999):");
		scanf("%d",&num);
	}
	if(num>9999&&num<99999)
		place = 5;
	else if(num>999)
		place = 4;
	else if(num>99)
		place = 3;
	else if(num>9)
		place = 2;
	else if(num>0)
		place = 1;
	printf("位数：%d",place);
	ten_thousand = num/10000;
	thousand = (num-ten_thousand*10000)/1000;
	hundred = (num-ten_thousand*10000-thousand*1000)/100;
	ten = (num-ten_thousand*10000-thousand*1000-hundred*100)/10;
	indiv = (num-ten_thousand*10000-thousand*1000-hundred*100-ten*10);
	printf("\n每一位数字为：");
	switch(place){
		case 5:printf("%d,%d,%d,%d,%d",ten_thousand,thousand,hundred,ten,indiv);
		       printf("\n倒序输出为：%d%d%d%d%d\n",indiv,ten,hundred,thousand,ten_thousand);
		       break;
		case 4:printf("%d,%d,%d,%d",thousand,hundred,ten,indiv);
		       printf("\n倒序输出为：%d%d%d%d\n",indiv,ten,hundred,thousand);
		       break;
		case 3:printf("%d,%d,%d",hundred,ten,indiv);
		       printf("\n倒序输出为：%d%d%d\n",indiv,ten,hundred);
		       break;
		case 2:printf("%d,%d",ten,indiv);
		       printf("\n倒序输出为：%d%d\n",indiv,ten);
		       break;
		case 1:printf("%d",indiv);
		       printf("\n倒序输出为：%d\n",indiv);
		       break;
	}
	return 0;
}
