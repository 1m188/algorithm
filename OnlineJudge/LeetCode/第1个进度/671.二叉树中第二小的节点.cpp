/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (45.36%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 17.8K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
 * 
 * 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * 输出: 5
 * 说明: 最小的值是 2 ，第二小的值是 5 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * 输出: -1
 * 说明: 最小的值是 2, 但是不存在第二小的值。
 * 
 * 
 */

#include "cstddef"
#include "queue"
#include "limits"
#include "vector"
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
    int minVal = -1;
    long long sec = LLONG_MAX;
    void findSec(TreeNode *root)
    {
        if (root)
        {
            if (root->val > minVal && root->val < sec)
            {
                sec = root->val;
            }
            else if (root->left)
            {
                findSec(root->left);
                findSec(root->right);
            }
        }
    }

    vector<int> vec;
    void preFind(TreeNode *root)
    {
        if (root)
        {
            vec.push_back(root->val);
            preFind(root->left);
            preFind(root->right);
        }
    }

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        // 保存最小值，之后判断第二小的值，递归遍历，只要有一个比最小值大的值即可，因为每个节点都大于等于它的父节点
        // AC
        // if (root)
        // {
        //     minVal = root->val;
        //     findSec(root->left);
        //     findSec(root->right);
        //     return sec == LLONG_MAX ? -1 : sec;
        // }
        // else
        // {
        //     return -1;
        // }

        // 层序遍历树，保存最小值之后判断比最小值大比第二小的值小的值
        // AC
        // if (root)
        // {
        //     queue<TreeNode *> q;
        //     q.push(root);
        //     int min = root->val;
        //     long long sec = LLONG_MAX;
        //     while (!q.empty())
        //     {
        //         int num = q.size();
        //         for (int i = 0; i < num; i++)
        //         {
        //             TreeNode *tmp = q.front();
        //             q.pop();
        //             if (tmp->val > min && tmp->val < sec)
        //             {
        //                 sec = tmp->val;
        //             }
        //             if (tmp->left)
        //             {
        //                 q.push(tmp->left);
        //                 q.push(tmp->right);
        //             }
        //         }
        //     }
        //     return sec == LLONG_MAX ? -1 : sec;
        // }
        // else
        // {
        //     return -1;
        // }

        // 暴力先序遍历保存所有的节点值然后排序求第二小的值
        // AC
        preFind(root);
        sort(vec.begin(), vec.end());
        for (const int &n : vec)
        {
            if (n != vec[0])
            {
                return n;
            }
        }
        return -1;
    }
};
// @lc code=end
