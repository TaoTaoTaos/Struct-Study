// 题目要求：给定一个以二叉链表表示的二叉树，查找值为x的节点，并输出该节点的所有祖先。假设值为x的节点不多于一个。

// 思路：我们可以使用递归的方式来解决这个问题。首先，我们需要定义一个二叉树节点的结构体，然后创建一个函数来查找值为x的节点。如果找到了，我们就把它的所有祖先节点打印出来。

#include <stdio.h>

// 定义二叉树节点的结构体
struct TreeNode
{
    int val;                // 节点的值
    struct TreeNode *left;  // 左子节点
    struct TreeNode *right; // 右子节点
};

// 查找值为x的节点，并输出该节点的所有祖先
int findAncestors(struct TreeNode *root, int x)
{
    // 如果根节点为空，直接返回0
    if (root == NULL)
        return 0;

    // 如果找到了值为x的节点，返回1
    if (root->val == x)
        return 1;

    // 如果左子树或右子树中找到了值为x的节点，打印当前节点，并返回1
    if (findAncestors(root->left, x) || findAncestors(root->right, x))
    {
        printf("%d ", root->val);
        return 1;
    }

    // 如果左右子树都没有找到值为x的节点，返回0
    return 0;
}

int main()
{
    // 创建二叉树的节点
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n5 = {5, NULL, NULL};

    // 构建二叉树
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;

    // 调用findAncestors函数，查找值为4的节点，并输出其所有祖先
    findAncestors(&n1, 4);

    return 0;
}

// 总结：这个题目主要考察了二叉树的遍历和递归的知识点。我们需要遍历二叉树来查找值为x的节点，然后通过递归的方式来找到它的所有祖先节点。
// 关键注释：关键在于理解递归的工作原理。递归是一种解决问题的方法，它把一个问题分解为越来越小的子问题，直到问题的规模小到可以被很简单直接解决。通常为了达到分解问题的效果，递归过程中要引入一个调用自身的函数。在这个题目中，我们使用递归来遍历二叉树的所有节点，当我们找到值为x的节点时，我们就通过递归的方式返回并打印出它的所有祖先节点。
