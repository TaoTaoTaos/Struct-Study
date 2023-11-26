// 题目要求：使用邻接矩阵法构建一个图

// 思路和算法原理：
// 1. 首先，我们需要创建一个二维数组来表示邻接矩阵。
// 2. 然后，我们将每个顶点与其相邻的顶点之间的边用矩阵中的元素表示。
// 3. 如果两个顶点之间存在边，我们就在相应的矩阵元素中填入1，否则填入0。

#include <stdio.h>

#define MAX_VEX 100 // 定义最大顶点数//! 用100表示 无穷

// 定义图的数据结构
typedef struct
{
    int vexs[MAX_VEX];         // 顶点集合
    int arc[MAX_VEX][MAX_VEX]; // 邻接矩阵
    int numVertexes, numEdges; // 图中当前的顶点数和边数
} MGraph;

void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges); // 输入顶点数和边数
    for (i = 0; i < G->numVertexes; i++)           // 读入顶点信息
        scanf(&G->vexs[i]);
    for (i = 0; i < G->numVertexes; i++) // 邻接矩阵初始化
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = 0;
    for (k = 0; k < G->numEdges; k++) // 读入numEdges条边，建立邻接矩阵
    {
        printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
        scanf("%d,%d,%d", &i, &j, &w); // 输入边(vi,vj)上的权w
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j]; // 因为是无向图，矩阵对称
    }
}

int main()
{
    // 创建一个图的实例
    MGraph G;
    // 调用函数，创建邻接矩阵
    CreateMGraph(&G);
    return 0;
}

// 总结：
// 本题考察了图的邻接矩阵表示法。邻接矩阵是表示图中顶点之间相邻关系的一种方法，它可以清晰地显示出图的结构。
// 在邻接矩阵中，行和列都代表图中的顶点，如果两个顶点之间存在边，那么相应的矩阵元素就为1，否则为0。

// 关键问题：
//! 邻接矩阵法的一个重要特点是它可以同时处理有向图和无向图。在无向图中，邻接矩阵是对称的，而在有向图中，则不一定。
//! 邻接矩阵法的一个缺点是，如果图中的顶点数目较多，但每个顶点的度（即与它相邻的顶点的数目）却相对较少，那么邻接矩阵中就会有很多无用的零元素，从而造成存储空间的浪费。
