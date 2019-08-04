//
// Created by zeno on 2019/8/4.
//

unsigned long g_ulGlobal = 0;
void GlobalInit(unsigned long ulArg){
    ulArg = 0x01;
    return;
}
void Test(){
    GlobalInit(g_ulGlobal);
    printf("%lu",g_ulGlobal);
    return;
}
int main(){
    Test();
    return 0;
}
