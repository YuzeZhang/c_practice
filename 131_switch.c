//
// Created by zeno on 2019/8/6.
//

#include <stdio.h>
int main(){
    int x = 0;
    switch (++x){
        case 0: ++x;
        case 1: ++x;
        case 2: ++x;
    }
    printf("%d",x);
}
