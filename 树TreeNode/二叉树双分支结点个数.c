#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// 创建新节点
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// 计算二叉树中双分支节点的个数
int doubleBranchCount(Node* node) {
    if (node == NULL)
        return 0; // 如果节点为空，返回0
    if (node->left != NULL && node->right != NULL)
        return doubleBranchCount(node->left) + doubleBranchCount(node->right) + 1; // 如果节点有两个孩子，返回左子树和右子树的双分支节点个数之和，再加1
    else
        return doubleBranchCount(node->left) + doubleBranchCount(node->right); // 如果节点只有一个孩子或没有孩子，返回左子树和右子树的双分支节点个数之和
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("Number of double branch nodes = %d", doubleBranchCount(root));
    return 0;
}


//Node* newNode(int data): 这个函数用于创建新的节点。它接收一个整数作为参数，然后创建一个新的节点，将这个整数赋值给节点的数据域，然后返回这个新创建的节点的指针。
//int doubleBranchCount(Node* node): 这个函数用于计算二叉树中双分支节点的个数。它接收一个节点的指针作为参数，然后递归地计算这个节点的左子树和右子树中双分支节点的个数，然后根据这个节点是否是双分支节点来决定是否需要将计数器加一。
//if (node == NULL): 这个条件判断用于检查当前节点是否为空。如果当前节点为空，那么就返回0，因为空节点不是双分支节点。