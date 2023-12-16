/*
题目要求：
使用层次遍历计算二叉树的高度。

思路：
1. 创建一个队列，将根节点入队。
2. 当队列不为空时，进行以下操作：
   a. 记录当前队列的大小，这个大小就是当前层的节点数。
   b. 将当前层的所有节点从队列中移除，并将这些节点的子节点加入队列。
   c. 高度加一。
3. 当队列为空时，返回高度。

以下是实现这个思路的代码：
*/

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的节点
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 定义队列的节点
typedef struct QueueNode
{
    TreeNode *node;
    struct QueueNode *next;
} QueueNode;

// 定义队列
typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

// 初始化队列
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue)); // 创建一个队列
    q->front = NULL;                           // 初始化队列的头部
    q->rear = NULL;                            // 初始化队列的尾部
    return q;                                  // 返回队列
}

// 入队操作
void enqueue(Queue *q, TreeNode *node)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode)); // 创建一个新的队列节点
    newNode->node = node;                                        // 设置队列节点的数据
    newNode->next = NULL;                                        // 设置队列节点的下一个节点为NULL
    if (q->rear == NULL)
    {                       // 如果队列为空
        q->front = newNode; // 设置队列的头部为新的节点
        q->rear = newNode;  // 设置队列的尾部为新的节点
    }
    else
    {                            //! 如果队列不为空
        q->rear->next = newNode; // 将新的节点添加到队列的尾部
        q->rear = newNode;       // 更新队列的尾部
    }
}

// 出队操作
TreeNode *dequeue(Queue *q)
{
    if (q->front == NULL)
    {                // 如果队列为空
        return NULL; // 返回NULL
    }
    QueueNode *tempNode = q->front;  // 获取队列的头部节点
    TreeNode *node = tempNode->node; // 获取头部节点的数据
    q->front = tempNode->next;       // 更新队列的头部
    if (q->front == NULL)
    {                   // 如果队列为空
        q->rear = NULL; // 更新队列的尾部
    }
    free(tempNode); // 释放头部节点的内存
    return node;    // 返回头部节点的数据
}

// 判断队列是否为空
int isEmpty(Queue *q)
{
    return q->front == NULL; // !如果队列的头部为NULL，那么队列为空，返回1；否则，返回0
}

// 使用层次遍历计算二叉树的高度
int treeHeight(TreeNode *root)
{
    if (root == NULL)
    {             // 如果二叉树为空
        return 0; // 返回0
    }
    Queue *q = createQueue(); // 创建一个队列
    enqueue(q, root);         // 将二叉树的根节点入队
    int height = 0;           // 初始化二叉树的高度为0
    while (!isEmpty(q))
    {                        // 当队列不为空时
        int nodeCount = 0;   // 初始化本层节点的数量为0
        nodeCount = size(q); // 获取当前队列的大小，即当前层的节点数
        for (int i = 0; i < nodeCount; i++)
        {                                // 当本层还有节点时
            TreeNode *node = dequeue(q); // 出队一个节点
            if (node->left != NULL)
            {                           // 如果该节点的左子节点不为空
                enqueue(q, node->left); // 将左子节点入队
            }
            if (node->right != NULL)
            {                            // 如果该节点的右子节点不为空
                enqueue(q, node->right); // 将右子节点入队
            }
        }
        height++; // 二叉树的高度加一
    }
    return height; // 返回二叉树的高度
}

/*
总结：
本题考察了二叉树的层次遍历和队列的知识点。解决问题的关键是使用队列来存储每一层的节点。
我们首先将根节点入队，然后在每一轮循环中，我们出队一个节点，访问该节点，然后将其左右子节点入队。
这样，我们就能按层次顺序访问二叉树的所有节点。
*/
