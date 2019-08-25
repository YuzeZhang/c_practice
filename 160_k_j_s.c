//
// Created by zeno on 2019/8/25.
//

#include <stdio.h>
int main(){
    int k,j,s;
    for(k = 2;k < 6;k++,k++){
        s = 1;
        for(j = k;j<6;j++)
            s+=j;
    }
    printf("%d",s);
    return 0;
}
