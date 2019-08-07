//
// Created by zeno on 2019/8/7.
//

#include <stdio.h>
int main(){
    int s = 0,n;
    for(n = 0;n<4;n++){
        switch (n){
            default:s+=4;
            case 1:s+=1;
            case 2:s+=2;
            case 3:s+=3;
        }
    }
    printf("%d\n",s);
    return 0;
}
