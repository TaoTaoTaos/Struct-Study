// 交换二叉树的左右子树。这个函数使用递归的方式来遍历二叉树的每一个节点，并交换每一个节点的左右子树。
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *lchild, *rchild;
} TreeNode, *BiTree;

void changeLeftRight(BiTree T)
{
    if (T != NULL)
    {
        // 交换左右子树
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;

        // 递归地交换左右子树的左右子树
        changeLeftRight(T->lchild);
        changeLeftRight(T->rchild);
    }
}

// 创建二叉树
void createBiTree(BiTree *T)
{
    int data;
    scanf("%d", &data);
    if (data == 0) //我们约定输入0表示节点不存在
        *T = NULL;
    else
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = data;
        createBiTree(&(*T)->lchild); //创建左子树
        createBiTree(&(*T)->rchild); //创建右子树
    }
}

// 前序遍历
void preOrderTraverse(BiTree T)
{
    if (T)
    {
        printf("%d ", T->data); //显示节点数据
        preOrderTraverse(T->lchild); //再先序遍历左子树
        preOrderTraverse(T->rchild); //最后先序遍历右子树
    }
}

int main()
{
    BiTree T;
    printf("请按先序序列输入各节点的字符，某节点的左子树或右子树为空时输入0。\n");
    createBiTree(&T);

    printf("前序遍历二叉树：\n");
    preOrderTraverse(T);
    printf("\n");

    changeLeftRight(T);

    printf("交换左右子树后，前序遍历二叉树：\n");
    preOrderTraverse(T);
    printf("\n");

    return 0;
}

/*在这个函数中，我们首先检查当前节点是否为空。
如果当前节点不为空，我们就交换它的左右子树，
然后递归地对左右子树执行相同的操作。这样，我们就可以确保二叉树的每一个节点的左右子树都被交换了。
*/