//
// Created by zeno on 2019/8/21.
//

#include <stdio.h>
int main(){
    int num1 = 10;
    int num2 = 20;
     const int*  p  = &num1;
    //*p = 20;
    p = &num2;
    printf("%d",*p);
    return 0;
}
