//
// Created by zeno on 2019/9/2.
//

#include <stdio.h>
#include <assert.h>
#include <string.h>
void left_move_once(char*str,int len){
    char temp;
    temp = str[0];
    for (int j = 0; j < len; ++j) {
        str[j - 1] = str[j];
    }
    str[len-1] = temp;

}
int is_left_move(char* str1,char* str2,int len1,int len2){
    assert(str1&&str2);
    if(len1!=len2){
        return 0;
    }
    for (int i = 0; i < len1; ++i) {
        left_move_once(str2,len1);
        if(strcmp(str1,str2)==0){
            return 1;
        }
    }
    return 0;
}
int main(){
    char str1[] = "ABCD";
    char str2[] = "BCDA";
    int len1 = sizeof(str1)/ sizeof(str1[0])-1;
    int len2 = sizeof(str2)/ sizeof(str2[0])-1;
    int ret = is_left_move(str1,str2,len1,len2);
    printf("%d",ret);
    return 0;
}
