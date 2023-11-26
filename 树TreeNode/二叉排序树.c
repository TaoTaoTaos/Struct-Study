#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct Node
{
    int data;           // 节点数据
    struct Node *left;  // 左子节点
    struct Node *right; // 右子节点
};

// 创建新节点的函数
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // 为新节点分配内存
    newNode->data = data;                                              // 设置节点数据
    newNode->left = newNode->right = NULL;                             // 初始化左右子节点为NULL
    return newNode;                                                    // 返回新节点
}

// 插入节点的函数
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    { // 如果树是空的，就创建一个新节点
        root = createNode(data);
    }
    else if (data <= root->data)
    { // 如果数据小于等于根节点，插入到左子树
        root->left = insert(root->left, data);
    }
    else
    { // 否则，插入到右子树
        root->right = insert(root->right, data);
    }
    return root; // 返回根节点
}

// 查找节点的函数
int search(struct Node *root, int data)
{
    if (root == NULL)
    { // 如果树是空的，返回0
        return 0;
    }
    else if (root->data == data)
    { // 如果找到数据，返回1
        return 1;
    }
    else if (data <= root->data)
    { // 如果数据小于根节点，搜索左子树
        return search(root->left, data);
    }
    else
    { // 否则，搜索右子树
        return search(root->right, data);
    }
}

// 查找最小节点的函数
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

//! 删除节点的函数
struct Node *delete(struct Node *root, int data) // 定义一个函数，输入是一个二叉搜索树的根节点和一个整数，输出是一个节点指针
{
    if (root == NULL) // 如果根节点为空
        return root; // 直接返回根节点
    else if (data < root->data) // 如果要删除的数据小于根节点的数据
        root->left = delete (root->left, data); // 在左子树中递归删除
    else if (data > root->data) // 如果要删除的数据大于根节点的数据
        root->right = delete (root->right, data); // 在右子树中递归删除
    else // 如果要删除的数据等于根节点的数据
    {
        if (root->left == NULL) //! 如果左子树为空,说明只有右子树了，那么让右子树来替代它就好
        {
            struct Node *temp = root->right; // 保存右子树
            free(root); // 删除根节点
            return temp; // 返回右子树
        }
        else if (root->right == NULL) // //! 如果右子树为空,说明只有左子树了，那么让左子树来替代它就好
        {
            struct Node *temp = root->left; // 保存左子树
            free(root); // 删除根节点
            return temp; // 返回左子树
        }
         //! 如果左右子树都不为空，那么找到右子树中的最小节点
         //! 找最小节点，就是进行中序遍历：中序遍历就可得到一个递增的数列
        struct Node *temp = findMin(root->right); // 找到右子树中的最小节点
        root->data = temp->data; // 用最小节点的数据替换根节点的数据
        root->right = delete (root->right, temp->data); // 在右子树中删除最小节点
    }
    return root; // 返回根节点
}

// 打印二叉树的函数
void printTree(struct Node *root, int space)
{
    if (root == NULL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}

int main()
{
    struct Node *root = NULL; // 创建一个空树
    int num, i, data;

    printf("请输入要插入的节点数量：");
    scanf("%d", &num);

    printf("请输入要插入的节点数据：");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &data);
        root = insert(root, data); // 插入数据
        printf("插入数据后的二叉树：\n");
        printTree(root, 0); // 打印二叉树
    }

    printf("请输入要查找的数字：");
    scanf("%d", &data);
    if (search(root, data))
        printf("找到了\n");
    else
        printf("没找到\n");

    printf("请输入要删除的数字：");
    scanf("%d", &data);
    root = delete (root, data);
    printf("删除数据后的二叉树：\n");
    printTree(root, 0); // 打印二叉树

    if (search(root, data))
        printf("删除失败\n");
    else
        printf("删除成功\n");

    return 0;
}
