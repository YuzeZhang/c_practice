#include<stdio.h>
void exchange(int* a,int* b){
        *a = *a^*b;
        *b = *a^*b;
        *a = *a^*b;                                                                                                                
}
int main(){
        int a[3] = {1,2,3};
        printf("交换前:a[1]=%d,a[1]=%d\n",a[1],a[1]);
        exchange(&a[1],&a[1]);
        printf("交换后:a[1]=%d,a[1]=%d\n",a[1],a[1]);
        return 0;
}

