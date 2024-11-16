/*
 * @lc app=leetcode.cn id=LCR 151 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 151] 彩灯装饰记录 III
 *
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/description/
 *
 * algorithms
 * Medium (58.19%)
 * Likes:    315
 * Dislikes: 0
 * Total Accepted:    276.6K
 * Total Submissions: 475.4K
 * Testcase Example:  '[8,17,21,18,null,null,6]'
 *
 * 一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照如下规则记录彩灯装饰结果：
 *
 *
 * 第一层按照从左到右的顺序记录
 * 除第一层外每一层的记录顺序均与上一层相反。即第一层为从左到右，第二层为从右到左。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [8,17,21,18,null,null,6]
 * 输出：[[8],[21,17],[18,6]]
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
#include <algorithm>
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
    vector<vector<int>> decorateRecord(TreeNode *root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> vec;
            queue<TreeNode *> que1;
            while (!que.empty()) {
                TreeNode *node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que1.push(node->left);
                if (node->right) que1.push(node->right);
            }
            que = que1;
            res.push_back(vec);
        }

        for (int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
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
