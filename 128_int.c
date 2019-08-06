//
// Created by zeno on 2019/8/6.
//

#include <stdio.h>
#include <stdlib.h>
int a = 1;
void test(){
    int a = 2;
    a+=1;
}
int main(){
    test();
    printf("%d\n",a);
    return 0;
}
