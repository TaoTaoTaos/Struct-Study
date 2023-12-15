// 题目要求：设计一个算法计算一棵给定二叉树的深度。
// 思路：使用递归的方式，比较左右子树的深度，取较大值，然后加1。
#include <stdio.h>
// 二叉树的存储表示
typedef struct BiTNode{
    int data; // 数据域
    struct BiTNode *lchild, *rchild; // 左右孩子指针
}BiTNode, *BiTree;

// 计算二叉树的深度
int Depth(BiTree T) {
    // 如果二叉树为空，深度为0
    if (T == NULL) return 0;
    else {
        // 计算左子树的深度
        int left = Depth(T->lchild);
        // 计算右子树的深度
        int right = Depth(T->rchild);
        // 返回左右子树深度较大的值并加1
        return (left > right ? left : right) + 1;
    }
}

int main() {
    // 创建二叉树并计算其深度的代码在此处省略
    return 0;
}

//! 关键注释：本题主要考察了二叉树的深度的计算，关键在于理解递归的思想。递归的终止条件是二叉树为空，此时深度为0。如果二叉树不为空，那么其深度就是左右子树深度的较大值加1。这里使用了递归函数Depth，它首先计算左子树的深度，然后计算右子树的深度，最后返回较大值加1。
