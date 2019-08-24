//
// Created by zeno on 2019/8/24.
//

#include <stdio.h>
#define MA(X,Y) (X*Y)
int main(){
    int i = 5;
    i = MA(i,i+1);
    i = i-7;
    printf("%d",i);
    return 0;
}
