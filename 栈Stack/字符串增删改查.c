/*
题目要求：
假设一个序列为HSSHHHS，运用栈的知识，编写算法将S全部提到H之前,即为SSSHHHH。

思路和算法原理：
我们可以使用两个栈来解决这个问题。首先，遍历序列，把所有的H压入第一个栈，把所有的S压入第二个栈。然后，依次从两个栈中弹出元素，先弹出所有的S，再弹出所有的H。

以下是具体的C语言实现：
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义栈的结构体
typedef struct Stack
{
    char *data;
    int top;
    
} Stack;

// 初始化栈
Stack *initStack(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (char *)malloc(sizeof(char) * n);
    s->top = -1;
    return s;
}

// 入栈操作
void push(Stack *s, char val)
{
    s->data[++s->top] = val;
}

// 出栈操作
char pop(Stack *s)
{
    return s->data[s->top--];
}

// 判断栈是否为空
int isEmpty(Stack *s)
{
    return s->top == -1;
}

int main()
{
    char seq[] = "HSSHHHS";                       // 原始序列
    int n = strlen(seq);                          // 序列的长度
    Stack *s1 = initStack(n), *s2 = initStack(n); // 初始化两个栈
    for (int i = 0; i < n; i++)
    { // 遍历序列
        if (seq[i] == 'H')
        { // 如果是H，压入第一个栈
            push(s1, seq[i]);
        }
        else if (seq[i] == 'S')
        { // 如果是S，压入第二个栈
            push(s2, seq[i]);
        }
    }
    while (!isEmpty(s2))
    { // 先弹出所有的S
        printf("%c", pop(s2));
    }
    while (!isEmpty(s1))
    { // 再弹出所有的H
        printf("%c", pop(s1));
    }
    printf("\n"); // 输出换行符
    return 0;
}

/*
总结：
这个题目考察的是栈的基本操作和性质。栈是一种后进先出（LIFO）的数据结构，可以用来保存序列的元素。通过控制入栈和出栈的顺序，我们可以实现将S全部提到H之前。

关键问题：
//! 1. 如何保存序列的元素？
我们可以使用两个栈来保存序列的元素。遍历序列，把所有的H压入第一个栈，把所有的S压入第二个栈。

//! 2. 如何实现将S全部提到H之前？
我们可以依次从两个栈中弹出元素，先弹出所有的S，再弹出所有的H。这样，就可以实现将S全部提到H之前。
*/
