//
// Created by zeno on 2019/8/5.
//

#include <stdio.h>
int x = 3;
void inc(){
    static  int x =1;
    x*=(x+1);
    printf("%d",x);
    return;
}
int main(){
    int i;
    for ( i = 0; i < x ; i++) {
        inc();
    }
    return 0;
}
