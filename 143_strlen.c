//
// Created by zeno on 2019/8/20.
//

#include <stdio.h>
#include <string.h>
int main(){
    char a[1000];
    int i;
    for(i = 0;i < 1000;i++){
        a[i] = (char)(-1-i);
    }
    printf("%d\n",strlen(a));
    return 0;
}
