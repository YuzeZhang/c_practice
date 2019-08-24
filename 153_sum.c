//
// Created by zeno on 2019/8/24.
//
#include <stdio.h>
#define sum(a,b,c) a+b+c
int main(){
    int i = 3;
    int j = 2;
    printf("%d",i*sum(i,(i+j),j));
    return 0;
}

