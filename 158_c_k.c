//
// Created by zeno on 2019/8/25.
//

#include <stdio.h>
int main(){
    int c[] = {1,3,5};
    int* k = c+1;
    printf("%d",*++k);
    return 0;
}
