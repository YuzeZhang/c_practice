//
// Created by Zeno on 2019/11/7.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1

typedef struct pNode{
    //����һԪ����ʽ
    int coef; //ϵ��
    int exp;//ָ��
    struct pNode* link;
}pNode;

typedef struct{
    int n;
    struct pNode *head;
}polynominal;

void Create(polynominal *p){
    //���ɱ�ͷ���{
    pNode *pn,*pre,*q;
    p->head=malloc(sizeof(pNode));
    p->head->exp=-1;
    p->head->link=NULL;
    for(int i = 0;i < 1;++i){
        pn=malloc(sizeof(pNode));
        printf("coef:\n");
        scanf("%d",&pn->coef);//�������ϵ��
        printf("exp:\n");
        scanf("%d",&pn->exp);//�������ָ��
        if (pn->exp<0) break;//��������ָ���������������
        pre=p->head;
        q=p->head->link;
        while(q&&q->exp>pn->exp){
        //�������֤����ʽ�ĸ���Ϊ��������
            pre=q;
            q=q->link;
        }
        pn->link=q;
        pre->link=pn;
    }
}
void Add(polynominal *px,polynominal *qx){
    //��Ӳ���
    pNode *q,*q1=qx->head,*p,*temp;//q1ָ���ͷ���
    p=px->head->link;//pָ�����ʽpx�ĵ�һ�����
    q=q1->link;//q1��q��ǰ��
    while(p && q){
        //while(p->exp < q->exp){
        //    //����q->exp�����
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
            temp=malloc(sizeof(pNode));//�����µ�һά����
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
    //����ʽ�������
    pNode *q;
    if(!p->head->link)//�ж϶���ʽ�Ƿ�Ϊ��
    return ;
    q=p->head->link;//���������һ��
    printf("%d*x^%d",q->coef,q->exp);
    q=q->link;
    while(q){
        if(q->exp==0)//�Գ���������
            if(q->coef>0)//����ϵ��>0�����
                printf("+%d",q->coef);
            else printf("%d",q->coef);//����ϵ��<0�����
        else if(q->coef>0)//�ǳ�������ϵ��>0���
            printf("+%d*x^%d",q->coef,q->exp);
        else//�ǳ�����ϵ��<0�����
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
