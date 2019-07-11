//
// Created by handsomezyz on 2019/7/11.
//

#include <stdio.h>
int main(){
    int integer1,integer2,different,count=0;
    printf("请输入两个整数，以逗号间隔：");
    scanf("%d,%d",&integer1,&integer2);
    different = integer1^integer2;
    for (int i = 31; i >=0; --i) {
        if (((different>>i)&1)==1){
            ++count;
        }
    }
    printf("这两个数的二进制表达式中有 %d 个位不同",count);
    return 0;
}
