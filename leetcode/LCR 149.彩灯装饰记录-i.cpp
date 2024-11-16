/*
 * @lc app=leetcode.cn id=LCR 149 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 149] 彩灯装饰记录 I
 *
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/description/
 *
 * algorithms
 * Medium (63.01%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    303.5K
 * Total Submissions: 481.7K
 * Testcase Example:  '[8,17,21,18,null,null,6]'
 *
 * 一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照从 左 到 右 的顺序返回每一层彩灯编号。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [8,17,21,18,null,null,6]
 * 输出：[8,17,21,18,6]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 节点总数 <= 1000
 *
 *
 *
 *
 */
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> decorateRecord(TreeNode *root) {
        if (!root) return {};

        vector<int> res;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            res.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [8,17,21,18,null,null,6]\n
// @lcpr case=end

 */
