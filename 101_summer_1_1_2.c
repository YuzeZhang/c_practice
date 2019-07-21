//
// Created by zeno on 2019/7/19.
//
#include <stdio.h>
int main(){
    int i,j,a = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(j%2)
                break;
            a++;
        }
        a++;
    }
    printf("%d\n",a);
}
