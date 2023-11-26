#include <stdio.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

}TNode,*TreeNode;

// 先序遍历，并用动态数组res，输出了每个节点的val。数组长度为ressize
int* preorderTraversal(struct TreeNode* root, int* returnSize) 
//!第一个函数，创建了个动态数组，用来存放每一个节点的val
{
    int* res = malloc(sizeof(int) * 500);
    *returnSize = 0; 
    preorder(root, res, returnSize);
    return res;
}
//! 然后才是先序遍历的代码
void preorder(struct TreeNode* root, int *res, int* resSize) {
    if (root == NULL) {
        return;
    }

    res[(*resSize)++] = root->val;  // 先访问根节点 
    //!把结点的值存放到动态数组res中位置为resSize的位置，一开始resSize是0
    preorder(root->left, res, resSize);  // 然后遍历左子树
    preorder(root->right, res, resSize);  // 最后遍历右子树
}
/*//!在这段代码中，ressize 和 returnSize 都是用来记录结果数组 res 的大小的。他们的主要区别在于他们在函数中的使用方式。

ressize 是在 postorder 函数中使用的，它是一个指向整数的指针，
用于在函数中跟踪 res 数组的当前大小。
每当向 res 数组中添加一个元素时，ressize 就会增加。

returnSize 是在 postorderTraversal 函数中使用的，它是一个指向整数的指针的指针。
这是因为我们希望在函数执行完毕后，能够知道 res 数组的最终大小。
由于 C 语言中函数参数是通过值传递的，
所以我们需要传递一个指针的指针，以便我们可以修改指针指向的值。

总的来说，ressize 和 returnSize 都是用来跟踪 res 数组大小的，
但是 returnSize 是为了能够在函数外部知道 res 的大小，
而 ressize 是为了在函数内部跟踪 res 的大小。
在函数执行完毕后，*returnSize 和 *ressize 应该是相同的。*/
