//
// Created by handsomezyz on 2019/7/16.
//
#include <stdio.h>
int average(int a,int b){
    return (a&b)+((a^b)>>1);
}
int main(){
    printf("����������������");
    int a,b;
    scanf("%d,%d",&a,&b);
    printf("����������ƽ��ֵΪ%d",average(a,b));
    return 0;
}
