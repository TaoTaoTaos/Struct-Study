// 题目要求：使用快慢指针删除链表的倒数第n个节点。

// 思路：我们可以使用两个指针，一个快指针和一个慢指针。首先，快指针先移动n个节点，然后快慢指针同时移动，当快指针到达链表的末尾时，慢指针就指向倒数第n个节点。然后我们就可以删除慢指针指向的节点。

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;      // 结点的数据值
    struct LNode *next; // 下一个结点的指针
} LNode, *LinkList;

// 使用快慢指针删除链表的倒数第n个节点
void DeleteNthFromEnd(LinkList L, int n)
{
    LNode *slow = L, *fast = L; // 创建两个指针，一个快指针和一个慢指针
    for (int i = 0; i < n; i++)
    { // 快指针先移动n个节点
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
        else
        {
            return; // 如果链表的长度小于n，直接返回
        }
    }
    while (fast->next != NULL)
    {                      // 当快指针没有到达链表的末尾
        slow = slow->next; // 慢指针移动一个节点
        fast = fast->next; // 快指针移动一个节点
    }
    LNode *temp = slow->next; // 保存要删除的节点
    slow->next = temp->next;  // 将要删除节点的前一个节点的next指向要删除节点的next
    free(temp);               // 释放要删除的节点
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

    // 使用快慢指针删除链表的倒数第n个节点
    DeleteNthFromEnd(L, 2);

    // 打印删除节点后的链表
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}

// 总结：这个题目考察的是链表的操作和快慢指针的使用。通过快慢指针，我们可以在一次遍历中找到链表的倒数第n个节点并删除它。关键在于理解快慢指针的工作原理，即快指针先移动n个节点，然后快慢指针同时移动，当快指针到达链表的末尾时，慢指针就指向倒数第n个节点。
// 时间复杂度：O(n)，其中n为链表的长度。我们需要遍历整个链表，因此时间复杂度为O(n)。
// 空间复杂度：O(1)。我们只使用了常数个额外的变量，因此空间复杂度为O(1)。
