//
// Created by handsomezyz on 2019/7/10.
//
#include <stdio.h>
int main(){
    int value;
    printf("������һ��������");
    scanf("%d",&value);
    printf("������Ķ�����������ż��λΪ��");
    for (int i = 31; i >= 1 ; i-=2) {
        printf("%d ",(value >> i)&1);
    }
    printf("\n������Ķ���������������λΪ��");
    for (int i = 30; i >=0 ; i-=2) {
        printf("%d ",(value>>i)&1);
    }
    printf("\n");
    return 0;
}
