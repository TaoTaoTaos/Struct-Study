// 题目要求：实现排序二叉树

// 思路和算法原理：
// 排序二叉树是一种特殊的二叉树，它的左子树的所有节点的值都小于根节点的值，右子树的所有节点的值都大于根节点的值。
// 我们可以通过递归的方式来实现排序二叉树的插入和查找操作。

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点
typedef struct Node {
    int data; // 节点数据
    struct Node* left; // 左子树
    struct Node* right; // 右子树
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 分配内存
    newNode->data = data; // 设置数据
    newNode->left = newNode->right = NULL; // 初始化左右子树
    return newNode;
}

// 插入节点
Node* insertNode(Node* root, int data) {
    // 如果树为空，创建新节点
    if (root == NULL) {
        root = createNode(data);
    }
    // 如果插入的数据小于根节点，插入到左子树
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    // 如果插入的数据大于根节点，插入到右子树
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// 主函数
int main() {
    Node* root = NULL; // 创建空树
    // 插入数据
    root = insertNode(root, 8); // 插入8
    root = insertNode(root, 3); // 插入3
    root = insertNode(root, 10); // 插入10
    root = insertNode(root, 1); // 插入1
    root = insertNode(root, 6); // 插入6
    root = insertNode(root, 14); // 插入14
    root = insertNode(root, 4); // 插入4
    root = insertNode(root, 7); // 插入7
    root = insertNode(root, 13); // 插入13
    return 0;
}

// 题目所考察的知识点：
// 1. 二叉树的基本概念和操作
// 2. 动态内存分配
// 3. 递归的使用

// 关键问题：
//! 1. 如何插入节点：我们通过比较插入的数据和根节点的数据来决定插入的位置。如果插入的数据小于根节点，我们就将数据插入到左子树，否则插入到右子树。我们使用递归的方式来实现这个过程。
//! 2. 如何创建节点：我们使用malloc函数来为新节点分配内存，然后设置节点的数据和左右子树。
