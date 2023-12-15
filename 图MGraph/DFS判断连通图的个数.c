// 题目要求：设计算法int DFSTraverse(Graph G)对无向图G进行深度优先遍历，并判断该无向图是否连通，若连通,函数返回1,否则返回连通分量的个数。
// 思路：我们可以使用一个数组visited来记录每个顶点是否被访问过。然后，我们从一个顶点开始，使用深度优先搜索遍历所有与它连通的顶点。如果遍历结束后，还有未访问的顶点，就表示图不连通。

#include <stdio.h>

#define MAX_VERTEX_NUM 100

typedef struct {
    // 顶点集合
    int V[MAX_VERTEX_NUM];
    // 边集合
    int E[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    // 顶点数和边数
    int vexnum, arcnum;
} Graph;

// 深度优先搜索
void DFS(Graph G, int v, int visited[]) {
    // 标记顶点v为已访问
    visited[v] = 1;

    // 遍历顶点v的所有邻接点
    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
        // 如果邻接点w未被访问，就递归访问它
        if (!visited[w]) {
            DFS(G, w, visited);
        }
    }
}

// 深度优先遍历
int DFSTraverse(Graph G) {
    // 初始化visited数组
    int visited[MAX_VERTEX_NUM] = {0};

    // 连通分量的个数
    int count = 0;

    // 遍历所有顶点
    for (int v = 0; v < G.vexnum; v++) {
        // 如果顶点v未被访问，就从它开始深度优先搜索
        if (!visited[v]) {
            DFS(G, v, visited);
            // 增加连通分量的个数
            count++;
        }
    }

    // 如果连通分量的个数为1，就返回1，否则返回连通分量的个数
    return count == 1 ? 1 : count;
}

// 总结：这个题目主要考察了深度优先搜索和连通性的判断。深度优先搜索是一种常用的图遍历算法，它可以用来判断图的连通性。
// 关键注释：DFS(G, v, visited); 这行代码是深度优先搜索的关键，它递归地访问每个顶点的所有邻接点。
// count++; 这行代码是计算连通分量的关键，每当我们从一个未被访问的顶点开始深度优先搜索时，就表示找到了一个新的连通分量。
