//
// Created by zeno on 2019/9/4.
//


#include <stdio.h>
#include <assert.h>
char* Strcpy(char* destination,const char* source){
    assert(destination&&source);
    while (*source!='\0'){
        *destination++ = *source++;
    }
    *destination = *source;
    return destination;
}

int main(){
    char str1[] = "ABCDEF";
    char str2[1024] = "abcdef";
    Strcpy(str2,str1);
    printf("%s",str2);
    return 0;
}
