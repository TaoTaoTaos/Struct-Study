#include <stdio.h>
#include <stdlib.h>

// 题目要求：使用栈实现十进制转八进制

// 思路和算法原理：
// 1. 创建一个栈，用于存储每次除以8后的余数。
// 2. 将十进制数除以8，将余数压入栈中，然后更新十进制数为商。
// 3. 重复步骤2，直到十进制数为0。
// 4. 从栈顶开始，依次弹出每个元素，这就是八进制表示。

// 定义栈的结构体
typedef struct Stack
{
    int *arr; // 存储栈的数组
    int top;  // 栈顶指针
} Stack;

// 初始化栈
Stack *initStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));      // 分配内存
    stack->arr = (int *)malloc(sizeof(int) * capacity); // 分配数组内存
    stack->top = -1;                                    // 初始化栈顶指针
    return stack;
}

// 压栈操作
void push(Stack *stack, int value)
{
    stack->arr[++stack->top] = value; // 将值放入栈顶，然后移动栈顶指针
}

// 弹栈操作
int pop(Stack *stack)
{
    return stack->arr[stack->top--]; // 返回栈顶元素，然后移动栈顶指针
}

// 判断栈是否为空
int isEmpty(Stack *stack)
{
    return stack->top == -1; // 如果栈顶指针为-1，那么栈为空
}

int main()
{
    // 输入十进制数
    int decimal;
    printf("请输入一个十进制数：");
    scanf("%d", &decimal);

    // 初始化栈
    Stack *stack = initStack(50);

    // 将十进制数转换为八进制数
    while (decimal != 0)
    {
        push(stack, decimal % 8); // 将余数压入栈(这个余数反着排就是结果)
        decimal /= 8;             //十进制数除以8的整数部分 继续参加下一次 % 8
    }

    // 输出八进制数
    printf("八进制表示为：");
    while (!isEmpty(stack))
    {
        printf("%d", pop(stack)); // 弹出栈顶元素并输出
    }
    printf("\n");

    return 0;
}

// 总结：
// 本题主要考察了栈的基本操作（压栈、弹栈、判断栈是否为空）以及如何使用栈来进行进制转换。
// 其中，关键问题在于如何将十进制数转换为八进制数。这里我们采用的方法是不断地将十进制数除以8，
// 然后将余数压入栈，最后再从栈顶开始依次弹出每个元素，就得到了八进制表示。
