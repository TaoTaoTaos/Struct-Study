// Prim算法和Kruskal算法都是用于求解图的最小生成树问题的经典算法。下面是它们的总结和简单的代码实现：

// 1. **Prim算法**：Prim算法从一个顶点开始
//逐渐长大覆盖整个图，每次都是选择距离当前生成树集合最近的一个顶点加入到集合中。


// 2. **Kruskal算法**：Kruskal算法是从边的角度出发
//每次选择一条最小的边，如果这条边连接的两个顶点于图中不在同一连通分量中，则添加这条边。直到图中所有的顶点都在同一连通分量中。

// 这两个算法都可以有效地求解最小生成树问题，但是它们的适用场景和性能略有不同。Prim算法更适合于稠密图，而Kruskal算法更适合于稀疏图。
