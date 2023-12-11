// 题目要求：实现栈的基本操作，包括初始化、入栈、出栈和获取栈顶元素。

// 思路：使用数组来实现栈，数组的最后一个元素作为栈顶。

#include <stdio.h>

#define MAX_SIZE 100 // 定义栈的最大长度

// 定义栈的数据结构
typedef struct
{
    int data[MAX_SIZE]; // 存储数据元素
    int top;            //!   栈顶指针
} Stack;

// 初始化栈
void InitStack(Stack *S)
{
    S->top = -1; //! 初始化栈顶指针为-1
}

// 入栈操作
void Push(Stack *S, int e)
{
    if (S->top == MAX_SIZE - 1)
    { // 如果栈已满，无法入栈
        return;
    }
    S->data[++S->top] = e; // 将元素e入栈
}

// 出栈操作
void Pop(Stack *S)
{
    if (S->top == -1)
    { // 如果栈为空，无法出栈
        return;
    }
    S->top--; //! 出栈
}

// 获取栈顶元素
int GetTop(Stack *S)
{
    if (S->top != -1)
    {                           // 如果栈不为空
        return S->data[S->top]; // 返回栈顶元素
    }
    return -1; // 如果栈为空，返回-1
}

int main()
{
    Stack S;              // 创建一个栈
    InitStack(&S);        // 初始化栈
    Push(&S, 10);         // 入栈10
    Push(&S, 20);         // 入栈20
    Pop(&S);              // 出栈
    int top = GetTop(&S); // 获取栈顶元素
    printf("The top element is %d\n", top);
    return 0;
}

//! 总结
// 本题主要考察了栈的基本操作，包括初始化、入栈、出栈和获取栈顶元素。栈是一种特殊的线性表，它只允许在一端进行插入和删除操作，这一端被称为栈顶。
// 栈是一种后进先出（LIFO）的数据结构，最后入栈的元素最先出栈。因此，栈常被用来处理具有递归或嵌套结构的问题。
// 本题中，我们使用数组来实现栈，数组的最后一个元素作为栈顶。在入栈和出栈操作中
//! 只需要修改栈顶指针，不需要移动元素，因此效率较高。
// 通过本题，我们可以理解栈的基本概念和操作，以及栈在解决问题中的应用。
