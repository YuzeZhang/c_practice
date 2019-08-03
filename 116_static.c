//
// Created by zeno on 2019/8/3.
//

#include <stdio.h>
int fun(int x,int y){
    static int m = 0;
    static int i = 2;
    i+= m+1;
    m = i+x+y;
    return m;
}
void main(){
    int j = 4;
    int m = 1;
    int k;
    k = fun(j,m);
    printf("%d,",k);
    k = fun(j,m);
    printf("%d\n",k);
}
