//
// Created by handsomezyz on 2019/7/11.
//

#include <stdio.h>
int main(){
    int integer1,integer2,different,count=0;
    printf("�����������������Զ��ż����");
    scanf("%d,%d",&integer1,&integer2);
    different = integer1^integer2;
    for (int i = 31; i >=0; --i) {
        if (((different>>i)&1)==1){
            ++count;
        }
    }
    printf("���������Ķ����Ʊ��ʽ���� %d ��λ��ͬ",count);
    return 0;
}
