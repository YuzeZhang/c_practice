//
// Created by handsomezyz on 2019/7/9.
//
#include <stdio.h>
int count_one_bits(int value1){
    int count=0;
    while (value1){
        count++;
        value1=value1&(value1-1);
    }
    return count;
}
int main(){
    int value,one_num;
    printf("请输入一个整数：");
    scanf("%d",&value);
    one_num = count_one_bits(value);
    printf("%d的二进制中1的个数是%d",value,one_num);
    return 0;
}
