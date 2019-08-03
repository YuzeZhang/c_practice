//
// Created by zeno on 2019/8/3.
//

#include <stdio.h>
int main(){
    unsigned x;
    printf("please enter x:");
    scanf("%d",&x);
    int count = 0;
    while (x){
        ++count;
        x = x&(x-1);
    }
    printf("%d",count);
    return 0;
}
