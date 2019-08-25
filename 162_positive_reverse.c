//
// Created by zeno on 2019/8/25.
//

#include <stdio.h>
#include <math.h>
int positive_reverse(int num){
    //获取num的位数
    int digits;
    int num_cpy = num;
    for ( digits = 0; num_cpy > 0 ; ++digits) {
        num_cpy/=10;
    }
    int each_digit[1024] = {0};
    for(int digits_cpy = digits, i = 0,num_cpy = num;digits_cpy>0;--digits_cpy,++i){
        if(i == 0){
            each_digit[i] = num/pow(10,(digits_cpy-1));
        } else{
           each_digit[i] = (num_cpy-each_digit[i-1]*pow(10,digits_cpy-1))/pow(10,(digits_cpy-1));
        }
    }
    for (int j = 0; j < digits; ++j) {
        printf("%d,",each_digit[j]);
    }
}
int main(){
    positive_reverse(12321);
}
