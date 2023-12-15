// 题目要求：实现图的广度优先搜索（BFS）

// 思路和算法原理：
// 广度优先搜索是一种用于图的查找算法
//!可以用来找到两个顶点之间的最短路径。（无权图）
//!（有权图用Dijkstra）
//!利用队列，出队一个，拉两个孩子进来。
// BFS是从根节点开始，沿着树的宽度遍历树的节点。如果所有节点均被访问，则算法中止。
// 广度优先搜索的实现一般采用open-closed表。

#include <stdio.h>
#define MAXVEX 100  // 最大顶点数
#define INFINITY 65535  // 无穷大

typedef char VertexType;  // 顶点类型
typedef int EdgeType;  // 边上的权值类型

// 边表结点
typedef struct EdgeNode
{
    int adjvex;  // 邻接点域，存储该顶点对应的下标
    EdgeType weight;  // 用于存储权值
    struct EdgeNode *next;  // 链域，指向下一个邻接点
} EdgeNode;

// 顶点表结点
typedef struct VertexNode
{
    VertexType data;  // 顶点域，存储顶点信息
    EdgeNode *firstedge;  // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges;  // 图中当前顶点数和边数
} graphAdjList, *GraphAdjList;

// BFS的队列
typedef struct
{

    int data[MAXVEX];
    int front, rear;

} Queue;

// 初始化队列
void initQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

// 入队列
void enQueue(Queue *Q, int i)
{
    if ((Q->rear + 1) % MAXVEX == Q->front)
        return;
    Q->data[Q->rear] = i;

    Q->rear = (Q->rear + 1) % MAXVEX;
}

// 出队列
int deQueue(Queue *Q)
{
    if (Q->front == Q->rear)//队列为空
        return -1;

    int data = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXVEX;
    return data;
}


// BFS算法
void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    Queue Q;
    int visited[MAXVEX];  // 记录顶点访问状态的数组
                            //! 0表示未访问，1表示已访问
    initQueue(&Q);  // 初始化队列

    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = 0;  // 初始化所有顶点状态都是未访问过状态

    for (i = 0; i < GL->numVertexes; i++)  // 对每一个顶点做循环
    {
        if (!visited[i])  // 若是未访问过
        {//就开始处理
            visited[i] = 1;  // 设置当前顶点访问过
            printf("%c ", GL->adjList[i].data);  // 打印顶点，也可以其他操作

            enQueue(&Q, i);  // 将此顶点入队列

            while (!QueueEmpty(Q))  // 若当前队列不为空
            {
                i = deQueue(&Q);  // 将队中第一个元素出队列，赋值给i

                p = GL->adjList[i].firstedge;  //! 找到当前顶点边表链表头指针

                while (p)
                {
                    if (!visited[p->adjvex])  // 若此顶点未被访问
                    {
                        visited[p->adjvex] = 1;
                        printf("%c ", GL->adjList[p->adjvex].data);
                        enQueue(&Q, p->adjvex);  // 将找到的此顶点入队列
                    }
                    p = p->next;  // 指针指向下一个邻接点
                }
            }
        }
    }
}


int main()
{
    // 这里省略了创建图的代码
    GraphAdjList GL;
    BFSTraverse(GL);
    return 0;
}

// 总结：
// 本题考察了图的广度优先搜索算法。
// BFS是一种重要的图遍历算法，它可以找到从一个顶点到其他所有顶点的最短路径。
// BFS的实现需要用到队列，通过不断地入队列和出队列操作，实现了广度优先的遍历。

//! 关键问题：
//! 1. BFS和DFS有什么区别？
//!    BFS和DFS都是图的遍历算法，但是BFS是按照广度优先，而DFS是按照深度优先。

//! BFS可以找到最短路径，但是需要更多的存储空间；DFS则相反，它需要较少的存储空间，但是找到的路径可能不是最短的。

//! 2. BFS如何处理连通分量？
//!    BFS在处理连通分量时，需要对每个顶点进行循环，如果发现有未访问过的顶点，就从该顶点开始进行新的一轮BFS。这样可以保证所有的连通分量都被遍历到。
