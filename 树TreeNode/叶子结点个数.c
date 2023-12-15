// 题目要求：写出求二叉树的叶子结点数目的算法。
#include <stdio.h>
// 定义状态类型
typedef int Status;

// 二叉树的存储表示
typedef struct BiTNode
{
    int data;                        // 数据域
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 全局变量，用于记录叶子节点的数量
int count = 0;

// 求二叉树的叶子结点数目
Status LeafBiTree(BiTree T)
{
    if (T != NULL)
    {
        // 如果是叶子节点，计数器加1
        if (T->lchild == NULL && T->rchild == NULL)
        {
            count++;
        }
        // 递归遍历左子树
        LeafBiTree(T->lchild);
        // 递归遍历右子树
        LeafBiTree(T->rchild);
    }
    return count;
}

int main()
{
    BiTree T;
    // 创建二叉树并计算其叶子节点数目的代码在此处省略
    printf("The number of leaf nodes is: %d", LeafBiTree(T));
    return 0;
}

//! 关键注释：本题主要考察了二叉树的遍历和叶子节点的识别。我们使用递归的方式遍历二叉树的所有节点，当遇到叶子节点（即左右子树都为空）时，计数器加1。最后返回计数器的值，即为二叉树的叶子节点数目。
