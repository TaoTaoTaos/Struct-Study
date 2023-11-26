#include <stdio.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

}TNode,*TreeNode;

//后序遍历，并用动态数组res，输出了每个节点的val。
int* postorderTraversal(struct TreeNode* root, int*returnSize) {
int*res = malloc(sizeof (int)*500);
*returnSize=0 ; 
postorder(root,res,returnSize);
return res;
}



void postorder (struct TreeNode*root ,int *res,int*ressize){
if (root==NULL){
return ;
}

else
postorder(root->left,res,ressize);
postorder(root->right,res,ressize);
res[(*ressize)++]=root->val;
}
/*在这段代码中，ressize 和 returnSize 都是用来记录结果数组 res 的大小的。
他们的主要区别在于他们在函数中的使用方式。

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


