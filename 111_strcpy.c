//
// Created by zeno on 2019/8/2.
//

#include <string.h>
#include <stdio.h>
int main(){
    char acHello[] = "hello\0world";
    char acNew[15] = {0};
    strcpy(acNew,acHello);
    printf("%d,%d",strlen(acNew), sizeof(acHello));
    return 0;
}
