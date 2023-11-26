// 交换二叉树的左右子树。这个函数使用递归的方式来遍历二叉树的每一个节点，并交换每一个节点的左右子树。

#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode
{
    int data;
    struct TreeN *lchild, *rchild;
} TreeNode, *BiTree;

void changeLeftRight(BiTree *T)
{
    if (*T != NULL)
    {
        // 交换左右子树
        BiTree temp = (*T)->lchild;
        (*T)->lchild = (*T)->rchild;
        (*T)->rchild = temp;

        // 递归地交换左右子树的左右子树
        changeLeftRight(&(*T)->lchild);
        changeLeftRight(&(*T)->rchild);
    }
}
/*
在这个函数中，我们首先检查当前节点是否为空。
如果当前节点不为空，我们就交换它的左右子树，
然后递归地对左右子树执行相同的操作。这样，我们就可以确保二叉树的每一个节点的左右子树都被交换了。
*/