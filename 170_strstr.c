//
// Created by zeno on 2019/9/6.
//

#include <stdio.h>
#include <assert.h>
char* Strstr(const char* str1, const char* str2){
    assert(str1&&str2);
    char* sign = str1;
    char* dp1 = sign;
    char* dp2 = str2;
    while (*dp1!='\0'){
        while ((*dp1==*dp2)&&(*dp1!='\0')&&(*dp2!='\0')){
            ++dp1;
            ++dp2;
        }
        if (*dp2 == '\0'){
            return sign;
        }
        dp2 = str2;
        ++sign;
        dp1 = sign;
    }
    return NULL;
}
int main(){
    char str[] = "This is a simple string";
    char* pch = Strstr(str,"simple");
    printf("%s",pch);
    return 0;
}
