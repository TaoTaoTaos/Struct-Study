/*
题目要求：
设计一个算法，判断一个单链表是否中心对称。例如链表 1->2->3->2->1 就是中心对称的，但是链表 1->2->3->4->5 就不是。

思路和算法原理：
我们可以使用快慢指针法找到链表的中点，然后把链表的前半部分元素压入栈中，再与链表的后半部分进行比较。

以下是具体的C语言实现：
*/

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点的结构体
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 定义栈的结构体
typedef struct Stack {
    int *data;
    int top;
} Stack;

// 初始化栈
Stack* initStack(int n) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(sizeof(int) * n);
    s->top = -1;
    return s;
}

// 入栈操作
void push(Stack *s, int val) {
    s->data[++s->top] = val;
}

// 出栈操作
int pop(Stack *s) {
    return s->data[s->top--];
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断链表是否中心对称的函数
int isSymmetric(ListNode *head) {
    ListNode *slow = head, *fast = head;
    Stack *s = initStack(100);  // 初始化栈
    //!  使用快慢指针法找到链表的中点
    while (fast && fast->next)  //!快指针非空 且 快指针下一个也不为空
    {
        push(s, slow->val);  //! 把链表的前半部分(slow指过的)元素push到栈中
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast) {
        slow = slow->next;  //   如果链表的长度是奇数，跳过中点
    }
    // 比较链表的后半部分和栈中的元素
    while (slow) {
        if (slow->val != pop(s)) {  // 如果发现不相等的元素，返回0表示不是中心对称
            return 0;
        }
        slow = slow->next;
    }
    return isEmpty(s);  // 如果栈为空，返回1表示是中心对称，否则返回0表示不是中心对称
}

int main() {
    // 测试的链表：1->2->3->2->1
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 1;
    head->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->val = 2;
    head->next->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->next->val = 3;
    head->next->next->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->next->next->val = 2;
    head->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
    head->next->next->next->next->val = 1;
    head->next->next->next->next->next = NULL;
    int result = isSymmetric(head);  // 调用函数判断链表是否中心对称
    printf("%s\n", result ? "是中心对称" : "不是中心对称");  // 输出结果
    return 0;
}

/*
总结：
这个题目考察的是栈和链表的基本操作和性质。栈是一种后进先出（LIFO）的数据结构，可以用来保存链表的前半部分元素。链表是一种线性数据结构，可以用快慢指针法找到链表的中点。

关键问题：
//! 1. 如何找到链表的中点？
我们可以使用快慢指针法找到链表的中点。快指针每次移动两步，慢指针每次移动一步。当快指针到达链表的尾部时，慢指针就到达了链表的中点。

//! 2. 如何判断链表是否中心对称？
我们可以把链表的 前半部分 元素压入栈中，然后与链表的后半部分进行比较。如果发现不相等的元素，那么这个链表就不是中心对称的。如果比较完所有的元素都是相等的，那么这个链表就是中心对称的。
*/
