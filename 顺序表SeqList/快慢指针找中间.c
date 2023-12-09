// 题目要求：使用快慢指针找到链表的中间节点。

// 思路：我们可以使用两个指针，一个快指针和一个慢指针。快指针每次移动两个节点，慢指针每次移动一个节点。当快指针到达链表的末尾时，慢指针就指向链表的中间节点。

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;      // 结点的数据值
    struct LNode *next; // 下一个结点的指针
} LNode, *LinkList;

// 使用快慢指针找到链表的中间节点
LNode *FindMiddle(LinkList L)
{
    LNode *slow = L, *fast = L; // 创建两个指针，一个快指针和一个慢指针
    while (fast != NULL && fast->next != NULL)
    {                            // 当快指针没有到达链表的末尾
        slow = slow->next;       // 慢指针移动一个节点
        fast = fast->next->next; // 快指针移动两个节点
    }
    return slow; // 返回慢指针，即中间节点
}

int main()
{
    // 创建链表
    LinkList L = (LinkList)malloc(sizeof(LNode)); // 分配内存给头结点
    L->next = NULL;                               // 初始化头结点的next为NULL

    // 添加一些节点到链表（这里添加了5个节点，值为1到5）
    for (int i = 1; i <= 5; i++)
    {
        LNode *node = (LNode *)malloc(sizeof(LNode)); // 分配内存给新节点
        node->data = i;                               // 设置新节点的数据
        node->next = L->next;                         // 将新节点的next指向头结点的next
        L->next = node;                               // 将头结点的next指向新节点
    }

    // 使用快慢指针找到链表的中间节点
    LNode *middle = FindMiddle(L);

    // 打印中间节点的数据
    printf("Middle node data: %d\n", middle->data);

    return 0;
}

// 总结：这个题目考察的是链表的操作和快慢指针的使用。通过快慢指针，我们可以在一次遍历中找到链表的中间节点。关键在于理解快慢指针的工作原理，即快指针每次移动两个节点，慢指针每次移动一个节点，当快指针到达链表的末尾时，慢指针就指向链表的中间节点。
// 时间复杂度：O(n)，其中n为链表的长度。我们需要遍历整个链表，因此时间复杂度为O(n)。
// 空间复杂度：O(1)。我们只使用了常数个额外的变量，因此空间复杂度为O(1)。
