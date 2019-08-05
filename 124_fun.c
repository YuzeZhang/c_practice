//
// Created by zeno on 2019/8/5.
//

#include <stdio.h>
int fun(int a, int b){
    if(a>b){
        return (a+b);
    } else{
        return (a-b);
    }
}
int main(){
    int x =3,y = 8,z =6,r;
    r = fun(fun(x,y),2*z);
    printf("%d\n",r);
    return 0;
}
