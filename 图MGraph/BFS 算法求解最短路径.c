// 题目要求：使用 BFS 算法求解最短路径问题，并记录路径。

// 思路和算法原理：
// BFS（广度优先搜索）是一种图形搜索算法，可以用于解决最短路径问题。
// BFS 从图的某一节点（源节点）开始，探索与源节点相邻的所有节点，然后对这些相邻节点进行探索，如此反复，直到找到目标节点为止。
// 在这个过程中，我们使用一个队列来存储待探索的节点，并使用一个数组（或哈希表）来存储每个节点的最短距离。
// 此外，我们还需要一个数组来存储每个节点的前驱节点，以便我们可以回溯并找到最短路径。
//!对某一结点进行bfs，就能找到该结点的最短路径
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000 // 定义最大节点数

int graph[MAX_NODES][MAX_NODES]; // 定义图的邻接矩阵
int dist[MAX_NODES];             // 存储每个节点的最短距离
int visited[MAX_NODES];          // 标记每个节点是否已被访问
int queue[MAX_NODES];            // 定义队列
int front = 0, rear = 0;         // 定义队列的头和尾
int prev[MAX_NODES];             // 存储每个节点的前驱节点

// 将节点添加到队列中
void enqueue(int node)
{                         // 添加节点到队列
    queue[rear++] = node; // 将节点添加到队列尾部
}

// 从队列中取出节点
int dequeue()
{                          // 从队列中取出节点
    return queue[front++]; // 返回队列头部的节点并更新队列头部
}

// BFS 算法
void bfs(int start_node, int num_nodes)
{
    for (int i = 0; i < num_nodes; i++)
    {                   // 初始化距离和访问数组
        dist[i] = -1;   //! 将所有节点的最短距离初始化为 -1
        visited[i] = 0; //! 将所有节点标记为未访问
        prev[i] = -1;   //! 将所有节点的前驱节点初始化为 -1
    }

    dist[start_node] = 0;    // 将起始节点的最短距离设置为 0
    visited[start_node] = 1; // 将起始节点标记为已访问
    enqueue(start_node);     // 将起始节点添加到队列中

    while (front != rear)       // 当队列不为空时
    {                                 
        int current_node = dequeue(); 
        // 最前面的元素出队，让他等于current_node

        for (int i = 0; i < num_nodes; i++)// 遍历所有节点
        { 
            if (graph[current_node][i] == 1 && visited[i] == 0)
            {            // !如果当前节点与其他节点相邻且未被访问
                // ! 这里current_node 既是节点的名字，又是邻接矩阵的行数
                dist[i] = dist[current_node] + 1; // 更新最短距离
                prev[i] = current_node;           // 更新前驱节点
                visited[i] = 1;                   // 标记节点为已访问
                enqueue(i);                       // 将节点添加到队列中
            }
            //每次循环，都会操作一个和当前节点相邻的节点
        }
    }
}

// 打印最短路径
void print_path(int start_node, int end_node)
{
    if (start_node == end_node)
    {                              // 如果起始节点和目标节点相同
        printf("%d ", start_node); // 打印节点
    }
    else if (prev[end_node] == -1)
    {                                    // 如果目标节点没有前驱节点
        printf("No path from %d to %d\n", start_node, end_node); // 打印错误信息
    }
    else
    {                                           // 如果目标节点有前驱节点
        print_path(start_node, prev[end_node]); // 递归打印路径
        printf("%d ", end_node);                // 打印节点
    }
}

int main()
{
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges); // 读取节点数和边数

    memset(graph, 0, sizeof(graph)); // 初始化图的邻接矩阵

    for (int i = 0; i < num_edges; i++)
    { // 读取每条边
        int u, v;
        scanf("%d %d", &u, &v);        // 读取边的两个节点
        graph[u][v] = graph[v][u] = 1; // 更新图的邻接矩阵
    }

    bfs(0, num_nodes); // 从节点 0 开始进行 BFS

    for (int i = 0; i < num_nodes; i++)
    { // 输出每个节点的最短距离
        printf("The shortest distance from node 0 to node %d is %d\n", i, dist[i]);
        printf("The shortest path from node 0 to node %d is: ", i);
        print_path(0, i); // 打印最短路径
        printf("\n");
    }

    return 0;
}

// 总结：
// 本题考察了 BFS 算法在最短路径问题中的应用。BFS 算法是一种广度优先的搜索策略，它能够找到从源节点到其他所有节点的最短路径。
// BFS 算法的时间复杂度是 O(V+E)，其中 V 是节点数，E 是边数。这是因为每个节点和每条边都会被访问一次。
// BFS 算法的空间复杂度是 O(V)，其中 V 是节点数。这是因为在最坏的情况下，队列中可能需要存储所有的节点。

// 关键问题：
// 1. 如何使用 BFS 算法求解最短路径问题？
//    BFS 算法从源节点开始，探索与源节点相邻的所有节点，然后对这些相邻节点进行探索，如此反复，直到找到目标节点为止。在这个过程中，我们使用一个队列来存储待探索的节点，并使用一个数组（或哈希表）来存储每个节点的最短距离。此外，我们还需要一个数组来存储每个节点的前驱节点，以便我们可以回溯并找到最短路径。
// 2. BFS 算法的时间复杂度和空间复杂度是多少？
//    BFS 算法的时间复杂度是 O(V+E)，其中 V 是节点数，E 是边数。这是因为每个节点和每条边都会被访问一次。BFS 算法的空间复杂度是 O(V)，其中 V 是节点数。这是因为在最坏的情况下，队列中可能需要存储所有的节点。
