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
    printf("������һ����������");
    scanf("%d",&value);
    printf("������ĵĶ�����λģʽ�����ҷ�ת���ֵ�� %u",reverse_bit(value));
    return 0;
}
