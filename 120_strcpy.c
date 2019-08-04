//
// Created by zeno on 2019/8/4.
//
#include <stdio.h>
#include <string.h>
int main(){
    char arr[2][4];
    strcpy((char*)arr,"you");
    strcpy(arr[1],"me");
    arr[0][3] = '&';
    printf("%s\n",arr);
    return 0;
}
