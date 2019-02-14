/*
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

/*
平衡二叉搜索树（Self-balancing binary search tree）又被称为AVL树（有别于AVL算法），且具有以下性质：
它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
*/

//递归求解树的深度，如果深度不符合要求则直接返回-1，代表不是，否则继续按照规则判断，最后如果返回不是-1，那么说明是

#include "algorithm"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(NULL), right(NULL) {}
};

class Solution
{
  private:
    int getLength(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            int left = getLength(root->left);
            if (left == -1)
            {
                return -1;
            }
            int right = getLength(root->right);
            {
                if (right == -1)
                {
                    return -1;
                }
            }
            return abs(left - right) <= 1 ? 1 + std::max(left, right) : -1;
        }
    }

  public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        return getLength(pRoot) != -1;
    }
};