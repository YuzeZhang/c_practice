//
// Created by zeno on 2019/9/6.
//


#include <stdio.h>
#include <assert.h>
char* Strncpy(char* destination,const char* source,size_t num){
    assert(destination&&source&&num);
    for (int i = 0; i <num; ++i) {
        *destination++ = *source++;
    }
    *destination = *source;
    return destination;
}
int main(){
    char str1[] = "To be or not to be";
    char str2[40];
    char str3[40];
    Strncpy(str2,str1, sizeof(str2));
    Strncpy(str3,str2,5);
    str3[5] = '\0';
    puts(str1);
    puts(str2);
    puts(str3);
    return 0;
}
