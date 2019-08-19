//
// Created by zeno on 2019/8/22.
//
#include <stdio.h>
int f(int x,int y){
    return (x&y)+((x^y)>>1);
}
int main(){
    int result = f(2,4);
    printf("%d\n",result);
    return 0;
}

