//
// Created by Zeno on 2019/10/8.
//

#include "201_BinaryTreeLevelOrder.h"
#include "186_Queue.h"

//层序遍历
void BinaryTreeLevelOreder(BTNode* root){
    Queue q;
    QueueInit(&q);
    //根节点入队
    if(root)
        QueuePush(&q,root);
    while(QueueEmpty(&q) == 0){
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
    }
}
