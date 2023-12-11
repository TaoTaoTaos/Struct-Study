/*
题目要求：找到两个单链表相交的结点

思路：
1. 首先遍历两个链表，得到它们的长度
2. 让较长的链表先走若干步，使得两个链表剩余的长度相等
3. 然后两个链表同时向前走，每次一步，当它们相遇时，所在的位置就是第一个公共结点
*/

#include <stdio.h>
#include <stdlib.h>

// 定义链表结点
struct ListNode
{
    int val;
    struct ListNode *next;
};

// 找到两个单链表相交的结点
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    // 初始化两个指针pA和pB分别指向链表A和B的头结点
    struct ListNode *pA = headA, *pB = headB;
    while (pA != pB)
    {
        // 指针pA和pB分别向前走一步
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
        
        /*
这两行代码的含义是：
1. 如果指针pA不为NULL，那么将pA移动到下一个结点，即pA = pA->next。
   如果指针pA为NULL（表示已经遍历完链表A），那么将pA移动到链表B的头结点，即pA = headB。
2. 同理，如果指针pB不为NULL，那么将pB移动到下一个结点，即pB = pB->next。
   如果指针pB为NULL（表示已经遍历完链表B），那么将pB移动到链表A的头结点，即pB = headA。

这样做的目的是：当pA和pB分别遍历完链表A和B后，它们会跳到另一个链表的头结点，继续向前走。
这就保证了pA和pB走过的路径长度是相同的，即两个链表的长度之和。
因此，如果链表A和B相交，那么pA和pB一定会在第一个公共结点相遇。
*/

    }
    // 如果链表A和B有交点，返回交点，否则返回NULL
    return pA;
}

/*
总结：
本题主要考察了链表的基本操作和双指针技巧。关键在于如何巧妙地处理两个链表长度不等的情况。
这里的处理方法是：两个指针分别从链表A和B的头结点开始向前走，如果到达链表的末尾，则跳到另一个链表的头结点继续向前走。
这样，当两个指针相遇时，所在的位置就是第一个公共结点。
*/
