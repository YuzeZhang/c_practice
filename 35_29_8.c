#include<stdio.h>
int main(){
	double score;
	printf("请输入您的成绩：");
	scanf("%lf",&score);
	while(score>100||score<0){
		printf("请重新输入：");
		scanf("%lf",&score);
	}
	char grade;
	switch((int)(score/10)){
		case(10):grade ='A';break;
		case(9):grade = 'A';break;
		case(8):grade = 'B';break;
		case(7):grade = 'C';break;
		case(6):grade = 'D';break;
		default:grade = 'D';break;
	}
	printf("等级是%c\n",grade);
	return 0;
}
