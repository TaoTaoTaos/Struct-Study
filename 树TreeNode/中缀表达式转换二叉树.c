// 题目要求：设计一个算法，将给定的表达式树(二叉树)转换为等价的中缀表达式(通过括号反映操作符的计算次序)并输出。

// 思路：我们可以使用中序遍历的方法，从根节点开始，递归地处理每个节点。对于每个节点，如果它是一个叶子节点，我们直接输出它的值。如果它是一个非叶子节点，我们在它的左子树和右子树的表达式外面加上括号，然后再输出它的操作符。

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的节点
typedef struct Node
{
    char val;           // 节点的值，可以是数字或者操作符
    struct Node *left;  // 左子树
    struct Node *right; // 右子树
} Node;

// 创建一个新的节点
Node *newNode(char val)
{
    Node *node = (Node *)malloc(sizeof(Node)); // 分配内存
    node->val = val;                           // 设置节点的值
    node->left = NULL;                         // 初始化左子树
    node->right = NULL;                        // 初始化右子树
    return node;                               // 返回新创建的节点
}

// 将表达式树转换为中缀表达式
void toInfix(Node *root)
{
    if (root != NULL)
    { // 如果节点不为空
        if (root->left != NULL)
        {                        // 如果有左子树
            printf("(");         // 输出左括号        左
            toInfix(root->left); // 递归处理左子树
        }


        printf("%c", root->val); // 输出节点的值          根


        if (root->right != NULL)
        {                         // 如果有右子树
            toInfix(root->right); // 递归处理右子树    右
            printf(")");          // 输出右括号
        }
    }
}

int main()
{
    // 创建一个表达式树
    Node *root = newNode('*');
    root->left = newNode('+');
    root->right = newNode('-');
    root->left->left = newNode('a');
    root->left->right = newNode('b');
    root->right->left = newNode('c');
    root->right->right = newNode('d');

    // 将表达式树转换为中缀表达式并输出
    toInfix(root);
    printf("\n");

    return 0;
}

// 总结：本题主要考察了二叉树的中序遍历和递归的使用。通过中序遍历，我们可以按照特定的顺序访问二叉树的每个节点，从而实现从表达式树到中缀表达式的转换。在这个过程中，递归的使用是关键，它可以简化代码的复杂性，使问题的解决变得更加直观和清晰。
//!关键注释：在这个问题中，关键的部分是如何正确地在中缀表达式中添加括号。我们需要在每个非叶子节点的左子树和右子树的表达式外面加上括号，以反映操作符的计算次序。这一点是通过在递归函数中添加对左子树和右子树的判断和处理来实现的。
