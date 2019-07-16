//
// Created by handsomezyz on 2019/7/16.
//
#include <stdio.h>
int average(int a,int b){
    return (a&b)+((a^b)>>1);
}
int main(){
    printf("请输入两个整数：");
    int a,b;
    scanf("%d,%d",&a,&b);
    printf("这两个数的平均值为%d",average(a,b));
    return 0;
}
