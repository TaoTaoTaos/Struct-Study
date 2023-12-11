#include <stdio.h>
#include <stdlib.h>

// 链表节点
typedef struct Node
{
    int data;
    struct Node *next;

} Node;

// 队列
typedef struct Queue
{
    Node *front, *rear;
} Queue;

// 创建一个新的节点
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 创建一个空队列
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// 添加元素到队列
// 即 把元素放到一个 新的结点里 ，再入队
void enQueue(Queue *queue, int data)
{
    Node *node = newNode(data);
    if (queue->rear == NULL) //! 如果队列是空的，那队列头和尾都指向结点
    {
        queue->front = queue->rear = node;
        return;
    }
    //! 如果队列不是空的
    queue->rear->next = node;//把node连到尾指针后面
    queue->rear = node;//更新尾指针
}

// 从队列中移除元素
int deQueue(Queue *queue)
{
    if (queue->front == NULL)   //!如果队头==队尾==NULL，那么队列是空的
        return -1;
    Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return data;
}

// 基数排序函数
void radixsort(int arr[], int n)
{
    // 找到最大值，知道排序的终止条件
    int max = getMax(arr, n);

    // 创建10个队列，对应每个基数0-9
    Queue *queues[10];
    for (int i = 0; i < 10; i++)
        queues[i] = createQueue();

    // 从最低位开始，对每一位进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        // 将每个数字放入对应的队列中
        for (int i = 0; i < n; i++)
            enQueue(queues[(arr[i] / exp) % 10], arr[i]);

        // 按照队列的顺序取出所有数字
        int idx = 0;
        for (int i = 0; i < 10; i++)
        {
            while (queues[i]->front != NULL)
            {
                arr[idx++] = deQueue(queues[i]);
            }
        }
    }

    // 释放队列
    for (int i = 0; i < 10; i++)
        free(queues[i]);
}

int main()
{
    // 定义数组
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 执行基数排序
    radixsort(arr, n);

    // 打印排序后的数组
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

// 总结：本题主要考察了基数排序算法的实现，基数排序是一种非比较型整数排序算法，其原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。具体做法是：首先根据最低有效位进行排序，然后根据次低有效位进行排序，依次类推，直到根据最高有效位进行排序。
// 关键注释：
// 1. "Node* newNode(int data)": 这是创建新节点的函数，每个节点包含一个数据和一个指向下一个节点的指针。
// 2. "Queue* createQueue()": 这是创建队列的函数，每个队列包含一个指向队首的指针和一个指向队尾的指针。
// 3. "void enQueue(Queue* queue, int data)": 这是入队函数，它在队尾添加一个新元素。
// 4. "int deQueue(Queue* queue)": 这是出队函数，它移除队首的元素并返回其值。
// 5. "void radixsort(int arr[], int n)": 这是基数排序函数，它首先获取数组的最大值，然后从最低位开始，对每一位进行计数排序。
// 6. "for (int exp = 1; max / exp > 0; exp *= 10)": 这是按位进行计数排序的循环，每次循环结束后，exp会乘以10，以便下次循环时对更高的位进行排序。
