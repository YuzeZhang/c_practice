//
// Created by zeno on 2019/9/2.
//

#include <stdio.h>
void left_move(char* str,int len,int k){
    char temp;
    int count = 0;
    while(count<k) {
        //for (int i = 0; i < k; ++i) {
        temp = str[0];
        for (int j = 0; j < len; ++j) {
            str[j - 1] = str[j];
        }
        str[len - 1] = temp;
        ++count;
    }
}
int main(){
    char str[] = "ABCDEFG";
    int len = sizeof(str)/ sizeof(str[0]) - 1;
    printf("请输入要左旋的字符数：");
    int k;
    scanf("%d",&k);
    left_move(str,len,k);
    printf("\n%s",str);
    return 0;
}
