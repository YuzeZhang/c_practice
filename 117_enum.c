//
// Created by zeno on 2019/8/3.
//

#include <stdio.h>
int main(){
    enum ENUM_A{
        X1,
        Y1,
        Z1=5,
        A1,
        B1
    };
    enum ENUM_A enumA = Y1;
    enum ENUM_A enumB = B1;
    printf("%d,%d",enumA,enumB);
    return 0;
}
