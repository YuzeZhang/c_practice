//
// Created by zeno on 2019/8/4.
//

#include <stdio.h>
int Change(int* pX){
    int y = 8;
    y = y - *pX;
    pX = &y;
    return 0;
}
int main(){
    int xx = 3;
    int* pY = &xx;
    Change(pY);
    printf("%d\n",*pY);
    return 0;
}
