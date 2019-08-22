//
// Created by zeno on 2019/8/22.
//

#include <stdio.h>
int fun(char* s){
    char* p = s;
    while (*p != '\0'){
        p++;
    }
    return (p-s);
}
int main(){
    printf("%d\n",fun("goodbye!"));
}
