// 题目要求：构建一个线索二叉树
// 思路和算法原理：
// 线索二叉树是一种通过二叉链表以及指向前驱和后继的引用来表示二叉树的数据结构。
// 这种方法仅需要修改空的引用来增加对子树的访问性。
// 在二叉树中，有两个指针是空的（左子节点或右子节点），并且可以用来存储前驱或后继节点的引用。

#include <stdio.h>
#include <stdlib.h>

// 定义线索二叉树的结构体
typedef struct ThreadNode
{
    char data;                          // 数据域
    struct ThreadNode *lchild, *rchild; // 左右孩子指针
    int ltag, rtag;                     //! 左右标志
} ThreadNode, *ThreadTree;





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

//! 线索化，就是先创一个空指针，然后把树进行前序，中序或者后续遍历，当每次访问结点时，判断这个节点有没有空的位置，如果有，那么就存入他的前驱结点的位置（就是pre指向的位置）


ThreadNode *pre = NULL;//! pre指针，先指向空，他一直跟在 正在被访问那个的后面


void InThread(ThreadTree tree)
{
    if (tree)
    {
        InThread(tree->lchild); // 递归左孩子线索化


        if (!tree->lchild) // !如果该节点没有左孩子，设置ltag为1，并把lchild指向刚刚访问过的节点
        { 
            tree->ltag = 1;
            tree->lchild = pre;
        }
        if (pre && !pre->rchild)//! 如果前驱节点没有右孩子，设置rtag为1，并把rchild指向当前节点
        { 
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
        {                          //!处理遍历的最后一个节点
            pre->rtag = 1;
        }
    }
}

// 遍历线索二叉树
void InOrder(ThreadTree tree)
{
    while (tree)
    {
        while (tree->ltag == 0)
        { // 找到最开始的节点
            tree = tree->lchild;
        }

        printf("%c ", tree->data); // 访问该节点
        
        while (tree->rtag == 1 && tree->rchild != NULL)
        { // 如果右指针是线索，一直访问下去
            tree = tree->rchild;
            printf("%c ", tree->data);
        }
        tree = tree->rchild; // 访问右孩子
    }
}

int main()
{
    // 题目要求：构建一个线索二叉树
    // 思路和算法原理：
    // 线索二叉树是一种通过二叉链表以及指向前驱和后继的引用来表示二叉树的数据结构。
    // 这种方法仅需要修改空的引用来增加对子树的访问性。
    // 在二叉树中，有两个指针是空的（左子节点或右子节点），并且可以用来存储前驱或后继节点的引用。

    ThreadTree tree;
    CreateTree(&tree);    // 创建二叉树
    CreateInThread(tree); // 线索化二叉树
    InOrder(tree);        // 遍历线索二叉树
    return 0;
}

// 总结：
// 本题主要考察了线索二叉树的构建和遍历。
// 线索二叉树是一种改进的二叉树，它在二叉树的基础上增加了对子树的访问性。
// 通过修改空的引用来存储前驱或后继节点的引用，从而提高了遍历的效率。
// //!关键问题：如何理解线索二叉树？
// 线索二叉树是一种通过二叉链表以及指向前驱和后继的引用来表示二叉树的数据结构。
// 这种方法仅需要修改空的引用来增加对子树的访问性。
// 在二叉树中，有两个指针是空的（左子节点或右子节点），并且可以用来存储前驱或后继节点的引用。
// 这样，在遍历线索二叉树时，无需使用栈或者递归，只需按照线索访问即可。
