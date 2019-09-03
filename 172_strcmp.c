//
// Created by zeno on 2019/9/6.
//

#include <stdio.h>
#include <assert.h>
int Strcmp(const char* str1,const char* str2){
    assert(str1&&str2);
    char* dp1 = str1;
    char* dp2 = str2;
    while(*dp1!='\0'&&*dp2!='\0'){
        if(*dp1==*dp2){
            ++dp1;
            ++dp2;
        }else if(*dp1 > *dp2){
            return 1;
        }else if(*dp1 < *dp2){
            return -1;
        }
    }
    return 0;
}
int main(){
    char key[] = "apple";
    char buffer[80];
    do{
        printf("Guess my favorite fruit?");
        fflush(stdout);
        scanf("%79s",buffer);
    }while (Strcmp(key,buffer)!=0);
    puts("Correct answer!");
    return 0;
}
