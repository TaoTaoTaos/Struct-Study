// 题目要求：实现队列的基本操作，包括初始化、入队、出队和获取队头元素。

// 思路：使用数组来实现队列，数组的第一个元素作为队头，最后一个元素作为队尾。

#include <stdio.h>

#define MAX_SIZE 100 // 定义队列的最大长度

// 定义队列的数据结构
typedef struct
{
    int data[MAX_SIZE]; // 存储数据元素
    int front;          // 队头指针
    int rear;           // 队尾指针
} Queue;

// 初始化队列
void InitQueue(Queue *Q)
{
    Q->front = Q->rear = 0; //! 初始化队头和队尾指针为0
}

// 入队操作
void EnQueue(Queue *Q, int e)
{
    if ((Q->rear + 1) % MAX_SIZE == Q->front)
    { 
        return;// 如果队列已满，无法入队
    }
    Q->data[Q->rear] = e;               // 将元素e入队
    
     //! 如果 front 、 rear 指针 只是简单 +1 ,那么很有可能会越出数组的范围。

     Q->rear = (Q->rear + 1) % MAX_SIZE;

     //! 如果 rear+1 小于 MAX_SIZE，则 rear 指针可以正常加一
     //! 如果 rear+1 大于等于 MAX_SIZE ， % MAX_SIZE 就等于 0，就回到了队头
    //比如 3%10 的结果是 3，
    // 而  5%5 的结果是 0，所以 rear 指针会回到队头
     //! 这样写保证了指针不会越界，会回到队头
}

// 出队操作
void DeQueue(Queue *Q)
{
    if (Q->front == Q->rear)
    { // 如果队列为空，无法出队
        return;
    }
    Q->front = (Q->front + 1) % MAX_SIZE; // 队头指针后移
}

// 获取队头元素
int GetHead(Queue *Q)
{
    if (Q->front != Q->rear)
    {                             // 如果队列不为空
        return Q->data[Q->front]; // 返回队头元素
    }
    return -1; // 如果队列为空，返回-1
}

int main()
{
    Queue Q;                // 创建一个队列
    InitQueue(&Q);          // 初始化队列
    EnQueue(&Q, 10);        // 入队10
    EnQueue(&Q, 20);        // 入队20
    DeQueue(&Q);            // 出队
    int head = GetHead(&Q); // 获取队头元素
    printf("The head element is %d\n", head);
    return 0;
}

//! 总结
// 本题主要考察了队列的基本操作，包括初始化、入队、出队和获取队头元素。队列是一种特殊的线性表，它只允许在一端进行插入操作，这一端被称为队尾，只允许在另一端进行删除操作，这一端被称为队头。
// 队列是一种先进先出（FIFO）的数据结构，最先入队的元素最先出队。因此，队列常被用来处理需要按照顺序处理的问题。
// 本题中，我们使用数组来实现队列，数组的第一个元素作为队头，最后一个元素作为队尾。在入队和出队操作中，只需要修改队头和队尾指针，不需要移动元素，因此效率较高。
// 通过本题，我们可以理解队列的基本概念和操作，以及队列在解决问题中的应用。
