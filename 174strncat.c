//
// Created by zeno on 2019/9/6.
//

#include <stdio.h>
#include <assert.h>
#include <string.h>
char* Strncat(char* destination, const char* source,size_t num){
    assert(destination&&source&&num);
    char* flag = destination;
    while (*flag!='\0'){
       ++flag;
    }
    for (int i = 0; i < num; ++i) {
        *flag = *source;
        ++flag;
        ++source;
    }
}
int main(){
    char str1[20];
    char str2[20];
    strcpy(str1,"To be ");
    strcpy(str2,"or not to be.");
    strncat(str1,str2,6);
    puts(str1);
    return 0;
}
