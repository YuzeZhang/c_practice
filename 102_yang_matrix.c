//
// Created by zeno on 2019/7/21.
//
#include <stdio.h>
#define true 1
#define false 0
#define ROW 4
#define COL 4
typedef int boolean;
boolean Yang_search(int a[ROW][COL],int to_find,int* row_found,int* col_found){
    if(to_find<a[0][0] || to_find>a[ROW][COL]){
        return false;
    }
    //�����Ͻǿ�ʼ��
    int row = 0;
    int col = COL-1;
    while (row<ROW&&col>=0){
        if(to_find == a[row][col]){
            *row_found = row;
            *col_found = col;
            return true;
        } else if(to_find<a[row][col]){
            --col;//Ҫ�ҵ�ֵ�ȵ�ǰֵС���ڸ��е������
        } else if(to_find>a[row][col]){
            ++row;//Ҫ�ҵ�ֵ�ȵ�ǰֵ�����ڸ��е��²���
        }
    }
    return false;
}
int main(){
    int a[4][4] = {1,2,8,9,
                   2,4,9,12,
                   4,7,10,13,
                   6,8,11,15};
    int row_found = -1;
    int col_found = -1;
    int to_find = 10;
    boolean ret = Yang_search(a,to_find,&row_found,&col_found);
    if(ret){
        printf("���ҵ�%d,λ��Ϊ%d,%d\n",to_find,row_found,col_found);
    } else{
        printf("û���ҵ�%d!",to_find);
    }
    return 0;
}

