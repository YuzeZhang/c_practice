//
// Created by zeno on 2019/8/3.
//

#include <stdio.h>
#define F(X,Y) ((X)+(Y))
int main(){
    int a =3,b = 4;
    printf("%d\n",F(a++,b++));
    return 0;
}
