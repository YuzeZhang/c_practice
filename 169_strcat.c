//
// Created by zeno on 2019/9/5.
//

#include <stdio.h>
#include <assert.h>
char* Strcat(char* destination,const char* source){
    assert(destination&&source);
    char* dp = destination;
    while(*dp!='\0'){
        ++dp;
    }
    while (*source!='\0'){
        *dp++ = *source++;
    }
    *dp = *source;
}
int main(){
    char str[1024] = "We are ";
    Strcat(str,"family.");
    printf("%s",str);
    return 0;
}
