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
    printf("������һ��������");
    scanf("%d",&value);
    one_num = count_one_bits(value);
    printf("%d�Ķ�������1�ĸ�����%d",value,one_num);
    return 0;
}
