/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

//自己一开始没什么思路，后来看了别人的方法才知道大概这么做，主要是递归同时判断左右子树的情况，附上别人的思路：
/*思路：首先根节点以及其左右子树，左子树的左子树和右子树的右子树相同
* 左子树的右子树和右子树的左子树相同即可，采用递归
* 非递归也可，采用栈或队列存取各级子树根节点
*/

#include "cstddef"

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
  private:
    bool judge(TreeNode *left, TreeNode *right)
    {
        if (!left)
        {
            return !right;
        }
        else if (!right)
        {
            return false;
        }
        else if (left->val != right->val)
        {
            return false;
        }
        else
        {
            return judge(left->left, right->right) && judge(left->right, right->left);
        }
    }

  public:
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (!pRoot)
        {
            return true;
        }
        else
        {
            return judge(pRoot->left, pRoot->right);
        }
    }
};