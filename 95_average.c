//
// Created by handsomezyz on 2019/7/14.
//
#include <stdio.h>
int average(int num1,int num2){
    int ave;
    ave = num1 - (num1-num2)/2;
    return ave;
}
int main(){
    int num1,num2;
    printf("��������������");
    scanf("%d,%d",&num1,&num2);
    printf("���ǵ�ƽ��ֵ��%d",average(num1,num2));
    return 0;
}
