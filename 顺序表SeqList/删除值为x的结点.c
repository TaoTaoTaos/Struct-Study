// 题目要求：设计算法void Deletex(LinkList &L,ElemType x,int & count)删除带头结点的单链表L中数据值为x的所有结点,并将删除的结点个数通过参数count返回。

// 思路：我们可以使用双指针的方式来解决这个问题。首先，我们创建两个指针，一个指向当前节点，另一个指向前一个节点。然后，我们遍历链表，如果当前节点的数据等于x，我们就删除当前节点，并将前一个节点的next指向当前节点的next，同时count加1。

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;      // 结点的数据值
    struct LNode *next; // 下一个结点的指针
} LNode, *LinkList;

// 删除带头结点的单链表L中数据值为x的所有结点,并将删除的结点个数通过参数count返回
void Deletex(LinkList L, ElemType x, int *count)
{
    LNode *p = L->next, *pre = L; // 创建两个指针，一个指向当前节点，另一个指向前一个节点
    *count = 0;                   // 初始化计数器
    while (p != NULL)
    { // 遍历链表
        if (p->data == x)
        {                        // 如果当前节点的数据等于x
            pre->next = p->next; // 将前一个节点的next指向当前节点的next
            free(p);             // 释放当前节点
            p = pre->next;       // 更新当前节点
            (*count)++;          // 计数器加1
        }
        else
        {                // 如果当前节点的数据不等于x
            pre = p;     // 更新前一个节点
            p = p->next; // 更新当前节点
        }
    }
}

int main()
{
    // 创建链表
    LinkList L = (LinkList)malloc(sizeof(LNode)); // 分配内存给头结点
    L->next = NULL;                               // 初始化头结点的next为NULL

    // 添加一些节点到链表（这里添加了5个值为1的节点）
    for (int i = 0; i < 5; i++)
    {
        LNode *node = (LNode *)malloc(sizeof(LNode)); // 分配内存给新节点
        node->data = 1;                               // 设置新节点的数据
        node->next = L->next;                         // 将新节点的next指向头结点的next
        L->next = node;                               // 将头结点的next指向新节点
    }

    // 删除值为1的节点
    int count;
    Deletex(L, 1, &count);

    // 打印删除的节点数
    printf("Deleted %d nodes.\n", count);

    return 0;
}

// 总结：这个题目考察的是链表的操作和双指针的使用。通过双指针，我们可以在遍历链表的同时删除满足条件的节点。关键在于理解双指针的工作原理，即前一个指针用于记录当前节点的前一个节点，以便在删除当前节点后更新其next指针。此外，我们还需要注意在删除节点后释放其内存，防止内存泄漏。
// 时间复杂度：O(n)，其中n为链表的长度。我们需要遍历整个链表，因此时间复杂度为O(n)。
// 空间复杂度：O(1)。我们只使用了常数个额外的变量，因此空间复杂度为O(1)。
