// 题目要求：实现 Dijkstra 算法，并记录最短路径。

// 思路和算法原理：
// Dijkstra 算法是一种用于在图中找到最短路径的算法。它从源节点开始，逐步扩展到所有可达的节点，直到所有节点都被访问。
// 在这个过程中，我们使用一个优先队列来存储待访问的节点，并使用一个数组（或哈希表）来存储每个节点的最短距离。
// 此外，我们还需要一个数组来存储每个节点的前驱节点，以便我们可以回溯并找到最短路径。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000 // 定义最大节点数
#define INF 1000000000 // 定义无穷大

int graph[MAX_NODES][MAX_NODES]; // 定义图的邻接矩阵
int dist[MAX_NODES];             // 存储每个节点的最短距离
int visited[MAX_NODES];          // 标记每个节点是否已被访问
int prev[MAX_NODES];             // 存储每个节点的前驱节点



// Dijkstra 算法
//!Dijkstra算法的工作原理是贪心算法，它总是先考虑当前最短的路径。因此，当我们访问一个节点时，我们可以确信，我们找到的从起始节点到这个节点的路径就是最短的路径。
void dijkstra(int start_node, int num_nodes)
{
    for (int i = 0; i < num_nodes; i++) //! 循环初始化三个数组

    //!dist记录最短距离，visited记录找到最短路径没有，prev记录前驱节点

    {                  
        dist[i] = INF;  // !将所有节点的最短距离初始化为无穷大
        visited[i] = 0; // !将visited所有节点标记为 0
        prev[i] = -1;   // !将所有节点的前驱节点初始化为 -1
    }

    dist[start_node] = 0; // 将起始节点的最短距离设置为 0

    for (int i = 0; i < num_nodes; i++)
    {                          // 遍历所有节点
        int min_dist = INF;    // 初始化最小距离为无穷大
        int current_node = -1; // 初始化当前节点为 -1

        for (int j = 0; j < num_nodes; j++)
        { // 找到未访问的最近节点
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                current_node = j;
            }
        }

        if (current_node == -1)
        { // 如果找不到未访问的最近节点，说明剩余的节点都不可达，退出循环
            break;
        }

        visited[current_node] = 1; // 标记当前节点为已访问

        for (int j = 0; j < num_nodes; j++)
        { // 更新当前节点的所有邻居节点的最短距离
            if (graph[current_node][j] != INF //!如果存在与current相连的路径
            && dist[current_node] + graph[current_node][j] < dist[j])
              //!而且找得到比他更小的距离
            {
                dist[j] = dist[current_node] + graph[current_node][j];
                prev[j] = current_node; // 更新前驱节点
            }
            //每一轮都能确定一个结点的最短距离
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
    {                                                            // 如果目标节点没有前驱节点
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

    for (int i = 0; i < num_nodes; i++)
    { // 初始化图的邻接矩阵
        for (int j = 0; j < num_nodes; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < num_edges; i++)
    { // 读取每条边
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w); // 读取边的两个节点和权重
        graph[u][v] = w;               // 更新图的邻接矩阵
    }

    dijkstra(0, num_nodes); // 从节点 0 开始进行 Dijkstra 算法

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
// 本题考察了 Dijkstra 算法在最短路径问题中的应用。Dijkstra 算法是一种贪心的搜索策略，它能够找到从源节点到其他所有节点的最短路径。
// Dijkstra 算法的时间复杂度是 O(V^2)，其中 V 是节点数。这是因为每个节点都需要遍历所有其他节点来找到最近的未访问节点。如果使用优先队列（如二叉堆）来存储待访问的节点，那么时间复杂度可以降低到 O((V+E)logV)。
// Dijkstra 算法的空间复杂度是 O(V)，其中 V 是节点数。这是因为我们需要存储每个节点的最短距离和访问状态。

// 关键问题：
// 1. 如何使用 Dijkstra 算法求解最短路径问题？
//    Dijkstra 算法从源节点开始，逐步扩展到所有可达的节点，直到所有节点都被访问。在这个过程中，我们使用一个优先队列来存储待访问的节点，并使用一个数组（或哈希表）来存储每个节点的最短距离。
// 2. Dijkstra 算法的时间复杂度和空间复杂度是多少？
//    Dijkstra 算法的时间复杂度是 O(V^2)，其中 V 是节点数。这是因为每个节点都需要遍历所有其他节点来找到最近的未访问节点。如果使用优先队列（如二叉堆）来存储待访问的节点，那么时间复杂度可以降低到 O((V+E)logV)。Dijkstra 算法的空间复杂度是 O(V)，其中 V 是节点数。这是因为我们需要存储每个节点的最短距离和访问状态。

//! BFS（广度优先搜索）和 Dijkstra 算法都是图搜索算法，可以用来找到从源节点到其他节点的路径。然而，它们在处理权重（或成本）时有所不同。

// BFS：BFS 是一种无权图的搜索算法，也就是说，它假设从一个节点到其任何相邻节点的距离（或成本）都是相同的。因此，BFS 可以找到从源节点到其他节点的最短路径（以边的数量计）。BFS 的时间复杂度是 O(V+E)，其中 V 是节点数，E 是边数。

// Dijkstra 算法：Dijkstra 算法是一种有权图的搜索算法，也就是说，它考虑了从一个节点到其相邻节点的距离（或成本）可能会有所不同。因此，Dijkstra 算法可以找到从源节点到其他节点的最短路径（以边的权重计）。如果所有边的权重都是 1，那么 Dijkstra 算法就退化为 BFS。Dijkstra 算法的时间复杂度是 O(V^2)，但如果使用优先队列（如二叉堆）来存储待访问的节点，那么时间复杂度可以降低到 O((V+E)logV)。

//! 总的来说，BFS 和 Dijkstra 算法都是寻找最短路径的有效方法，但适用的场景不同。BFS 更适合无权图，而 Dijkstra 算法更适合有权图。