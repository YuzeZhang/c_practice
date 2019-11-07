//
// Created by Zeno on 2019/11/7.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1

typedef struct pNode{
    //建立一元多项式
    int coef; //系数
    int exp;//指数
    struct pNode* link;
}pNode;

typedef struct{
    int n;
    struct pNode *head;
}polynominal;

void Create(polynominal *p){
    //生成表头结点{
    pNode *pn,*pre,*q;
    p->head=malloc(sizeof(pNode));
    p->head->exp=-1;
    p->head->link=NULL;
    for(int i = 0;i < 1;++i){
        pn=malloc(sizeof(pNode));
        printf("coef:\n");
        scanf("%d",&pn->coef);//输入项的系数
        printf("exp:\n");
        scanf("%d",&pn->exp);//输入项的指数
        if (pn->exp<0) break;//若输入项指数负数，结果输入
        pre=p->head;
        q=p->head->link;
        while(q&&q->exp>pn->exp){
        //插入项并保证多项式的各项为降幂排列
            pre=q;
            q=q->link;
        }
        pn->link=q;
        pre->link=pn;
    }
}
void Add(polynominal *px,polynominal *qx){
    //相加操作
    pNode *q,*q1=qx->head,*p,*temp;//q1指向表头结点
    p=px->head->link;//p指向多项式px的第一个结点
    q=q1->link;//q1是q的前驱
    while(p && q){
        //while(p->exp < q->exp){
        //    //跳过q->exp大的项
        //    q1=q;
        //    q=q->link;
        //}
        if(p->exp==q->exp){
            q->coef=q->coef+p->coef;
            if(q->coef==0){
                q1->link=q->link ;
                free(q);
                q=q1->link;
                p=p->link;
            }else{
                q1=q;
                q=q->link;
                p=p->link;
            }
        }else{
            temp=malloc(sizeof(pNode));//生成新的一维数组
            temp->coef=p->coef;
            temp->exp=p->exp;
            temp->link=q1->link;
            q1->link=temp;
            p=p->link;
        }
    }
}

int Output(polynominal list1){
    int i=0;
    pNode *pn;
    if(!list1.head)
        return ERROR;
    pn=list1.head;
    for(i=0;i<list1.n;i++){
        pn=pn->link;
        printf("%d,%d",pn->coef,pn->exp);
    }
    return OK;
}
void output(polynominal *p){
    //多项式输出函数
    pNode *q;
    if(!p->head->link)//判断多项式是否为空
    return ;
    q=p->head->link;//单独输出第一项
    printf("%d*x^%d",q->coef,q->exp);
    q=q->link;
    while(q){
        if(q->exp==0)//对常数项的输出
            if(q->coef>0)//常数系数>0的情况
                printf("+%d",q->coef);
            else printf("%d",q->coef);//常数系数<0的情况
        else if(q->coef>0)//非常数项项系数>0情况
            printf("+%d*x^%d",q->coef,q->exp);
        else//非常数项系数<0的情况
            printf("%d*x^%d",q->coef,q->exp);
            q=q->link;
    }
}
int main(){
    polynominal list1;
    polynominal list2;
    Create (&list1);
    printf("\nthe linklist is:");
    output(&list1);
    printf("\n");
    Create (&list2);
    printf("\nthe linklist is:");
    output(&list2);
    printf("\n");
    Add(&list1,&list2);
    printf("the sum is:");
    output(&list2);
    return 0;
}
