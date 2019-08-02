//
// Created by zeno on 2019/8/2.
//
#include <stdio.h>
int main(){
    int x,y,z;
    x=z=2,y=3;
    if(x>y)
        z = 1;
    else if(x == y)
        z = 0;
    else
        z = -1;
    printf("%d",z);
    return 0;
}
