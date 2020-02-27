/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (43.78%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 20.7K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
 * 
 */

#include "cstddef"
#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    unordered_map<int, int> um;

    void recordMode(TreeNode *root)
    {
        if (root)
        {
            if (um.find(root->val) == um.end())
            {
                um[root->val] = 1;
            }
            else
            {
                um[root->val]++;
            }
            recordMode(root->left);
            recordMode(root->right);
        }
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        if (!root)
        {
            return vector<int>();
        }

        recordMode(root);
        vector<std::pair<int, int>> vec(um.begin(), um.end());
        sort(vec.begin(), vec.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) { return p1.second > p2.second; });
        vector<int> res{vec[0].first};
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i].second == vec[0].second)
            {
                res.push_back(vec[i].first);
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
