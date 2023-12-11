#include <stdio.h>
#include <stdlib.h>

// 邻接表中表对应的链表的边
typedef struct ArcNode
{
    int adjvex;              // 该边所指向的节点的位置
    struct ArcNode *nextarc; // 指向下一条边的指针
} ArcNode;

// 邻接表中表的顶点
typedef struct VNode
{
    char data;         // 顶点信息
    ArcNode *firstarc; // 指向第一条依附该顶点的边
} VNode, AdjList[100];


typedef struct  // 邻接表
{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 图的顶点数和边数
} ALGraph;

int main()
{
    // 创建一个邻接表
    ALGraph G;
    // 初始化邻接表
    G.vexnum = 5;
    G.arcnum = 7;
    for (int i = 0; i < G.vexnum; ++i)
    {
        G.vertices[i].data = 'A' + i;
        G.vertices[i].firstarc = NULL;
    }
    // 添加边
    for (int i = 0; i < G.arcnum; ++i)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        ArcNode *arc = (ArcNode *)malloc(sizeof(ArcNode));
        arc->adjvex = end;
        arc->nextarc = G.vertices[start].firstarc;
        G.vertices[start].firstarc = arc;
    }
    // 打印邻接表
    for (int i = 0; i < G.vexnum; ++i)
    {
        printf("%c", G.vertices[i].data);
        ArcNode *arc = G.vertices[i].firstarc;
        while (arc != NULL)
        {
            printf(" -> %c", G.vertices[arc->adjvex].data);
            arc = arc->nextarc;
        }
        printf("\n");
    }
    return 0;
}
