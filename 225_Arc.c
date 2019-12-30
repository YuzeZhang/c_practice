//
// Created by Zeno on 2019/12/30.
//
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MVNum 100

typedef int Status;
typedef char VerTexType;
typedef int OtherInfo;

typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode, *StackList;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    OtherInfo weight;
}ArcNode;

typedef struct VNode{
    VerTexType data;
    ArcNode *firstarc;
}VNode, AdjList[MVNum];

typedef struct{
    AdjList vertices;
    int vexnum;//������
    int arcnum;//����
}ALGraph;

int indegree[MVNum] = { 0 };

StackList InitStack(StackList* S)
{
S = NULL;
return *S;
}

StackList Push(StackList S, int e)
{
    StackList p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return S;
}

StackList Pop(StackList S, int *e)
{
    StackList p;
    p = S;
    if (!p)
        return ERROR;
    *e = p->data;
    S = S->next;
    free(p);
    return S;
}

int LocateVex(ALGraph *G, VerTexType v)
{
    int i;
    for (i = 0; i < (G->vexnum); i++)
    {
        if (v == G->vertices[i].data)
            return i;
    }
}

void CreateUDG(ALGraph *G)
{
    int i, j, k;
    OtherInfo w;
    VerTexType v1, v2;
    ArcNode *p1;
    printf("�����ܽڵ������ܱ�����");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    fflush(stdin);
    printf("��������ڵ��ֵ��");
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    for (k = 0; k < G->arcnum; k++)
    {
        fflush(stdin);
        printf("����һ���ߵ������ڵ��Լ��ߵ�Ȩֵ��");
        scanf("%c %c %d", &v1, &v2, &w);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = j;
        p1->weight = w;
        p1->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = p1;
        indegree[j]++;
    }
}

Status TopologicalSort(ALGraph G, int *topo)
{
    //����ͼG�����ڽӱ�洢�ṹ
    //��G�޻�·�������G�Ķ����һ���������в�����OK�����򷵻�ERROR
    int i, k;
    int count; //������������
    StackList S;
    ArcNode *p;
    S = NULL;
    for (i = 0; i < G.vexnum; i++) //��������ȶ���ջ S
    {
        if (!indegree[i])
            S = Push(S, i); //���Ϊ0�߽�ջ
    }
    count = 0;//������������
    while (S)
    {
        S = Pop(S, &i);
        topo[count] = i;
        ++count;//����
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            k = p->adjvex;
            --indegree[k]; //��i�Žڵ�ÿ���ڽӵ����ȼ�1
            if (indegree[k] == 0)
                S = Push(S, k); //����ȼ�Ϊ0����ջ
            p = p->nextarc;
        }
    }
    topo[count] = -1;
    if (count < G.vexnum)
        return ERROR;
    else
        return OK;
}


//ȷ���ؼ�·�����ĸ���������
//
//1.�¼�vi�����緢��ʱ��ve(i)��
//
//��������vi��ÿһ���������vi���пɷ���������ve(i)�Ǵ�Դ�㵽vi���·�����ȡ�����v0һ��Ϊ0.
//
//2.�¼�vi����ٷ���ʱ��:
//
//�¼�vi�ķ�����������vi��ÿһ����¼�����ٷ���ʱ�䡣Ϊ�˲������ڣ�vi�����ʱ�䲻�ó��������¼�vk����ٷ���ʱ���ȥ�<vi,vk>�ĳ���ʱ�䡣
//
//3.�ai=<vj,vk>�����翪ʼʱ��e(i):
//
//ֻ���¼�vj�����ˣ��ai���ܿ�ʼ�����Իai�����翪ʼʱ�����ʱ��vj�����緢��ʱ��ve(j)��
//
//4.�a i=<vj,vk>������ʼʱ��l(i):
//
//�a i�Ŀ�ʼʱ����Ҫ��֤������ʱ��vk����ٷ���ʱ�䡣
// ���Իa i������ʼʱ��l(i)����ʱ��vk����ٷ���ʱ��vl(k)��ȥ�ai�ĳ���ʱ��wj,k

//�ж��Ƿ�Ϊ�ؼ�·������pָ���i���ڵ�ĵ�һ���ߡ���p��Ϊ�յ�ʱ����eΪve[i]��
// lΪp�߼�¼����һ���ڵ���¼�������ʱ���ȥp�ߵ�Ȩֵ����e��l���������ߵ��������㡣
// ��pָ����һ���ߡ��ظ����β���ֱ����������йؼ�·����

Status CriticalPath(ALGraph G)//�ؼ�·��
{
    int i, j, k, e, l;
    int *ve, *vl;
    int topo[MVNum];
    ArcNode *p;
    ve = (int *)malloc(sizeof(int)*G.vexnum); //��¼�¼����緢��ʱ��
    vl = (int *)malloc(sizeof(int)*G.vexnum); //��¼�¼�������ʱ��
    if (!TopologicalSort(G, topo))
        return ERROR;
    for (i = 0; i < G.vexnum; i++)//���緢��ʱ���ʼ��Ϊ0
        ve[i] = 0;
    for (i = 0; i < G.vexnum; i++)//ȥ��ʱ��ȡ���ʱ��
    {
        k = topo[i];
        p = G.vertices[k].firstarc;
        while (p)
        {
            j = p->adjvex;
            if (ve[j] < ve[k] + p->weight)
                ve[j] = ve[k] + p->weight;
            p = p->nextarc;
        }
    }
    for (i = 0; i < G.vexnum; i++)
        vl[i] = ve[G.vexnum - 1];//���һ���¼������翪ʼʱ��=����ʼʱ�䣬����������ʱ���ʼ�������һ���¼��Ŀ�ʼʱ�䣨�����ı�־��
    for (i = G.vexnum - 1; i >= 0; i--)//������ʱ��ȡ��Сʱ��
    {
        k = topo[i];
        p = G.vertices[k].firstarc;
        while (p)
        {
            j = p->adjvex;
            if (vl[k]>vl[j] - p->weight)
                vl[k] = vl[j] - p->weight;
            p = p->nextarc;
        }
    }
    //���ڹؼ�����ԣ�e(i)=l(i)�����ڷǹؼ����l(i)-e(i)��ֵ�Ǹù��̵������������˷�Χ�ڵ��ʶ����󲻻�Ӱ���������̵Ĺ���
    for (i = 0; i < G.vexnum; i++)//�Ƚ�������С�������С��ͬʱ���ǹؼ�·��
    {
        p = G.vertices[i].firstarc;
        while (p)
        {
            j = p->adjvex;
            e = ve[i];
            l = vl[j] - p->weight;
            if (e == l)
                printf("%c->%c\n", G.vertices[i].data, G.vertices[j].data);
            p = p->nextarc;
        }
    }
    return OK;
}

int main(void)
{
    ALGraph G;
    CreateUDG(&G);
    if (!CriticalPath(G))
        printf("����\n");
    else
        printf("����\n");
    return 0;
}

