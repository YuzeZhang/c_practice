//
// Created by zeno on 2019/8/4.
//
#include <stdio.h>
int fun(int x){
    int count = 0;
    while (x){
        count++;
        x = x & (x-1);
    }
    return count;
}
int main(){
    printf("fun(2017)=%d\n",fun(2019));
}
