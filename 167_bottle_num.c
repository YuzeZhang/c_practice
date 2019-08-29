//
// Created by zeno on 2019/9/4.
//
#include <stdio.h>
int bootle_num(int money){
    if(money){
        while (money!=1){
            if(money%2!=0){
                return money-1 + bootle_num(money/2+1);
            } else{
                return money + bootle_num(money/2);
            }
        }
        return 1;
    }
    return 0;
}
int main(){
    int money;
    printf("please enter your money:");
    scanf("%d",&money);
    printf("%d",bootle_num(money));
    return 0;
}

