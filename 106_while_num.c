//
// Created by zeno on 2019/7/27.
//
#include <stdio.h>
int main(){
    int i = 0;
    while (i < 10){
        if(i<1){
            continue;
        }
        if(i == 5){
            break;
        }
        i++;
    }
    printf("%d",i);
    return 0;
}
