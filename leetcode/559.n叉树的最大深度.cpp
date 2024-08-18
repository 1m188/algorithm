/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (68.21%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    16.8K
 * Total Submissions: 24.6K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]\r'
 *
 * 给定一个 N 叉树，找到其最大深度。
 * 
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 我们应返回其最大深度，3。
 * 
 * 说明:
 * 
 * 
 * 树的深度不会超过 1000。
 * 树的节点总不会超过 5000。
 * 
 */

#include "vector"
#include "algorithm"
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root)
        {
            if (root->children.size())
            {
                vector<int> depth;
                for (int i = 0; i < root->children.size(); i++)
                {
                    depth.push_back(maxDepth(root->children[i]));
                }
                return 1 + *max_element(depth.begin(), depth.end());
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
};
// @lc code=end
