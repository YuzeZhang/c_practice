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
    int vexnum;//顶点数
    int arcnum;//弧数
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
    printf("输入总节点数和总边数：");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    fflush(stdin);
    printf("输入各个节点的值：");
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }
    for (k = 0; k < G->arcnum; k++)
    {
        fflush(stdin);
        printf("输入一条边的两个节点以及边的权值：");
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
    //有向图G采用邻接表存储结构
    //若G无回路，则输出G的顶点的一个拓扑序列并返回OK，否则返回ERROR
    int i, k;
    int count; //对输出顶点计数
    StackList S;
    ArcNode *p;
    S = NULL;
    for (i = 0; i < G.vexnum; i++) //创建零入度顶点栈 S
    {
        if (!indegree[i])
            S = Push(S, i); //入度为0者进栈
    }
    count = 0;//对输出顶点计数
    while (S)
    {
        S = Pop(S, &i);
        topo[count] = i;
        ++count;//计数
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            k = p->adjvex;
            --indegree[k]; //对i号节点每个邻接点的入度减1
            if (indegree[k] == 0)
                S = Push(S, k); //若入度减为0则入栈
            p = p->nextarc;
        }
    }
    topo[count] = -1;
    if (count < G.vexnum)
        return ERROR;
    else
        return OK;
}


//确定关键路径的四个描述量：
//
//1.事件vi的最早发生时间ve(i)：
//
//进入世界vi的每一活动都结束，vi才有可发生，所以ve(i)是从源点到vi的最长路径长度。其中v0一般为0.
//
//2.事件vi的最迟发生时间:
//
//事件vi的发生不得延误vi的每一后继事件的最迟发生时间。为了不延误工期，vi的最迟时间不得迟于其后继事件vk的最迟发生时间减去活动<vi,vk>的持续时间。
//
//3.活动ai=<vj,vk>的最早开始时间e(i):
//
//只有事件vj发生了，活动ai才能开始。所以活动ai的最早开始时间等于时间vj的最早发生时间ve(j)。
//
//4.活动a i=<vj,vk>的最晚开始时间l(i):
//
//活动a i的开始时间需要保证不延误时间vk的最迟发生时间。
// 所以活动a i的最晚开始时间l(i)等于时间vk的最迟发生时间vl(k)减去活动ai的持续时间wj,k

//判断是否为关键路径：将p指向第i个节点的第一条边。当p不为空的时候让e为ve[i]，
// l为p边记录的另一个节点的事件最晚发生时间减去p边的权值，若e和l相等则输出边的两个顶点。
// 让p指向下一条边。重复本段操作直到检测完所有关键路径。

Status CriticalPath(ALGraph G)//关键路径
{
    int i, j, k, e, l;
    int *ve, *vl;
    int topo[MVNum];
    ArcNode *p;
    ve = (int *)malloc(sizeof(int)*G.vexnum); //记录事件最早发生时间
    vl = (int *)malloc(sizeof(int)*G.vexnum); //记录事件最晚发生时间
    if (!TopologicalSort(G, topo))
        return ERROR;
    for (i = 0; i < G.vexnum; i++)//最早发生时间初始化为0
        ve[i] = 0;
    for (i = 0; i < G.vexnum; i++)//去的时候取最大时间
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
        vl[i] = ve[G.vexnum - 1];//最后一个事件的最早开始时间=最晚开始时间，所有最晚发生时间初始化成最后一个事件的开始时间（结束的标志）
    for (i = G.vexnum - 1; i >= 0; i--)//回来的时候取最小时间
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
    //对于关键活动而言，e(i)=l(i)。对于非关键活动，l(i)-e(i)的值是该工程的期限余量，此范围内的适度延误不会影响整个工程的工期
    for (i = 0; i < G.vexnum; i++)//比较最大和最小，最大最小相同时就是关键路径
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
        printf("错误\n");
    else
        printf("结束\n");
    return 0;
}

