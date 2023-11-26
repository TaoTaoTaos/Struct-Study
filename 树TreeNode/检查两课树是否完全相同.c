#include <stdio.h>
#include <stdbool.h>   //! 用 bool函数 要调用 stdbool 头文件
typedef struct  TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

}Tnode,*TreeNode;

//!  这个bool函数使用先序遍历的思想，但是不用写 preorder
bool IsSame(TreeNode p, TreeNode q) //!  p 、q 是要比较的两棵树的根
{

if(p == NULL && q == NULL)//如果根都空，那么一定一样
return true;
else if (p == NULL || q == NULL) // 如果根不空，但有一个人是空的，那他两肯定不一样
return false;
else if (p->val!= q->val) // 如果根值不一样，那么一定不一样
return false;

//! 这三种情况，判断了p 、q 两树的根值 ，如果都判断完了，还没跳出，那么开始递归，判断左右子树吧

return IsSame(p->left,q->left) && IsSame(p->right,q->right); 
//!  递归调用，判p 、q 两树的左右子树是否一样

}


void main()
{

return 0;


}