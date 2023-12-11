// 题目要求：设计算法，逆置队列元素
// 思路：我们可以使用栈来帮助我们实现队列的逆置。首先，我们将队列中的所有元素出队并入栈，然后再将栈中的所有元素出栈并入队，这样就完成了队列的逆置。

#include <stdio.h>  // 引入标准输入输出库
#include <stdlib.h> // 引入标准库

#define MAX 100 // 定义队列和栈的最大容量

typedef struct
{                  // 定义队列结构体
    int data[MAX]; // 队列数据
    int front;     // 队首指针
    int rear;      // 队尾指针
} Queue;

typedef struct
{                  // 定义栈结构体
    int data[MAX]; // 栈数据
    int top;       // 栈顶指针
} Stack;

void initQueue(Queue *q)
{ // 初始化队列
    q->front = 0;
    q->rear = 0;
}

void initStack(Stack *s)
{ // 初始化栈
    s->top = -1;
}

void push(Stack *s, int x)
{ // 入栈操作
    if (s->top == MAX - 1)
    { // 栈满
        printf("Stack overflow.\n");
        return;
    }
    s->data[++(s->top)] = x; // 入栈
}

int pop(Stack *s)
{ // 出栈操作
    if (s->top == -1)
    { // 栈空
        printf("Stack underflow.\n");
        return -1;
    }
    return s->data[(s->top)--]; // 出栈
}

void enqueue(Queue *q, int x)
{ // 入队操作
    if ((q->rear + 1) % MAX == q->front)
    { // 队列满
        printf("Queue overflow.\n");
        return;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX; // 循环队列
}

int dequeue(Queue *q)
{ // 出队操作
    if (q->front == q->rear)
    { // 队列空
        printf("Queue underflow.\n");
        return -1;
    }
    int x = q->data[q->front];
    q->front = (q->front + 1) % MAX; // 循环队列
    return x;
}

void reverseQueue(Queue *q)
{ // 逆置队列
    Stack s;
    initStack(&s);
    while (q->front != q->rear)
    {                         // 队列不空
        push(&s, dequeue(q)); // 出队并入栈
    }
    while (s.top != -1)
    {                        // 栈不空
        enqueue(q, pop(&s)); // 出栈并入队
    }
}

int main()
{ // 主函数
    Queue q;
    initQueue(&q);
    for (int i = 1; i <= 5; i++)
    { // 将1到5入队
        enqueue(&q, i);
    }
    reverseQueue(&q); // 逆置队列
    while (q.front != q.rear)
    { // 打印队列
        printf("%d ", dequeue(&q));
    }
    return 0;
}
// 总结：本题主要考察了队列和栈的基本操作，以及如何利用栈来实现队列的逆置。关键在于理解栈和队列的特性，栈是后进先出，队列是先进先出，因此可以通过栈来实现队列的逆置。
