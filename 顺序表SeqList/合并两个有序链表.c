// 题目要求：合并两个有序链表。

// 思路：我们可以使用一个新的头节点，然后比较两个链表的头节点，将较小的节点添加到新链表的末尾，然后移动较小节点所在的链表的头节点。重复这个过程，直到两个链表的头节点都为空。

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;      // 结点的数据值
    struct LNode *next; // 下一个结点的指针
} LNode, *LinkList;

// 合并两个有序链表
LinkList Merge(LinkList L1, LinkList L2)
{
    LNode *dummy = (LNode *)malloc(sizeof(LNode)); // 创建一个新的头节点
    LNode *tail = dummy;                           // 创建一个指向新链表末尾的指针
    while (L1 != NULL && L2 != NULL)
    { // 当两个链表的头节点都不为空
        if (L1->data < L2->data)
        {                    // 如果L1的头节点的数据小于L2的头节点的数据
            tail->next = L1; // 将L1的头节点添加到新链表的末尾
            L1 = L1->next;   // 移动L1的头节点
        }
        else
        {                    // 如果L1的头节点的数据大于等于L2的头节点的数据
            tail->next = L2; // 将L2的头节点添加到新链表的末尾
            L2 = L2->next;   // 移动L2的头节点
        }
        tail = tail->next; // 移动新链表的末尾指针
    }
    if (L1 != NULL)
    {                    // 如果L1还有剩余节点
        tail->next = L1; // 将L1的剩余节点添加到新链表的末尾
    }
    if (L2 != NULL)
    {                    // 如果L2还有剩余节点
        tail->next = L2; // 将L2的剩余节点添加到新链表的末尾
    }
    return dummy->next; // 返回新链表的头节点
}

// 创建新节点
LinkList createNewNode(ElemType data)
{
    LinkList newNode = (LinkList)malloc(sizeof(LNode)); // 分配内存给新节点
    newNode->data = data;                               // 设置新节点的数据
    newNode->next = NULL;                               // 初始化新节点的next为NULL
    return newNode;                                     // 返回新节点
}

int main()
{
    // 创建两个有序链表
    LinkList L1 = createNewNode(1);
    L1->next = createNewNode(3);
    L1->next->next = createNewNode(5);

    LinkList L2 = createNewNode(2);
    L2->next = createNewNode(4);
    L2->next->next = createNewNode(6);

    // 合并两个有序链表
    LinkList L = Merge(L1, L2);

    // 打印合并后的链表
    LinkList p = L;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}

// 总结：这个题目考察的是链表的操作和合并算法的使用。通过比较两个链表的头节点，我们可以在一次遍历中合并两个有序链表。关键在于理解合并算法的工作原理，即每次都将较小的节点添加到新链表的末尾，然后移动较小节点所在的链表的头节点。
// 时间复杂度：O(n + m)，其中n和m分别为两个链表的长度。我们需要遍历两个链表的所有节点，因此时间复杂度为O(n + m)。
// 空间复杂度：O(1)。我们只使用了常数个额外的变量，因此空间复杂度为O(1)。
