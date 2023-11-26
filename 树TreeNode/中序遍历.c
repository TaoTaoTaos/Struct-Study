#include <stdio.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

}TNode,*TreeNode;

// 中序遍历，并用动态数组res，输出了每个节点的val。
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int) * 500);
    *returnSize = 0; 
    inorder(root, res, returnSize);
    return res;
}

void inorder(struct TreeNode* root, int *res, int* resSize) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, res, resSize);  // 先遍历左子树
    res[(*resSize)++] = root->val;  // 然后访问根节点
    inorder(root->right, res, resSize);  // 最后遍历右子树
}