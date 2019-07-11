//
// Created by handsomezyz on 2019/7/10.
//
#include <stdio.h>
int main(){
    int value;
    printf("请输入一个整数：");
    scanf("%d",&value);
    printf("这个数的二进制序列中偶数位为：");
    for (int i = 31; i >= 1 ; i-=2) {
        printf("%d ",(value >> i)&1);
    }
    printf("\n这个数的二进制序列中奇数位为：");
    for (int i = 30; i >=0 ; i-=2) {
        printf("%d ",(value>>i)&1);
    }
    printf("\n");
    return 0;
}
