/*
题目要求：
二叉树用二叉链表结构进行存储。请编写算法求二叉树根节点左右子树相隔最远的叶子节点之间距离。

思路：
1. 首先，我们需要找到左子树中距离根节点最远的叶子节点，这可以通过后序遍历实现。
2. 然后，我们需要找到右子树中距离根节点最远的叶子节点，这也可以通过后序遍历实现。
3. 最后，我们将这两个距离相加，就得到了左右子树相隔最远的叶子节点之间的距离。

代码如下：
*/

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新节点
TreeNode *createNode(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 后序遍历求最大深度
int postOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = postOrder(root->left);         // 左子树的最大深度
    int right = postOrder(root->right);       // 右子树的最大深度
    return (left > right ? left : right) + 1; // 返回左右子树中的最大深度+1
}

// 求二叉树根节点左右子树相隔最远的叶子节点之间距离
int maxDistance(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = postOrder(root->left);   // 左子树的最大深度
    int right = postOrder(root->right); // 右子树的最大深度
    return left + right;                // 返回左右子树的最大深度之和
}

int main()
{
    // 创建二叉树
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // 求二叉树根节点左右子树相隔最远的叶子节点之间距离
    int distance = maxDistance(root);
    printf("The maximum distance between two leaves is: %d\n", distance);

    return 0;
}

/*
总结：
本题主要考察了二叉树的后序遍历和深度的概念。通过后序遍历，我们可以求出二叉树的最大深度，然后通过左右子树的最大深度之和，我们就可以求出二叉树根节点左右子树相隔最远的叶子节点之间的距离。

关键注释：
1. "TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));" 这行代码是创建一个新的二叉树节点。我们使用malloc函数为新节点分配内存，并将输入的值赋给新节点的val字段。
2. "int left = postOrder(root->left);" 这行代码是通过后序遍历求出左子树的最大深度。
3. "int right = postOrder(root->right);" 这行代码是通过后序遍历求出右子树的最大深度。
4. "return (left > right ? left : right) + 1;" 这行代码是返回左右子树中的最大深度+1，这就是当前节点的最大深度。
5. "return left + right;" 这行代码是返回左右子树的最大深度之和，这就是二叉树根节点左右子树相隔最远的叶子节点之间的距离。
*/
