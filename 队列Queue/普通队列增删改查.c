#include <stdio.h>
#include <stdlib.h>

// 题目要求：实现一个普通队列的增删改查

// 思路：我们首先定义一个队列的结构体，包括一个数组用于存储元素，两个指针分别指向队头和队尾。然后，我们实现队列的基本操作，包括入队、出队、修改队列元素、查找队列元素。

#define MAXSIZE 100 // 队列的最大容量

// 定义队列的结构体
typedef struct
{
    int data[MAXSIZE]; // 存储元素的数组
    int front;         // 队头指针
    int rear;          // 队尾指针
} Queue;

// 初始化队列
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空
int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

// 判断队列是否为满
int isFull(Queue *q)
{
    return q->rear == MAXSIZE;
}

// 入队
void enqueue(Queue *q, int x)
{
    if (isFull(q))
    {
        printf("队列已满，无法入队\n");
        return;
    }
    q->data[q->rear++] = x;
}

// 出队
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空，无法出队\n");
        return -1;
    }
    return q->data[q->front++];
}

// 修改队列元素
void modify(Queue *q, int pos, int x)
{
    if (pos < 0 || pos >= q->rear)
    {
        printf("位置无效，无法修改\n");
        return;
    }
    q->data[pos] = x;
}

// 查找队列元素
int search(Queue *q, int x)
{
    for (int i = q->front; i < q->rear; i++)
    {
        if (q->data[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("%d\n", dequeue(&q)); // 输出：1
    printf("%d\n", dequeue(&q)); // 输出：2
    printf("%d\n", dequeue(&q)); // 输出：3
    return 0;
}

/*这样的普通队列在实际使用中存在一些不足之处：

1. **空间利用不充分**：在普通队列中，当队列的元素被出队后，这些位置就无法再被利用，这就造成了空间的浪费。尽管队列的尾部还有空闲的空间，但是由于队列的操作特性（只能在队尾添加元素，在队头删除元素），这些空间无法被利用。

2. **队列长度固定**：在初始化队列时，我们需要指定队列的最大长度。如果后续的操作超出了这个长度，那么队列就无法再添加新的元素，即使队列中还有空闲的空间。

3. **队列溢出**：当队列满时，如果还要添加新的元素，就会导致队列溢出。这是因为在普通队列中，队尾指针总是指向队列的最后一个元素的下一个位置，如果这个位置已经没有空间，那么就会发生溢出。

以上就是普通队列的一些不足之处，为了解决这些问题，我们可以使用循环队列。循环队列通过将队列的首尾相连，形成一个环形，使得队列在出队后，空出的位置可以被再次利用，从而提高了空间的利用率。同时，循环队列也可以避免队列溢出的问题，因为队尾指针可以在队列满时回到队列的开始位置，从而实现“循环”。总的来说，循环队列在处理具有队列特性的问题时，具有更高的效率和效果。
*/