// 题目要求：实现图的深度优先搜索（DFS）

// 思路和算法原理：
// 深度优先搜索是一种用于图的查找算法，它沿着树的深度遍历树的节点，尽可能深的搜索树的分支。
// 当节点v的所在边都己被探寻过，搜索将回溯到发现节点v的那条边的起始节点。
// 这一过程一直进行到已发现从源节点可达的所有节点为止。
// 如果还存在未被发现的节点，则选择其中一个作为源节点并重复以上过程，整个进程反复进行直到所有节点都被访问为止。
//! 与先根遍历类似，有根找根
//! DFS可以找到所有路径，可以求联通分量的个数
//!BFS可以找最短路径
//! 时间复杂度O(V+E),空间复杂度O(V)
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

int visited[MAXVEX];  // 访问标志的数组

// DFS算法
void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = 1;  // 设置当前节点访问过
    printf("%c ", GL->adjList[i].data);  // 打印顶点，也可以其他操作
    p = GL->adjList[i].firstedge;  // 使p指向顶点v的第一个邻接点
    while (p)
    {
        if (!visited[p->adjvex])  // 若邻接顶点p->adjvex未访问
            DFS(GL, p->adjvex);  // 对未访问的邻接顶点递归调用
        p = p->next;
    }
}

void DFSTraverse(GraphAdjList GL)
{
    int i;
    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = 0;  // 初始化所有顶点状态都是未访问过状态
    for (i = 0; i < GL->numVertexes; i++)  // 对每一个顶点做循环
        if (!visited[i])  // 若是未访问过就处理
            DFS(GL, i);  // 调用DFS，进行一次深度优先遍历
}

int main()
{
    // 这里省略了创建图的代码
    GraphAdjList GL;
    DFSTraverse(GL);
    return 0;
}

// 总结：
// 本题考察了图的深度优先搜索算法。
// DFS是一种重要的图遍历算法，它可以找到从一个顶点到其他所有顶点的路径。
// DFS的实现需要用到递归，通过不断地深入和回溯，实现了深度优先的遍历。

//! 关键问题：
//! 1. DFS和BFS有什么区别？
//!    DFS和BFS都是图的遍历算法，但是DFS是按照深度优先，而BFS是按照广度优先。DFS可以找到所有可能的路径，但是找到的路径可能不是最短的；BFS则相反，它可以找到最短路径，但是需要更多的存储空间。
//! 2. DFS如何处理连通分量？
//!    DFS在处理连通分量时，需要对每个顶点进行循环，如果发现有未访问过的顶点，就从该顶点开始进行新的一轮DFS。这样可以保证所有的连通分量都被遍历到。
