//
// Created by zeno on 2019/8/7.
//

#include <stdio.h>
#include <string.h>
int main(){
    char* pcColor = "blue1";
    char acColor[] = "blue1";
    printf("%d\n",strlen(pcColor));
    printf("%d\n",strlen(acColor));
    printf("%d\n", sizeof(pcColor));
    printf("%d\n", sizeof(acColor));
}
