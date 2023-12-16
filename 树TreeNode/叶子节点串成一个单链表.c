// 题目要求：把二叉树的叶子节点从左到右建立一个单链表。

// 思路：我们可以使用深度优先搜索（DFS）的方法，从根节点开始，递归地处理每个节点。对于每个节点，如果它是一个叶子节点，我们就把它添加到链表的末尾。

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的节点
typedef struct TreeNode
{
    int val;                // 节点的值
    struct TreeNode *left;  // 左子树
    struct TreeNode *right; // 右子树
} TreeNode;

// 定义链表的节点
typedef struct ListNode
{
    int val;               // 节点的值
    struct ListNode *next; // 下一个节点
} ListNode;

// 创建一个新的二叉树节点
TreeNode *newTreeNode(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode)); // 分配内存
    node->val = val;                                       // 设置节点的值
    node->left = NULL;                                     // 初始化左子树
    node->right = NULL;                                    // 初始化右子树
    return node;                                           // 返回新创建的节点
}

// 创建一个新的链表节点
ListNode *newListNode(int val)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // 分配内存
    node->val = val;                                       // 设置节点的值
    node->next = NULL;                                     // 初始化下一个节点
    return node;                                           // 返回新创建的节点
}

// 把二叉树的叶子节点从左到右添加到链表中
ListNode *addLeavesToList(TreeNode *root)
{
    static ListNode *head = NULL; // 初始化链表的头节点
    static ListNode *tail = NULL; // 初始化链表的尾节点

    if (root != NULL)
    { // 如果节点不为空
        if (root->left == NULL && root->right == NULL)
        {                                            // 如果节点是叶子节点
            ListNode *node = newListNode(root->val); // 创建一个新的链表节点
            if (head == NULL)
            {                // 如果链表为空
                head = node; // 设置头节点
                tail = node; // 设置尾节点
            }
            else
            {                      // 如果链表不为空
                tail->next = node; // 把新节点添加到链表的末尾
                tail = node;       // 更新尾节点
            }
        }
        else
        {                                 // 如果节点不是叶子节点
            addLeavesToList(root->left);  // 递归处理左子树
            addLeavesToList(root->right); // 递归处理右子树
        }
    }

    return head; // 返回链表的头节点
}

// 打印链表
void printList(ListNode *head)
{
    ListNode *node = head; // 初始化当前节点
    while (node != NULL)
    {                             // 当当前节点不为空时
        printf("%d ", node->val); // 输出当前节点的值
        node = node->next;        // 移动到下一个节点
    }
    printf("\n");
}

int main()
{
    // 创建一个二叉树
    TreeNode *root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    root->right->left = newTreeNode(6);
    root->right->right = newTreeNode(7);

    // 把二叉树的叶子节点从左到右添加到链表中
    ListNode *head = NULL; // 初始化链表的头节点
    ListNode *tail = NULL; // 初始化链表的尾节点
    addLeavesToList(root);

    // 打印链表
    printList(head);

    return 0;
}

// 总结：本题主要考察了二叉树的遍历和链表的操作。通过深度优先搜索，我们可以按照特定的顺序访问二叉树的每个节点，从而实现从二叉树到链表的转换。在这个过程中，链表的操作是关键，它可以帮助我们把二叉树的叶子节点添加到链表中。
// //!关键注释：在这个问题中，关键的部分是如何把二叉树的叶子节点添加到链表中。我们需要在遍历二叉树的过程中，对每个叶子节点创建一个新的链表节点，然后把它添加到链表的末尾。这一点是通过在递归函数中添加对叶子节点的判断和处理来实现的。
