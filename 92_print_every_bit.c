//
// Created by handsomezyz on 2019/7/11.
//
#include <stdio.h>
int main(){
    int integer;
    printf("������һ��������");
    scanf("%d",&integer);
    printf("��������Ķ����Ƶ�ÿһλ��:");
    for (int i = 31; i >=0 ; --i) {
        printf("%d ",(integer>>i)&1);
    }
    return 0;
}
