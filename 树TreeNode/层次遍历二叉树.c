/*
题目要求：
实现二叉树的层次遍历。

思路：
1. 创建一个队列，将根节点入队。
2. 当队列不为空时，进行以下操作：
   a. 出队一个节点，访问该节点。
   b. 如果该节点的左子节点不为空，将左子节点入队。
   c. 如果该节点的右子节点不为空，将右子节点入队。

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
    TreeNode *tNode;
    struct QueueNode *next;
} QueueNode;

// 定义队列
typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

// 初始化队列
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// 入队
void enqueue(Queue *q, TreeNode *node)
{
    QueueNode *qn = (QueueNode *)malloc(sizeof(QueueNode));
    qn->tNode = node;
    qn->next = NULL;
    if (q->rear == NULL)
    {
        q->front = qn;
        q->rear = qn;
    }
    else
    {
        q->rear->next = qn;
        q->rear = qn;
    }
}

// 出队
TreeNode *dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    QueueNode *qn = q->front;
    TreeNode *node = qn->tNode;
    q->front = qn->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(qn);
    return node;
}

// 判断队列是否为空
int isEmpty(Queue *q)
{
    return q->front == NULL;
}

// 二叉树的层次遍历
void levelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    Queue *q = initQueue();
    enqueue(q, root);
    while (!isEmpty(q))
    {
        TreeNode *node = dequeue(q);
        printf("%d ", node->val);
        if (node->left != NULL)
        {
            enqueue(q, node->left);
        }
        if (node->right != NULL)
        {
            enqueue(q, node->right);
        }
    }
    printf("\n");
    free(q);
}

/*
总结：
本题考察了二叉树的层次遍历和队列的知识点。解决问题的关键是使用队列来存储每一层的节点。
我们首先将根节点入队，然后在每一轮循环中，我们出队一个节点，访问该节点，然后将其左右子节点入队。
这样，我们就能按层次顺序访问二叉树的所有节点。
*/
