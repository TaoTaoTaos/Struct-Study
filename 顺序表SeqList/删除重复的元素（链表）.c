/*
题目要求：删除两个有序链表a和b中相同的节点。

思路：
1. 初始化两个指针，分别指向链表a和b的开始位置。
2. 比较两个指针所指向的节点的值，如果两个值相等，则删除节点，并将两个指针都向右移动一位。
3. 如果a->val小于b->val，将指针a向右移动一位。
4. 如果a->val大于b->val，将指针b向右移动一位。
5. 当一个链表遍历完后，停止操作。

注意：在删除节点时，需要修改前一个节点的next指针，以保持链表的连续性。
*/

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct ListNode
{
    int val;
    struct ListNode *next;
};

void deleteSame(struct ListNode *a, struct ListNode *b)
{
    struct ListNode *p = a, *q = b;
    struct ListNode *pre_p = NULL, *pre_q = NULL;

    // 遍历链表a和b
    while (p != NULL && q != NULL)
    {
        // 如果p->val等于q->val，删除p和q，并将两个指针都向右移动一位
        if (p->val == q->val)
        {
            if (pre_p != NULL)
            {
                pre_p->next = p->next;
            }
            if (pre_q != NULL)
            {
                pre_q->next = q->next;
            }
            struct ListNode *temp_p = p, *temp_q = q;
            p = p->next;
            q = q->next;
            free(temp_p);
            free(temp_q);
        }
        // 如果p->val小于q->val，将指针p向右移动一位
        else if (p->val < q->val)
        {
            pre_p = p;
            p = p->next;
        }
        // 如果p->val大于q->val，将指针q向右移动一位
        else
        {
            pre_q = q;
            q = q->next;
        }
    }
}

/*
总结：
本题主要考察了链表的基本操作和双指针技巧。关键在于如何在遍历两个链表的过程中，删除两个链表中相同的节点。
这里的处理方法是：使用两个指针，分别指向链表a和b的开始位置，然后比较两个指针所指向的节点的值，如果两个值相等，则删除节点，并将两个指针都向右移动一位。
这样，当遍历完两个链表后，就删除了两个链表中相同的节点。
*/
