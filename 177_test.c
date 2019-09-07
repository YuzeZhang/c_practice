//
// Created by zeno on 2019/9/7.
//

#include <stdio.h>
int main(){
    typedef struct test{
        char a;
        int b;
    };
    struct test test1;
    test1.a = 1;
    test1.b = 2;
    printf("%d",sizeof(test1));
    return 0;
}
