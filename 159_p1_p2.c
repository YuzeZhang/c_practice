//
// Created by zeno on 2019/8/25.
//
#include <stdio.h>
int main(){
    int a = 2,*p1,**p2;
    p2 = &p1;
    p1 = &a;
    a++;
    printf("%d,%d,%d\n",a,*p1,**p2);
    return 0;
}

