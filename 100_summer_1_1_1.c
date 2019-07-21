//
// Created by zeno on 2019/7/19.
//
#include <stdio.h>
int main(){
    int a[] ={2,4,6,8,10,12,14,16,18,20,22,24},*q[4],k;
    for (int k = 0; k < 4; ++k) {
        q[k] = &a[k*3];
    }
    printf("%d\n",q[3][1]);
    return 0;
}
