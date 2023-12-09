// 题目要求：设计算法void CountLevel(BiTree &T)计算二叉树T的每个结点的层次，并存入结点的 level分量（规定根的层次为1）。

// 思路：我们可以使用递归的方式来解决这个问题。首先，我们将根节点的层次设置为1。然后，我们递归地访问每个节点的左孩子和右孩子，将它们的层次设置为父节点的层次加1。

#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct BiTNode
{
    TElemType data;                  // 结点的数据值
    struct BiTNode *lchild, *rchild; // 左右孩子指针
    int level;                       // 结点的层次
} BiTNode, *BiTree;

// 计算二叉树T的每个结点的层次，并存入结点的 level分量
void CountLevel(BiTree T, int level)
{
    if (T != NULL)
    {                                     // 如果节点不为空
        T->level = level;                 // 将当前层次赋值给节点的 level
        CountLevel(T->lchild, level + 1); // 递归处理左子树，层次加1
        CountLevel(T->rchild, level + 1); // 递归处理右子树，层次加1
    }
}

// 创建新节点
BiTree createNewNode(TElemType data)
{
    BiTree newNode = (BiTree)malloc(sizeof(BiTNode)); // 分配内存
    newNode->data = data;                             // 设置数据
    newNode->lchild = NULL;                           // 左孩子为空
    newNode->rchild = NULL;                           // 右孩子为空
    return newNode;                                   // 返回新节点
}

int main()
{
    // 创建二叉树
    BiTree root = createNewNode(1);
    root->lchild = createNewNode(2);
    root->rchild = createNewNode(3);
    root->lchild->lchild = createNewNode(4);
    root->lchild->rchild = createNewNode(5);
    root->rchild->lchild = createNewNode(6);
    root->rchild->rchild = createNewNode(7);

    // 计算每个节点的层次
    CountLevel(root, 1);

    // 打印结果
    printf("Root level: %d\n", root->level);
    printf("Left child level: %d\n", root->lchild->level);
    printf("Right child level: %d\n", root->rchild->level);

    return 0;
}

// 总结：这个题目考察的是二叉树的遍历和递归的使用。通过递归遍历二叉树的每一个节点，我们可以计算出每个节点的层次。关键在于理解递归的工作原理，即每一层递归都有自己的变量空间，因此每个节点的 level 变量都是独立的。
