//
// Created by Zeno on 2019/10/13.
//
#include <stdio.h>
int Fib(int n){
    int num,num_1 = 1,num_2 = 0;
    for(int i = 2;i <= n;++i){
        num = num_1 + num_2;
        num_2 = num_1;
        num_1 = num;
    }
    return num;
}
int main(){

    return 0;
}
