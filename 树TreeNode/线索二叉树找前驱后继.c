// 题目要求：在线索二叉树中找到一个节点的先序和后继
// 思路和算法原理：
// 在线索二叉树中，我们可以通过节点的线索找到它的先序和后继。
// 先序是指在中序遍历中，当前节点的前一个节点。后继是指在中序遍历中，当前节点的后一个节点。

#include <stdio.h>
#include <stdlib.h>

// 定义线索二叉树的结构体
typedef struct ThreadNode
{
    char data;                          // 数据域
    struct ThreadNode *lchild, *rchild; // 左右孩子指针
    int ltag, rtag;                     // 左右标志

} ThreadNode, *ThreadTree;

// 全局变量，始终指向刚刚访问过的结点
ThreadNode *pre = NULL;

// 创建二叉树的函数
void CreateTree(ThreadTree *tree)
{
    char data;
    scanf("%c", &data);
    if (data != '#')
    {
        *tree = (ThreadNode *)malloc(sizeof(ThreadNode));
        (*tree)->data = data;
        (*tree)->ltag = (*tree)->rtag = 0; // 初始化标志位
        CreateTree(&(*tree)->lchild);      // 创建左子树
        CreateTree(&(*tree)->rchild);      // 创建右子树
    }
    else
    {
        *tree = NULL;
    }
}

// 中序遍历线索化
void InThread(ThreadTree tree)
{
    if (tree)
    {
        InThread(tree->lchild); // 递归左孩子线索化
        if (!tree->lchild)
        { // 如果该节点没有左孩子，设置ltag为1，并把lchild指向刚刚访问过的节点
            tree->ltag = 1;
            tree->lchild = pre;
        }
        if (pre && !pre->rchild)
        { // 如果前驱节点没有右孩子，设置rtag为1，并把rchild指向当前节点
            pre->rtag = 1;
            pre->rchild = tree;
        }
        pre = tree;             // 保持pre指向刚刚访问过的节点
        InThread(tree->rchild); // 递归右孩子线索化
    }
}

// 建立线索二叉树
void CreateInThread(ThreadTree tree)
{
    pre = NULL;
    if (tree != NULL)
    {
        InThread(tree);
        if (pre->rchild == NULL)
        { // 处理遍历的最后一个节点
            pre->rtag = 1;
        }
    }
}

// 找到节点的先序和后继
// 找到节点的先序和后继
void FindPreAndNext(ThreadTree tree, char x)
{
    ThreadNode *pre = NULL, *next = NULL;
    ThreadNode *target = NULL; // 目标节点
    while (tree)
    {
        while (tree->ltag == 0)
        { // 找到最开始的节点
            tree = tree->lchild;
        }
        if (tree->data == x)
        { // 找到目标节点
            target = tree;
            if (tree->ltag == 1)
            { // 如果左指针是线索，那么它就是先序
                pre = tree->lchild;
            }
            if (tree->rtag == 1)
            { // 如果右指针是线索，那么它就是后继
                next = tree->rchild;
            }
        }
        while (tree->rtag == 1 && tree->rchild != NULL)
        { // 如果右指针是线索，一直访问下去
            tree = tree->rchild;
        }
        tree = tree->rchild; // 访问右孩子
    }
    if (!pre)
    { // 如果先序为空，遍历二叉树找到先序
        ThreadNode *temp = target;
        while (temp->ltag == 0)
        {
            temp = temp->lchild;
        }
        while (temp->rtag == 1 && temp->rchild != NULL)
        {
            temp = temp->rchild;
        }
        pre = temp->rchild;
    }
    if (!next)
    { // 如果后继为空，遍历二叉树找到后继
        ThreadNode *temp = target;
        while (temp->rtag == 0)
        {
            temp = temp->rchild;
        }
        next = temp;
    }
    if (pre)
    {
        printf("The pre of %c is %c\n", x, pre->data);
    }
    else
    {
        printf("The pre of %c is NULL\n", x);
    }
    if (next)
    {
        printf("The next of %c is %c\n", x, next->data);
    }
    else
    {
        printf("The next of %c is NULL\n", x);
    }
}

int main()
{
    // 题目要求：在线索二叉树中找到一个节点的先序和后继
    // 思路和算法原理：
    // 在线索二叉树中，我们可以通过节点的线索找到它的先序和后继。
    // 先序是指在中序遍历中，当前节点的前一个节点。后继是指在中序遍历中，当前节点的后一个节点。

    ThreadTree tree;
    CreateTree(&tree);         // 创建二叉树
    CreateInThread(tree);      // 线索化二叉树
    FindPreAndNext(tree, 'D'); // 找到节点D的先序和后继
    return 0;
}

// 总结：
// 本题主要考察了线索二叉树的构建和遍历，以及如何在线索二叉树中找到一个节点的先序和后继。
// 线索二叉树是一种改进的二叉树，它在二叉树的基础上增加了对子树的访问性。
// 通过修改空的引用来存储前驱或后继节点的引用，从而提高了遍历的效率。
// //!关键问题：如何在线索二叉树中找到一个节点的先序和后继？
// 在线索二叉树中，我们可以通过节点的线索找到它的先序和后继。
// 先序是指在中序遍历中，当前节点的前一个节点。后继是指在中序遍历中，当前节点的后一个节点。
// 如果节点的左指针是线索，那么它就是先序；如果节点的右指针是线索，那么它就是后继。
