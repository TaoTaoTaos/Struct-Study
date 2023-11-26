#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void DeleteMax(LinkList *L)
{
    LNode *p = (*L)->next, *pre = *L; // p用来遍历链表，pre记录p的前驱
    LNode *maxp = p, *maxpre = pre;   // maxp用来记录最大节点，maxpre记录最大节点的前驱
    while (p != NULL)
    {
        if (p->data > maxp->data)
        {                 // 如果当前节点的数据大于最大节点的数据
            maxp = p;     // 更新最大节点
            maxpre = pre; // 更新最大节点的前驱
        }
        pre = p; // 移动pre和p
        p = p->next;
    }
    maxpre->next = maxp->next; // 删除最大节点
    free(maxp);                // 释放最大节点的内存
}