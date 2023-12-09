// 题目要求：使用链式存储实现线性表的基本操作，包括初始化、插入、删除和查找。

// 思路：使用链表来实现线性表，链表的每个节点包含一个数据元素和一个指向下一个节点的指针。

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点的数据结构
typedef struct LNode
{
    int data;           // 数据元素
    struct LNode *next; // 指向下一个节点的指针
} LNode;

// 初始化链表
LNode *InitList()
{
    LNode *head = (LNode *)malloc(sizeof(LNode)); // 创建头节点
    head->next = NULL;                            // 头节点的指针域为空
    return head;
}

// 在链表的第i个位置插入元素e
void ListInsert(LNode *head, int i, int e)
{
    LNode *p = head;
    int j = 0;
    while (p && j < i - 1)
    { // 寻找第i-1个节点
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
    { // 如果i小于1或者大于表长+1
        return;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
    s->data = e;                               // 将e赋值给新节点
    s->next = p->next;                         // 将p的后继节点赋值给s的后继
    p->next = s;                               // 将s赋值给p的后继
}

// 删除链表的第i个元素
void ListDelete(LNode *head, int i)
{
    LNode *p = head;
    int j = 0;
    while (p->next && j < i - 1)
    { // 寻找第i-1个节点
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
    { // 如果i小于1或者大于表长+1
        return;
    }
    LNode *q = p->next; // 临时保存被删除节点的位置
    p->next = q->next;  // 将q的后继赋值给p的后继
    free(q);            // 释放被删除节点的内存空间
}

// 查找元素e在链表中的位置
int LocateElem(LNode *head, int e)
{
    LNode *p = head->next;
    int i = 1;
    while (p)
    {
        if (p->data == e)
        {
            return i;
        }
        p = p->next;
        ++i;
    }
    return 0;
}

int main()
{
    LNode *L = InitList();       // 创建一个链表
    ListInsert(L, 1, 10);        // 在第1个位置插入10
    ListInsert(L, 2, 20);        // 在第2个位置插入20
    ListDelete(L, 1);            // 删除第1个元素
    int pos = LocateElem(L, 20); // 查找20在链表中的位置
    printf("The position of 20 is %d\n", pos);
    return 0;
}

//! 总结
// 本题主要考察了使用链式存储实现线性表的基本操作，包括初始化、插入、删除和查找。链表是一种动态数据结构，它不需要在创建时就确定大小，而是可以根据需要动态地分配内存和释放内存。
// 在链表中插入和删除元素时，只需要修改相应节点的指针，不需要移动元素，因此效率较高。但是查找元素时，需要从头节点开始逐个遍历，效率较低。
// 通过本题，我们可以理解链表的基本概念和操作，以及链表和数组在实现线性表时的优缺点。
