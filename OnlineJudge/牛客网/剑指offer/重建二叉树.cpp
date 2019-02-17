/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

//根据前序遍历和中序遍历的特点，递归求解

#include "vector"

using namespace std;

//Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  private:
    TreeNode *reConstructBinaryTree(const vector<int> &pre, const vector<int> &vin, int preStart, int preEnd, int vinStart, int vinEnd)
    {
        if (preStart <= preEnd && vinStart <= vinEnd)
        {
            TreeNode *root = new TreeNode(pre[preStart]);
            for (int i = vinStart; i < vin.size(); i++)
            {
                if (vin[i] == pre[preStart])
                {
                    root->left = reConstructBinaryTree(pre, vin, preStart + 1, preStart + i - vinStart, vinStart, i - 1);
                    root->right = reConstructBinaryTree(pre, vin, preStart + i - vinStart + 1, preEnd, i + 1, vinEnd);
                    break;
                }
            }
            return root;
        }
        else
        {
            return NULL;
        }
    }

  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        return reConstructBinaryTree(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
};