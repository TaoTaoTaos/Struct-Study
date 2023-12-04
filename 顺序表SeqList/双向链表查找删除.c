// 题目要求：设计算法 int DeleteDul(DLinkList &L,int i,Elem Type &x)实现将一个带头结点的双向循环链表L的第i个结点删除，并将删除结点的数据值通过引用参数返回。若删除成功，函数返回1，否则函数返回0.
// 思路：首先，我们需要找到第i个节点。然后，我们将该节点的前驱节点的后继指针指向该节点的后继节点，并将该节点的后继节点的前驱指针指向该节点的前驱节点。最后，我们删除该节点，并将其数据值返回。

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义元素类型为整型
typedef struct DLnode
{
    ElemType data;        // 数据域
    struct DLnode *prior; // 前驱结点指针
    struct DLnode *next;  // 后继结点指针
} DLnode, *DLinkList;     // 定义双向循环链表的结点类型和指针类型

int DeleteDul(DLinkList *L, int i, ElemType *x)
{
    DLinkList p = (*L)->next; // p指向第一个节点
    int j = 1;
    // 寻找第i个节点
    while (p != *L && j < i)
    { // 当p不为空且未到达位置i时，继续向后查找
        p = p->next;
        ++j;
    }
    if (p == *L || j > i)
        return 0; // 未找到第i个元素，删除失败
    // 删除操作
    *x = p->data;              // 保存被删除节点的数据值
    p->prior->next = p->next;  // 将被删除节点的前驱节点的后继指针指向被删除节点的后继节点
    p->next->prior = p->prior; // 将被删除节点的后继节点的前驱指针指向被删除节点的前驱节点
    free(p);                   // 释放被删除节点的内存空间
    return 1;                  // 删除成功
}

int main()
{
    // 创建一个带头结点的双向循环链表
    DLinkList L = (DLinkList)malloc(sizeof(DLnode));
    L->prior = L;
    L->next = L;

    // 添加一些元素到链表中
    for (int i = 1; i <= 5; ++i)
    {
        DLinkList newNode = (DLinkList)malloc(sizeof(DLnode));
        newNode->data = i;

        // 将新节点插入到链表的末尾
        newNode->prior = L->prior;
        newNode->next = L;
        L->prior->next = newNode;
        L->prior = newNode;
    }

    // 删除第3个元素
    ElemType x;
    int i = 3;
    if (DeleteDul(&L, i, &x))
    {
        printf("成功删除第%d个元素，其值为%d\n", i, x);
    }
    else
    {
        printf("删除失败\n");
    }

    // 释放链表占用的内存
    while (L->next != L)
    {
        DLinkList p = L->next;
        L->next = p->next;
        free(p);
    }
    free(L);

    return 0;
}

// 总结：本题主要考察了双向循环链表的删除操作。关键在于正确处理被删除节点的前驱节点和后继节点的指针，以及释放被删除节点的内存空间。此外，还需要注意的是，删除操作可能会失败，当链表为空或者i超出链表长度时，应返回0表示删除失败。
