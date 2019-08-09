//
// Created by zeno on 2019/8/20.
//

#include <stdio.h>
int main(){
    char* str[3] = {"stra","strb","strc"};
    char* p = str[0];
    int i = 0;
    while (i<3){
        printf("%s ",p++);
        i++;
    }
    return 0;
}
