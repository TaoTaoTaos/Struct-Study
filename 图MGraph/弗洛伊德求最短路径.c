#include<stdio.h>
#define INF 99999
#define V 4

// 打印结果
void printSolution(int dist[][V]);

// 使用弗洛伊德算法求解所有节点对之间的最短路径
void floydWarshall (int graph[][V])
{
    // dist[][] 将用于存储最短距离
    int dist[V][V], i, j, k;

    // 初始化dist[][]为输入图的邻接矩阵
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // 通过每个顶点一次
    for (k = 0; k < V; k++)
    {
        // 选择所有顶点作为源点
        for (i = 0; i < V; i++)
        {
            // 选择所有顶点作为目标点
            for (j = 0; j < V; j++)
            {
                // 如果顶点k在最短路径i到j上，则更新dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // 打印最短距离矩阵
    printSolution(dist);
}

// 打印解决方案（最短距离矩阵）
void printSolution(int dist[][V])
{
    printf ("以下是所有节点对之间的最短距离\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
