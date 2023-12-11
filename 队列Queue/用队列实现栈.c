// 题目要求：使用队列实现栈的下列操作：
//
// push(x) -- 元素 x 入栈
// pop() -- 移除栈顶元素
// top() -- 获取栈顶元素
// empty() -- 返回栈是否为空

#include <stdio.h>
#include <stdlib.h>

// 定义队列结构
typedef struct
{
    int *data;
    int head, tail, size;
} Queue;

// 初始化队列
Queue *createQueue(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(size * sizeof(int));
    queue->head = 0;
    queue->tail = -1;
    queue->size = size;
    return queue;
} 

// 入队操作
void enqueue(Queue *queue, int x)
{
    if ((queue->tail + 1) % queue->size == queue->head)
    {
        return;
    }
    queue->tail = (queue->tail + 1) % queue->size;
    queue->data[queue->tail] = x;
}

// 出队操作
int dequeue(Queue *queue)
{
    if (queue->head == (queue->tail + 1) % queue->size)
    {
        return -1;
    }
    int ret = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return ret;
}

// 获取队首元素
int front(Queue *queue)
{
    if (queue->head == (queue->tail + 1) % queue->size)
    {
        return -1;
    }
    return queue->data[queue->head];
}

// 判断队列是否为空
int isEmpty(Queue *queue)
{
    return queue->head == (queue->tail + 1) % queue->size;
}
//================================================================
// 定义栈结构=两个队列
typedef struct
{
    Queue *queue1;
    Queue *queue2;

} MyStack;

// 初始化栈
MyStack *myStackCreate()
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->queue1 = createQueue(100);
    stack->queue2 = createQueue(100);
    return stack;
}

// 入栈操作
void myStackPush(MyStack *obj, int x)
{
    enqueue(obj->queue1, x);
    while (!isEmpty(obj->queue2))
    {
        enqueue(obj->queue1, dequeue(obj->queue2));
    }
    Queue *temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;
}

// 出栈操作
int myStackPop(MyStack *obj)
{
    return dequeue(obj->queue2);
}

// 获取栈顶元素
int myStackTop(MyStack *obj)
{
    return front(obj->queue2);
}

// 判断栈是否为空
int myStackEmpty(MyStack *obj)
{
    return isEmpty(obj->queue2);
}

int main()
{
    // 创建栈
    MyStack *stack = myStackCreate();

    // 入栈操作
    myStackPush(stack, 1);
    myStackPush(stack, 2);

    // 获取栈顶元素
    printf("%d\n", myStackTop(stack)); // 输出：2

    // 出栈操作
    printf("%d\n", myStackPop(stack)); // 输出：2

    // 判断栈是否为空
    printf("%d\n", myStackEmpty(stack)); // 输出：0（表示栈不为空）

    return 0;
}

// 总结：这个题目考察的是栈和队列的操作以及它们之间的转换。通过两个队列，我们可以模拟栈的操作。关键在于理解栈和队列的特性，即栈是后进先出，队列是先进先出。我们可以通过调整元素在两个队列之间的位置，使得后进入队列的元素先出队，从而模拟栈的后进先出特性。
// 时间复杂度：入栈操作的时间复杂度为O(n)，出栈操作和获取栈顶元素的操作的时间复杂度为O(1)，其中n为栈的元素数量。
// 空间复杂度：O(n)，我们需要额外的空间来存储栈中的元素。
