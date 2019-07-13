//
// Created by handsomezyz on 2019/7/13.
//
#include <stdio.h>
unsigned int reverse_bit(unsigned int value){
    int bit=0,ret=0;
    for (int i = 0; i < 32; ++i) {
        ret=ret<<1;
        bit = value & 1;
        value=value>>1;
        ret = bit | ret;
    }
    return ret;
}
int main(){
    unsigned int value;
    printf("请输入一个正整数：");
    scanf("%d",&value);
    printf("这个数的的二进制位模式从左到右翻转后的值是 %u",reverse_bit(value));
    return 0;
}
