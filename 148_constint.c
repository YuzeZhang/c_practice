//
// Created by zeno on 2019/8/22.
//

#include <stdio.h>
int main(){
    const int i = 0;
    int* j = (int*) &i;
    *j = 1;
    printf("%d,%d",i,*j);
    return 0;
}
