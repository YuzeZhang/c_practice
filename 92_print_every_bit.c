//
// Created by handsomezyz on 2019/7/11.
//
#include <stdio.h>
int main(){
    int integer;
    printf("请输入一个整数：");
    scanf("%d",&integer);
    printf("这个整数的二进制的每一位是:");
    for (int i = 31; i >=0 ; --i) {
        printf("%d ",(integer>>i)&1);
    }
    return 0;
}
