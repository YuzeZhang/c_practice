//
// Created by zeno on 2019/8/22.
//

#include <stdio.h>
int main(){
    unsigned char a = 0xA5;
    unsigned char b = ~a>>4+1;
    printf("%d,%d\n",a,b);
    return 0;
}
